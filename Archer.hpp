#include "Unit.hpp"
#ifndef ARCHER_H
#define ARCHER_H
class Archer : public Unit{
  Archer(int x, int y, int drawx, int drawy) : Unit(x, y, drawx, drawy){
    range = 5;
    damage = 20;
    moveRange = 2;
    myDrawable->setOutlineColor(sf::Color(100,100,20));
  };
};
#endif ARCHER_H
