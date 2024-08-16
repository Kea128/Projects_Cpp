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
  Ship();

 private:
  ShipBody* body_;
  Engine* engine_;
  Weapon* weapon_;
};

int main(int argc, char* argv[]) { return 0; }
