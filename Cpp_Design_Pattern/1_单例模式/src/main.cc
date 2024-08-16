#include <atomic>
#include <iostream>
#include <mutex>

#if 0
/**
 * @brief 定义一个单例模式的任务队列
 * @brief 饿汉模式：定义类的时候已经创建单例对象
 * 
 * @note 在多线程的场景下，饿汉模式没有线程安全问题(多线程可以同时访问这个单例对象)
 */
class TaskQueue {
 public:
  // 删除所有构造函数，该类只能在内部初始化
  //   TaskQueue() = delete;
  TaskQueue(const TaskQueue& t) = delete;
  TaskQueue& operator=(const TaskQueue& t) = delete;  // 显式删除拷贝赋值函数

  static TaskQueue* GetInstance() { return taskQ_; }

  void print() { std::cout << "单例对象的print函数..." << std::endl; }

 private:
  // 将构造函数私有化，防止创建对象
  TaskQueue() {}
  // TaskQueue(const TaskQueue& t) {}
  // TaskQueue& operator=(const TaskQueue& t) {};

  // 或者加上 =default，使用这两个构造函数的默认实现
  // TaskQueue() = default;
  // TaskQueue(const TaskQueue& t) = default;
  // TaskQueue& operator=(const TaskQueue& t) = default;

  // 只能通过类名访问静态属性或方法(静态成员变量，类内声明，类外初始化)
  static TaskQueue* taskQ_;
};
// 静态成员变量，类内声明，类外初始化是语法要求；但初始化实质算在类内作用域
TaskQueue* TaskQueue::taskQ_ = new TaskQueue();
#endif

#if 0
/**
 * @brief 定义一个单例模式的任务队列
 * @brief 懒汉模式：什么时候使用这个单例对象，在使用时创建实例
 *
 * @note 在多线程的场景下，懒汉模式有线程安全问题
 * (懒汉模式问题在读数据时，通常为第一次，会产生多个实例)
 * 可以加 1.互斥锁 保证线程安全
 * 此外，需要使用 2.双重检查锁定 3.原子变量 保证线程安全
 */
class TaskQueue {
 public:
  TaskQueue(const TaskQueue& t) = delete;
  TaskQueue& operator=(const TaskQueue& t) = delete;  // 显式删除拷贝赋值函数
  static TaskQueue* GetInstance() {
    // 静态成员函数只能使用静态成员变量
    // std::lock_guard<std::mutex> lock(mutex_);
    /*
      从原子变量中加载指向任务队列的指针，判断该指针是否为空
    */
    TaskQueue* taskQ = taskQ_.load();
    // 双重检查锁定，在首次实例化后，后续线程可以同时访问实例对象
    if (taskQ == nullptr) {
      /*
        多个线程会阻塞在互斥锁上
        抢到互斥锁的线程继续向下执行
      */
      mutex_.lock();
      /*
        再次加载原子变量中的任务队列指针
        这步为必须
      */
      taskQ = taskQ_.load();
      if (taskQ == nullptr) {
        /*
          底层对这步分为三步操作：
          1.申请空内存
          2.空内存赋值
          3.返回堆区内存指针
          原子变量是为了让底层严格按这三步操作
        */
        taskQ = new TaskQueue();
        taskQ_.store(taskQ);
      }
      mutex_.unlock();
    }
    return taskQ;
  }
  void print() { std::cout << "懒汉模式单例对象的print函数..." << std::endl; }

 private:
  TaskQueue() {}
  // static TaskQueue* taskQ_;
  static std::mutex mutex_;
  static std::atomic<TaskQueue*> taskQ_;  // 用原子变量管理taskQ_
};
// TaskQueue* TaskQueue::taskQ_ = nullptr;
/*
  用原子变量管理任务队列的指针
  原子变量是static，类内声明，类外初始化，刚开始是空
  通过原子变量保存了当前类的实例对象
*/
std::atomic<TaskQueue*> TaskQueue::taskQ_;
std::mutex TaskQueue::mutex_;  // 类外对mutex_声明(因为mutex_在类内已经实例化)
#endif

#if 1
/**
 * @brief 定义一个单例模式的任务队列
 * @brief 懒汉模式：什么时候使用这个单例对象，在使用时创建实例
 *
 * @note 在多线程的场景下，懒汉模式有线程安全问题
 * 使用静态局部对象解决线程安全问题：要求编译器必须支持 C++ 11
 */
class TaskQueue {
 public:
  TaskQueue(const TaskQueue& t) = delete;
  TaskQueue& operator=(const TaskQueue& t) = delete;  // 显式删除拷贝赋值函数
  /*
    第一次调用GetInstance()时，在全局区创建静态对象taskQ
    第二次调用GetInstance()时，直接返回taskQ
    如果指令逻辑进入一个未被初始化的声明变量，所有并发执行应当等待该变量完成初始化：
    例如：
    对于静态变量，int b = 0; 没有初始化; int d; 没有初始化
    int c = 1; 初始化了
    因为静态变量在全局数据区，只要在全局数据区，其默认值都为0；
    所以，我们认为在全局数据区中 =0 的数据都是未初始化的
  */
  static TaskQueue* GetInstance() {
    /*多线程到来时，要等待taskQ初始化完成
      taskQ初始化过程：
        1.分配空内存
        2.调用TaskQueue构造函数得到对象
        3.把实例对象写入到空内存
      写完成结束后，内存被初始化，之后，所有等待的线程就可以继续了
      此时，taskQ是有效的且不会重复初始化
    */
    static TaskQueue taskQ;
    return &taskQ;
  }
  void print() { std::cout << "懒汉模式单例对象的print函数..." << std::endl; }

 private:
  TaskQueue() {}
};
#endif

int main(int argc, char* argv[]) {
  TaskQueue* taskQ = TaskQueue::GetInstance();
  taskQ->print();
  return 0;
}
