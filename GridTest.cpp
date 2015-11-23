//must compile Square.cpp & Grid.cpp first
//g++ GridTest.cpp -o Test.out -Wall Grid.o Square.o
#include "Grid.hpp"
#include <assert.h>
void testConstructorAndGetters(){
    Grid* myGrid = new Grid(9, 10, 8, 7);
    assert(myGrid->getSquareHeight() == 7);
    assert(myGrid->getSquareWidth() == 8);
    assert(myGrid->getGrid()->size() == 10);
    assert((*(myGrid->getGrid()))[0].size() == 9);
}
int main(){
  testConstructorAndGetters();
  std::cout << "all assertions passed" << std::endl;
}
