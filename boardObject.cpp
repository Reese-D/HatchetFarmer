#include "BoardObject.hpp"

BoardObject::BoardObject(int xInArray, int yInArray, int drawx, int drawy){
  this->x = xInArray;
  this->y = yInArray;
  this->drawx = drawx;
  this->drawy = drawy;
}

void BoardObject::setDrawable(std::shared_ptr<sf::Drawable> d){
  myDrawable = d;
}
