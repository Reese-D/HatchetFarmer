#ifndef BOARD_OBJECT_H
#define BOARD_OBJECT_H
#include <SFML/Graphics.hpp>
class BoardObject{
public:
  BoardObject(int xInArray, int yInArray, int drawx, int drawy);
  virtual ~BoardObject(){}; //must have virtual destructor
  virtual bool isPassable() =0;
  virtual void setDrawable(std::shared_ptr<sf::Drawable> d);
  virtual std::shared_ptr<sf::Drawable> getDrawable(){return myDrawable;};
  virtual std::string myType() =0;
protected:
  int x, y,drawx,drawy;
  std::shared_ptr<sf::Drawable> myDrawable;
};
#endif
