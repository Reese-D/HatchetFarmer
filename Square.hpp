#ifndef SQUARE_H
#define SQUARE_H
#include <SFML/Graphics.hpp>
#include "BoardObject.hpp"
class Square{
public:
  Square(int width, int height);
  ~Square();  //clean up BoardObject pointer
  void setPosition(int x, int y);
  void setObject(BoardObject *b);
  BoardObject* getObject();
  sf::RectangleShape getDrawable();
private:
  int width, height, x, y;
  sf::RectangleShape myRect;
  BoardObject *myObject;
};
#endif
