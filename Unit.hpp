#ifndef UNIT_H
#define UNIT_H
#include "BoardObject.hpp"
#define DEFAULT_SIZE 10
class Unit : public BoardObject{
public:
  Unit(int x, int y, int drawx, int drawy) : BoardObject(x, y, drawx, drawy) {
    std::shared_ptr<sf::CircleShape> tempDraw =std::shared_ptr<sf::CircleShape>(new sf::CircleShape(DEFAULT_SIZE));
    tempDraw->setFillColor(sf::Color(0,255,0));
    tempDraw->setPosition(drawx,drawy);
    myDrawable = std::move(tempDraw);
    range = 1;
    health = 100;
    damage = 20;
    moveRange = 1;
  };
  bool isPassable(){return false;}; //override pure virtual parent function
  virtual void attack(std::shared_ptr<Unit> b);
  virtual bool takeDamage(int damageRecieved); //returnse false on death
  virtual int getMoveRange(){return moveRange;};
  virtual int getAttackRange(){return range;};
  virtual int getHealth(){return health;};
  std::string myType(){return "Unit";};
  virtual void moveDrawable(int drawx, int drawy){
    std::dynamic_pointer_cast<sf::CircleShape>(myDrawable)->setPosition(drawx, drawy);
  };
protected:
  int range, health, damage, moveRange;
};
#endif
