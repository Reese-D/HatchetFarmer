#ifndef UNIT_H
#define UNIT_H
#include "BoardObject.hpp"
#define DEFAULT_SIZE 10
class Unit : public BoardObject{
public:
  struct UnitType{
    short range, health, damage, moveRange;
  };
  Unit(int x, int y, int drawx, int drawy) : BoardObject(x, y, drawx, drawy) {
    std::shared_ptr<sf::CircleShape> tempDraw =std::shared_ptr<sf::CircleShape>(new sf::CircleShape(DEFAULT_SIZE));
    tempDraw->setFillColor(sf::Color(0,255,0));
    tempDraw->setPosition(drawx,drawy);
    myDrawable = std::move(tempDraw);
  };
  bool isPassable(){return false;}; //override pure virtual parent function
  void attack(std::shared_ptr<Unit> b);
  bool takeDamage(int damageRecieved); //returnse false on death
  int getMoveRange();
  int getAttackRange();
  int getHealth();
  std::string myType(){return "Unit";};

  virtual void moveDrawable(int drawx, int drawy){
    std::dynamic_pointer_cast<sf::CircleShape>(myDrawable)->setPosition(drawx, drawy);
  };
};
#endif
