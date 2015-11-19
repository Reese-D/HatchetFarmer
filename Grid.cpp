
//g++ Grid.cpp -c -Wall
#include "Grid.hpp"

Grid::Grid(int width, int height, int squareWidth, int squareHeight){
  this->height = height;
  this->width = width;
  this->squareWidth = squareWidth;
  this->squareHeight = squareHeight;
  grid.assign(height, std::vector<Square>(width, Square(squareWidth, squareHeight)));
  for(int y = 0; y < (int)grid.size(); y++){
    for(int x = 0; x < (int)grid[y].size(); x++){
      grid[y][x].setPosition(squareWidth*x, squareHeight*y);
    }
  }
}

int Grid::getSquareWidth(){
  return squareWidth;
}

int Grid::getSquareHeight(){
  return squareHeight;
}

std::vector< std::vector<Square> > Grid::getGrid(){
  return grid;
}
