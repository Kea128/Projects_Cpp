#ifndef _THREAD_POOL_H_
#define _THREAD_POOL_H_

#include <atomic>              // 原子变量
#include <condition_variable>  // 条件变量头文件
#include <functional>  // 可调用对象的包装器和绑定器对应的头文件
#include <iostream>
#include <map>    // 工作线程map容器
#include <mutex>  // 互斥锁
#include <queue>  // 任务队列，先进先出
#include <thread>
#include <vector>  // 工作线程vector容器,替换为map容器

/**
 * 线程池构成：
 * 1.管理者线程 --> 子线程，1个
 *      -控制工作线程的数量，增加或减少
 * 2.若干工作线程 --> 子线程，n个
 *      -从任务队列中取出任务，并处理
 *      -任务队列为空，被阻塞(被条件变量阻塞)
 *      -线程同步(需要互斥锁)(工作的线程在从任务队列中取出任务过程中需要线程同步)
 *      -需要知道当前工作线程的数量，空闲线程数量
 *      -最小，最大线程数量
 * 3.任务队列 --> stl-->queue容器
 *      -对任务队列进行操作需要互斥锁
 *      -还需要条件变量
 * 4.线程池开关 --> bool类型变量
 *      -关闭：销毁线程池中的所有线程
 *      -开启：让线程池中的所有线程工作
 */

namespace my_thread_pool {
class ThreadPool {
 public:
  ThreadPool(int minThreads = 2,
             int maxThreads = std::thread::hardware_concurrency());
  ~ThreadPool();

  // 添加任务的函数 ---> 任务队列
  // 参数为可调用对象类型,因为任务队列类型为std::function
  // 任务队列为线程间共享资源，当线程从其中取任务时，需要进行线程同步,就需要互斥锁
  void addTask(std::function<void(void)> task);

 private:
  // 任务函数
  void manager();
  void worker();

 private:
  // 管理者线程指针，指向实例
  std::thread* manager_;
  // 存储已经退出任务函数的线程id
  std::vector<std::thread::id> workers_ids_;
  // 更新线程存储方式为map
  std::map<std::thread::id, std::thread> workers_;

  // 定义原子变量的线程最大最小数量，因为不确定是否要作为共享资源在线程间修改
  // 设置为原子变量，保证线程安全
  std::atomic<int> minThreads_;
  std::atomic<int> maxThreads_;
  // 当前工作线程的数量，空闲线程数量也不能保证它们不会在多线程中被访问修改
  // 也定义为原子变量
  std::atomic<int> curThreads_;
  std::atomic<int> idleThreads_;
  // 退出的线程数量
  std::atomic<int> exitThreads_;

  // 线程池开关也需要在多个线程访问，定义为原子变量
  std::atomic<bool> trigger_;

  // 任务队列
  // 虽然这里std::function的类型为void(void)不带参
  // 但是可以使用std::bind绑定，降元
  std::queue<std::function<void(void)>> tasks_;

  // 互斥锁：用来保护任务队列queue
  std::mutex queue_mutex_;
  // 互斥锁：用来保护存储已经退出任务函数的线程id的vector容器
  std::mutex ids_mutex_;

  // 条件变量，用来阻塞消费者线程
  // 当任务队列为空时，阻塞消费者线程
  // 当任务队列放入新的任务时，唤醒消费者线程
  std::condition_variable conditon_;
};
}  // namespace my_thread_pool

#endif
