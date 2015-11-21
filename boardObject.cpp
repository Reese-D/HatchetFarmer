#include "BoardObject.hpp"

BoardObject::BoardObject(int xInArray, int yInArray){
  this->x = xInArray;
  this->y = yInArray;
}

void BoardObject::setDrawable(sf::Drawable *d){
  delete myDrawable;  //free old memory
  myDrawable = d;
}
