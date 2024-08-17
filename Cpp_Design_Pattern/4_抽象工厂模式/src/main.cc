#include <iostream>
#include <string>

/**
 * @brief 抽象工厂模式
 */

/**
 * @brief 船体父类
 */
class ShipBody {
 public:
  virtual std::string getBody() = 0;
  virtual ~ShipBody(){};
};

class WoodBody : public ShipBody {
 public:
  std::string getBody() override {
    return std::string("使用<木材>制作船体...");
  }
};

class IronBody : public ShipBody {
 public:
  std::string getBody() override {
    return std::string("使用<钢材>制作船体...");
  }
};

class MetalBody : public ShipBody {
 public:
  std::string getBody() override {
    return std::string("使用<合成金属>制作船体...");
  }
};

/**
 * @brief 引擎父类
 */
class Engine {
 public:
  virtual std::string getEngine() = 0;
  virtual ~Engine(){};
};

class HumanEngine : public Engine {
 public:
  std::string getEngine() override {
    // 如果不用string构造，发生隐式类型转换
    return "动力方式 <手动>...";
  }
};

class DieselEngine : public Engine {
 public:
  std::string getEngine() override {
    // 如果不用string构造，发生隐式类型转换
    return "动力方式 <内燃机>...";
  }
};

class NuclearEngine : public Engine {
 public:
  std::string getEngine() override {
    // 如果不用string构造，发生隐式类型转换
    return "动力方式 <核反应堆>...";
  }
};

/**
 * @brief 武器父类
 */
class Weapon {
 public:
  virtual std::string getWeapon() = 0;
  virtual ~Weapon(){};
};

class GunWeapon : public Weapon {
 public:
  std::string getWeapon() override { return "武器 <枪>..."; }
};

class CannonWeapon : public Weapon {
 public:
  std::string getWeapon() override { return "武器 <加农炮>..."; }
};

class LaserWeapon : public Weapon {
 public:
  std::string getWeapon() override { return "武器 <激光>..."; }
};

/**
 * @brief 船类
 */
class Ship {
 public:
  Ship(ShipBody* body, Engine* engine, Weapon* weapon)
      : body_(body), engine_(engine), weapon_(weapon) {}
  ~Ship() {
    delete body_;
    delete engine_;
    delete weapon_;
  }

  std::string getProperty() {
    return body_->getBody() + engine_->getEngine() + weapon_->getWeapon();
  }

 private:
  ShipBody* body_;
  Engine* engine_;
  Weapon* weapon_;
};

/**
 * 工厂类 - 抽象
 */
class AbstractFactory {
 public:
  virtual Ship* createShip() = 0;
  virtual ~AbstractFactory() {}
};

class BasicFactory : public AbstractFactory {
 public:
  Ship* createShip() override {
    Ship* ship = new Ship(new WoodBody(), new HumanEngine(), new GunWeapon());
    std::cout << "制造基础型号" << std::endl;
    return ship;
  }
};

class StandardFactory : public AbstractFactory {
 public:
  Ship* createShip() override {
    Ship* ship =
        new Ship(new IronBody(), new DieselEngine(), new CannonWeapon());
    std::cout << "制造标准型号" << std::endl;
    return ship;
  }
};

class AdvancedFactory : public AbstractFactory {
 public:
  Ship* createShip() override {
    Ship* ship =
        new Ship(new MetalBody(), new NuclearEngine(), new LaserWeapon());
    std::cout << "制造高级型号" << std::endl;
    return ship;
  }
};

int main(int argc, char* argv[]) {
  AbstractFactory* factory = new AdvancedFactory;
  Ship* ship = factory->createShip();
  std::cout << ship->getProperty() << std::endl;
  delete ship;
  delete factory;
  return 0;
}
