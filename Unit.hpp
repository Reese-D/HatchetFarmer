#ifndef UNIT_H
#define UNIT_H
#include "boardObject.hpp"
class Unit : public BoardObject{
public:
  Unit(int x, int y) : BoardObject(x, y) {}
  bool isPassable(){return false;}; //override pure virtual parent function
};
#endif
