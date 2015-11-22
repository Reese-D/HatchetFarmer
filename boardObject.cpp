#include "BoardObject.hpp"

BoardObject::BoardObject(int xInArray, int yInArray){
  this->x = xInArray;
  this->y = yInArray;
}

void BoardObject::setDrawable(std::shared_ptr<sf::Drawable> d){
  myDrawable = d;
}
