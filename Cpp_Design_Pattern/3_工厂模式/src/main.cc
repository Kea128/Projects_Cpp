#include <atomic>
#include <iostream>
#include <mutex>

/**
 * @brief 工厂模式
 * @brief 工厂模式，对应的工厂类为抽象工厂类和子类
 */

/**
 * @brief 父类(抽象类)
 */
class AbstractSmile {
 public:
  virtual void transform() = 0;
  virtual void ability() = 0;

  /*
    首先多态发生条件：
    1.子类继承父类
    2.子类重写父类的(纯)虚函数
    3.父类指针或引用指向子类对象
    4.父类指针或引用调用(父类)子类方法

    父类中提供虚析构函数，是为了释放父类指针指向的具体某个子类对象
    如果不提供，当指向子类对象的父类指针delete时，只会释放父类对象(释放在子类对象中的父类对象)
    (因为在父类指针中保存的是子类对象的地址，这样无法完全析构子类对象,只能析构子类对象中的父类对象)
  */
  virtual ~AbstractSmile(){};
};

class SheepSmile : public AbstractSmile {
 public:
  void transform() override { std::cout << "派生类a 函数1" << std::endl; }

  void ability() override { std::cout << "派生类a 函数2" << std::endl; }
};

class LionSmile : public AbstractSmile {
 public:
  void transform() override { std::cout << "派生类b 函数1" << std::endl; }

  void ability() override { std::cout << "派生类b 函数2" << std::endl; }
};

class BatSmile : public AbstractSmile {
 public:
  void transform() override { std::cout << "派生类c 函数1" << std::endl; }

  void ability() override { std::cout << "派生类c 函数2" << std::endl; }
};

/**
 * @brief 强类型枚举，底层对应char类型
 */
enum class SmileType : char {
  SHEEP,
  LION,
  BAT,
};

/**
 * @brief 定义工厂类 - 父类(抽象类)
 * @note 抽象类中定义接口
 * @note 子类重写接口
 * @note 通过父类的工厂指针指向子类对象
 */
class AbstractFactory {
 public:
  virtual AbstractSmile* createSmile() = 0;
  virtual ~AbstractFactory() { std::cout << "父工厂类, 析构函数" << std::endl; }
};

class SheepFactory : public AbstractFactory {
 public:
  AbstractSmile* createSmile() override { return new SheepSmile; }
  ~SheepFactory() { std::cout << "派生工厂a, 析构函数" << std::endl; }
};

class LionFactory : public AbstractFactory {
 public:
  AbstractSmile* createSmile() override { return new LionSmile; }
  ~LionFactory() { std::cout << "派生工厂b, 析构函数" << std::endl; }
};

class BatFactory : public AbstractFactory {
 public:
  AbstractSmile* createSmile() override { return new BatSmile; }
  ~BatFactory() { std::cout << "派生工厂c, 析构函数" << std::endl; }
};

int main(int argc, char* argv[]) {
  // 父工厂类指针指向子工厂类对象
  AbstractFactory* factoryPtr = nullptr;
  factoryPtr = new SheepFactory;
  // 父工厂类指针调用子类对象中的函数，传递给Smile的父类指针
  AbstractSmile* smilePtr = factoryPtr->createSmile();
  // 通过Smile父类指针调用子类对象中的函数
  smilePtr->transform();
  smilePtr->ability();
  delete factoryPtr;
  delete smilePtr;
  return 0;
}
