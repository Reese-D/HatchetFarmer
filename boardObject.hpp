#ifndef BOARD_OBJECT_H
#define BOARD_OBJECT_H
#include <SFML/Graphics.hpp>
class BoardObject{
public:
  BoardObject(int xInArray, int yInArray);
  virtual ~BoardObject(){}; //must have virtual destructor
  virtual bool isPassable() =0;
  virtual void setDrawable(std::shared_ptr<sf::Drawable> d);
  virtual std::shared_ptr<sf::Drawable> getDrawable(){return myDrawable;};
protected:
  int x, y;
  std::shared_ptr<sf::Drawable> myDrawable;
};
#endif
