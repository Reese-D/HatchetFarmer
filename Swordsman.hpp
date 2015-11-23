  #include "Unit.hpp"
  #ifndef SWORDSMAN_H
  #define SWORDSMAN_H
  class Swordsman : public Unit{
    Unit(int x, int y, int drawx, int drawy) : BoardObject(x, y, drawx, drawy) {
      range = 1;
      damage = 40;
      moveRange = 3;
      myDrawable->setOutlineColor(sf::Color(0,0,255));
    };
  };
  #endif
