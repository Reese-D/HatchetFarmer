#ifndef UNIT_H
#define UNIT_H
#include "boardObject.hpp"
#define DEFAULT_SIZE 5
class Unit : public BoardObject{
public:
  Unit(int x, int y) : BoardObject(x, y) {
    std::shared_ptr<sf::CircleShape> tempDraw =std::shared_ptr<sf::CircleShape>(new sf::CircleShape(DEFAULT_SIZE));
    tempDraw->setFillColor(sf::Color(0,255,0));
    tempDraw->setPosition(x*50,y*50);
    myDrawable = tempDraw;
  };
  bool isPassable(){return false;}; //override pure virtual parent function
};
#endif
