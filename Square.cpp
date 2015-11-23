#include "Square.hpp"
Square::Square(int width, int height){
  this->width = width;
  this->height = height;
  sf::Vector2f temp = sf::Vector2<float>(width, height);
  myRect = sf::RectangleShape(temp);
  sf::Color color(255,0,0);
  myRect.setFillColor(sf::Color(255,255,255));
  myRect.setOutlineColor(color);
  myRect.setOutlineThickness(1);
}

Square::~Square(){
}

void Square::setPosition(int x, int y){
  this->x = x;
  this->y = y;
  myRect.setPosition(x,y);
}

sf::RectangleShape* Square::getDrawable(){
  //myRect.setFillColor(sf::Color(255,0,0));
  return &myRect;
}

void Square::setRectColor(sf::Color c){
  myRect.setFillColor(c);
}

void Square::setObject(std::shared_ptr<BoardObject> b){
  this->myObject = b;
}

void Square::swapObject(std::shared_ptr<BoardObject> b, int drawx, int drawy){
  this->myObject = b;
  std::dynamic_pointer_cast<Unit>(myObject)->moveDrawable(drawx, drawy);
}

std::shared_ptr<BoardObject> Square::getObject(){
  return std::move(myObject);
}
