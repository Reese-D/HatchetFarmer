
//g++ Grid.cpp -c -Wall
#include "Grid.hpp"

Grid::Grid(int width, int height, int squareWidth, int squareHeight){
  this->height = height;
  this->width = width;
  this->squareWidth = squareWidth;
  this->squareHeight = squareHeight;
  grid.assign(height, std::vector<Square>(width, Square(squareWidth, squareHeight)));
  for(uint y = 0; y < grid.size(); y++){
    for(uint x = 0; x < grid[y].size(); x++){
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
