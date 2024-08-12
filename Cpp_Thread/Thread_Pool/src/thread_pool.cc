#include "thread_pool.h"

namespace my_thread_pool {

ThreadPool::ThreadPool(int minThreads, int maxThreads)
    : minThreads_(minThreads),
      maxThreads_(maxThreads),
      trigger_(true),
      idleThreads_(minThreads),
      curThreads_(minThreads) {
  std::cout << "maxThreads: " << maxThreads_ << std::endl;
  // 创建管理者线程，创建时需要指定任务函数
  manager_ = new std::thread(&ThreadPool::manager, this);
  // 创建工作的线程，创建时需要指定任务函数
  for (int i = 0; i < minThreads; ++i) {
    // *****以下是vector容器存储线程*****
    /*
        push_back会拷贝t对象，效率低
        std::thread t(&ThreadPool::worker, this);
        workers_.push_back(t);
    */

    // emplace_back()需要在添加过程中去构造对象才能避免拷贝和移动
    // 也就是需要在函数的括号中去构造要添加的对象
    // 需要将()中添加的对象变成临时对象
    // 这里在容器内部直接构造了匿名对象
    // 当把匿名对象从容器中弹出或容器销毁时，匿名对象销毁
    // workers_.emplace_back(std::thread(&ThreadPool::worker, this));

    // *****以下是map容器存储线程*****
    // t为临时对象
    // 注意：线程对象不允许拷贝,thread(const thread&) = delete;
    std::thread t(&ThreadPool::worker, this);
    workers_.insert(std::make_pair(t.get_id(), std::move(t)));
  }
}

ThreadPool::~ThreadPool() {
  trigger_ = false;
  // 唤醒所有阻塞的线程
  conditon_.notify_all();
  // 通过引用的方式遍历线程池中所有线程
  // 不能auto it : workers_
  // 因为线程对象不允许拷贝
  for (auto& it : workers_) {
    std::thread& t = it.second;
    // 判断当前线程是否可连接
    if (t.joinable()) {
      // 阻塞当前线程，等待子线程t执行完毕？(等待子线程退出任务函数)
      std::cout << "*****线程: " << t.get_id() << " 已退出*****" << std::endl;
      t.join();
    }
    // 以上只是退出线程的任务函数
    // 析构workers_中的具体线程会自动在析构ThreadPool对象时完成
  }

  // 对管理者线程同样进行以上操作
  if (manager_->joinable()) {
    manager_->join();
  }
  delete manager_;
}

// addTask()为生产者线程调用的函数，用来向任务队列中添加任务
void ThreadPool::addTask(std::function<void(void)> task) {
  {
    // 【unique_lock】和【lock_guard】为模板类，【管理互斥锁】，管理目的是避免死锁
    // 创建一个lock_guard对象，传入一个互斥锁的实例
    // 这个lock_guard类型的locker是局部变量(互斥锁管理对象)
    // 当locker对象构造完成时，会对互斥锁queue_mutex_加锁(前提是互斥锁queue_mutex_打开状态)，
    // 如果queue_mutex_是锁定的，线程在调用此函数时会阻塞在互斥锁上
    // 如果queue_mutex_是未锁定的，线程在调用此函数时会成功对互斥锁queue_mutex_加锁
    std::lock_guard<std::mutex> locker(queue_mutex_);

    // 这里使用emplace()和push()效率一样
    // 因为task已经被创建了，不是临时对象
    // tasks_为<queue>,emplace()添加至队尾
    tasks_.emplace(task);
  }  // 添加作用域，执行到此处，locker对象被析构，queue_mutex_会自动解锁

  // 添加一个任务后，需要唤醒阻塞在条件变量conditon_上的工作线程
  // 这里notify_one()只会唤醒一个线程
  // 这里notify_all()会唤醒所有线程
  // 这行代码不需要锁
  // conditon_.notify_one();
  conditon_.notify_all();
};

void ThreadPool::manager() {
  while (trigger_.load()) {
    // 休眠3秒，检测线程池线程数量
    std::this_thread::sleep_for(std::chrono::seconds(1));
    int idle = idleThreads_.load();
    int cur = curThreads_.load();
    // 线程销毁(两个阶段)
    // 1. 唤醒阻塞在条件变量conditon_上的工作线程
    // 2. 销毁被唤醒的线程对象
    // 空闲线程数量大于当前线程数量的一半，且当前线程数量大于最小线程数量
    if (idle > cur / 2 && cur > minThreads_) {
      // 每次销毁两个线程
      // 记录销毁的线程数量
      exitThreads_.store(2);
      // 唤醒所有阻塞在条件变量conditon_上的工作线程
      conditon_.notify_all();

      // 这里加一把互斥锁ids_mutex_，因为workers_ids_在manager线程和worker线程中都会被访问
      std::lock_guard<std::mutex> ids_locker(ids_mutex_);
      // 2. 销毁被唤醒的线程对象
      for (auto id : workers_ids_) {
        auto it = workers_.find(id);
        if (it != workers_.end()) {
          // it为map容器的迭代器，*it为map容器的对组元素
          // .second为线程对象
          // 调用线程对象的join()方法，阻塞当前的manage线程，等待线程对象(*it)里面的任务执行完成
          // 这里其实不会阻塞很长时间，因为(*it)的任务函数已经退出
          // 但是必须调用join()方法释放(*it)线程占用的系统资源
          std::cout << "=====线程 " << it->first << " 已销毁=====" << std::endl;
          (*it).second.join();
          workers_.erase(it);
        }
      }
      // 清空存储已经退出任务函数的线程id的vector容器
      workers_ids_.clear();

    }
    // 线程增加: 空闲线程数量为零，且当前线程数量小于最大线程数量
    else if (idle == 0 && cur < maxThreads_) {
      // 原本vector容器存储线程
      // workers_.emplace_back(std::thread(&ThreadPool::worker, this));
      // 现在map容器存储线程
      std::thread t(&ThreadPool::worker, this);
      workers_.insert(std::make_pair(t.get_id(), std::move(t)));

      curThreads_++;
      idleThreads_++;
    }
  }
}

void ThreadPool::worker() {
  // 判断线程池是否开启
  // trigger_为原子变量，可以直接访问或调用load()方法
  while (trigger_.load()) {
    std::function<void(void)> task = nullptr;
    // 任务队列为线程池的共享资源，需要互斥锁
    // 【unique_lock】和【lock_guard】为模板类，【管理互斥锁】，管理目的是避免死锁
    std::unique_lock<std::mutex> locker(queue_mutex_);
    {
      // 有了锁之后需要取任务，需要判断任务队列是否为空
      // 这里用while循环，当线程解除阻塞时，也需要判断任务队列是否为空
      while (tasks_.empty() && trigger_) {
        // 如果任务队列为空，需要将当前线程阻塞在条件变量conditon_上
        // ***调用wait()方法之后，locker对象管理的这个互斥锁自动解锁***
        // ***这是为了避免死锁,因为wait()方法会阻塞当前线程***
        conditon_.wait(locker);
        // 上一行执行完表示线程被唤醒,不再阻塞在条件变量conditon_上
        // 1. 唤醒阻塞在条件变量conditon_上的工作线程
        if (exitThreads_.load() > 0) {
          curThreads_--;
          idleThreads_--;
          exitThreads_--;
          std::cout << "-----线程退出, ID: " << std::this_thread::get_id()
                    << " -----" << std::endl;

          // 某个线程退出后，将对应id存储在 workers_ids_ 中,
          // 然后再在管理者线程中删除对应id的线程对象
          // 这里使用emplace_back()和push_back()效率一样

          // 这里加一把互斥锁ids_mutex_，因为workers_ids_在manager线程和worker线程中都会被访问
          std::lock_guard<std::mutex> ids_locker(ids_mutex_);
          workers_ids_.emplace_back(std::this_thread::get_id());
          return;  // return为退出线程的工作函数，ids_locker在此处析构，ids_mutex_也会自动解锁
        }
      }
      // 跳出以上while循环，说明任务队列不为空，需要取任务
      if (!tasks_.empty()) {
        std::cout << "取出了一个任务..." << std::endl;
        // task = tasks_.front(); 会拷贝队头元素，效率低
        // std::move()方法进行资源转移，tasks_.front()为匿名对象
        // 把匿名对象的资源转移到另一个对象中
        task = std::move(tasks_.front());
        tasks_.pop();
      }
    }  // 添加作用域，执行到此处，locker对象被析构，queue_mutex_会自动解锁

    // 如果task不是空对象，则执行任务
    // task为可调用对象
    if (task) {
      // 取出任务后，空闲线程数量减1，idleThreads_为原子变量，--线程安全
      idleThreads_--;
      task();
      idleThreads_++;
    }
  }
}

};  // namespace my_thread_pool
