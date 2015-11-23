#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <vector>
#include "Square.hpp"
class Grid{
public:
  Grid(int height, int width, int squareWidth, int squareHeight);
  int getSquareWidth();
  int getSquareHeight();
  std::vector< std::vector<std::shared_ptr<Square> > >* getGrid();
  int width, height, squareWidth, squareHeight;
  std::vector< std::vector<std::shared_ptr<Square> > > grid;
protected:
};
#endif
