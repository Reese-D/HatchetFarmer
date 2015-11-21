#ifndef BOARD_OBJECT_H
#define BOARD_OBJECT_H
#include <SFML/Graphics.hpp>
class BoardObject{
public:
  BoardObject(int xInArray, int yInArray);
  virtual ~BoardObject(){delete myDrawable;}; //must have virtual destructor
  virtual bool isPassable() =0;
  virtual void setDrawable(sf::Drawable *d);
  virtual sf::Drawable* getDrawable(){return myDrawable;};
protected:
  int x, y;
  sf::Drawable *myDrawable;
};
#endif
