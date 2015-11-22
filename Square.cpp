#include "Square.hpp"
Square::Square(int width, int height){
  this->width = width;
  this->height = height;
  sf::Vector2f temp = sf::Vector2<float>(width, height);
  myRect = sf::RectangleShape(temp);
  sf::Color color(255,0,0);
  myRect.setOutlineColor(color);
  myRect.setOutlineThickness(3);
}

Square::~Square(){
}

void Square::setPosition(int x, int y){
  this->x = x;
  this->y = y;
  myRect.setPosition(x,y);
}

sf::RectangleShape Square::getDrawable(){
  return myRect;
}

void Square::setObject(std::shared_ptr<BoardObject> b){
  this->myObject = b;
}

std::shared_ptr<BoardObject> Square::getObject(){
  return myObject;
}
