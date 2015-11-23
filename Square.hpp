#ifndef SQUARE_H
#define SQUARE_H
#include <SFML/Graphics.hpp>
#include "BoardObject.hpp"
class Square{
public:
  Square(int width, int height);
  ~Square();  //clean up BoardObject pointer
  void setPosition(int x, int y);
  void setRectColor(sf::Color c);
  void setObject(std::shared_ptr<BoardObject> b);
  std::shared_ptr<BoardObject> getObject();
  sf::RectangleShape* getDrawable();

private:
  int width, height, x, y;
  sf::RectangleShape myRect;
  std::shared_ptr<BoardObject> myObject;
};
#endif
