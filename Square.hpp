#ifndef SQUARE_H
#define SQUARE_H
#include <SFML/Graphics.hpp>
class Square{
public:
  Square(int width, int height);
  void setPosition(int x, int y);
  sf::RectangleShape getDrawable();
private:
  int width, height, x, y;
  sf::RectangleShape myRect;
};
#endif
