#ifndef UNIT_H
#define UNIT_H
#include "boardObject.hpp"
#define DEFAULT_SIZE 5
class Unit : public BoardObject{
public:
  Unit(int x, int y) : BoardObject(x, y) {myDrawable = new sf::CircleShape(DEFAULT_SIZE);};
  bool isPassable(){return false;}; //override pure virtual parent function
};
#endif
