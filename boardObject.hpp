#ifndef BOARD_OBJECT_H
#define BOARD_OBJECT_H
class BoardObject{
public:
  BoardObject(int xInArray, int yInArray);
  virtual ~BoardObject(){}; //must have virtual destructor
  virtual bool isPassable() =0;
protected:
  int x, y;
};
#endif
