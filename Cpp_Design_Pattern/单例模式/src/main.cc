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

#if 1
/**
 * @brief 定义一个单例模式的任务队列
 * @brief 懒汉模式：什么时候使用这个单例对象，在使用时创建实例
 *
 * @note 在多线程的场景下，懒汉模式有线程安全问题
 * (懒汉模式问题在读数据时，通常为第一次，会产生多个实例)
 * 可以加互斥锁保证线程安全
 */
class TaskQueue {
 public:
  TaskQueue(const TaskQueue& t) = delete;
  TaskQueue& operator=(const TaskQueue& t) = delete;  // 显式删除拷贝赋值函数
  static TaskQueue* GetInstance() {
    // 静态成员函数只能使用静态成员变量
    // std::lock_guard<std::mutex> lock(mutex_);
    // 双重检查锁定，在首次实例化后，后续线程可以同时访问实例对象
    if (taskQ_ == nullptr) {
      mutex_.lock();
      if (taskQ_ == nullptr) {
        taskQ_ = new TaskQueue();
      }
      mutex_.unlock();
    }
    return taskQ_;
  }
  void print() { std::cout << "懒汉模式单例对象的print函数..." << std::endl; }

 private:
  TaskQueue() {}
  // static TaskQueue* taskQ_;
  static std::mutex mutex_;
  static std::atomic<TaskQueue*> taskQ_;  // 用原子变量管理taskQ_
};
// TaskQueue* TaskQueue::taskQ_ = nullptr;
std::atomic<TaskQueue*> TaskQueue::taskQ_;
std::mutex TaskQueue::mutex_;  // 类外对mutex_声明(因为mutex_在类内已经实例化)
#endif

int main(int argc, char* argv[]) {
  TaskQueue* taskQ = TaskQueue::GetInstance();
  taskQ->print();
  return 0;
}
