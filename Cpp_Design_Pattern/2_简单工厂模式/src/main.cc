#include <atomic>
#include <iostream>
#include <mutex>

/**
 * @brief 简单工厂模式
 * @brief 简单工厂模式，对应的工厂类有且只有一个
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
 * @brief 定义简单工厂类
 */
class SmileFactory {
 public:
  /**
   * @return 父类指针
   * @note 函数中创建子类对象，返回值为父类指针指向子类对象，发生多态
   */
  AbstractSmile* createSmile(SmileType type) {
    AbstractSmile* ptr = nullptr;
    switch (type) {
      case (SmileType::SHEEP): {
        ptr = new SheepSmile;
        break;
      }
      case (SmileType::LION): {
        ptr = new LionSmile;
        break;
      }
      case (SmileType::BAT): {
        ptr = new BatSmile;
        break;
      }
      default:
        break;
    }
  }
};

int main(int argc, char* argv[]) {
  SmileFactory factory;
  AbstractSmile* ptr = factory.createSmile(SmileType::BAT);
  ptr->transform();
  ptr->ability();

  delete ptr;
  return 0;
}
