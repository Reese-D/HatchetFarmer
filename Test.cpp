#include <SFML/Window.hpp>
#include "Grid.hpp"
#include "Unit.hpp"
#define SQUARE_WIDTH 50
#define SQUARE_HEIGHT 50
sf::RectangleShape drawRectangle(float x, float y, int width, int height){
  sf::Vector2f temp = sf::Vector2<float>(width, height);
  sf::RectangleShape returnVal = sf::RectangleShape(temp);
  returnVal.setPosition(x, y);
  return returnVal;
}

void moveUnit(Grid *grid, int fromX, int fromY, int toX, int toY){
  std::vector<std::vector<std::shared_ptr<Square> > > temporary = *(grid->getGrid());
  std::shared_ptr<Unit> movingObj = std::dynamic_pointer_cast<Unit>(temporary[fromY][fromX]->getObject());

  //if there isn't already a unit in the spot you want to move to
  if(temporary[toY][toX]->getObject() == nullptr){
    temporary[toY][toX]->setObject(movingObj); //set the object to the new spot
    temporary[fromY][fromX]->setObject(nullptr); //remove the object from the old spot
    std::dynamic_pointer_cast<sf::CircleShape>(movingObj->getDrawable())
        ->setPosition(SQUARE_WIDTH * toX+15, SQUARE_HEIGHT * toY+15);
  }
}
int main()
{
  int gridWidth = 20;
  int gridHeight = 20;
  Grid* myGrid = new Grid(gridWidth, gridHeight, SQUARE_WIDTH, SQUARE_HEIGHT);

  sf::RenderWindow window(sf::VideoMode(1500, 1500), "SFML works!");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  while (window.isOpen())
  {
      sf::Event event;
      while (window.pollEvent(event))
      {
        switch (event.type){
          case sf::Event::Closed:
            window.close();
            break;
          case sf::Event::KeyPressed:
            //TODO: handle hotkeys
            break;
          case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left){
              std::cout << "left button pressed" << std::endl;
              std::cout << "mouse x: " << event.mouseButton.x << std::endl;
              std::cout << "mouse y: " << event.mouseButton.y << std::endl;
              //
              //
              std::vector<std::vector<std::shared_ptr<Square> > > temp = myGrid->grid;
              temp[event.mouseButton.y/SQUARE_HEIGHT][event.mouseButton.x/SQUARE_WIDTH]->setRectColor(sf::Color(255,0,0));
            }
            break;
          case sf::Event::MouseButtonReleased:
            if(event.mouseButton.button == sf::Mouse::Left){
              std::vector<std::vector<std::shared_ptr<Square> > > temp = myGrid->grid;
              temp[event.mouseButton.y/SQUARE_HEIGHT][event.mouseButton.x/SQUARE_WIDTH]->setRectColor(sf::Color(255,255,255));
            }
            break;
          default:
            break;
        }
      }

      window.clear(); //clear previous shite
      //window.draw(drawRectangle(100,10,50,20));
      std::vector<std::vector<std::shared_ptr<Square> > > temp = *(myGrid->getGrid());
      for(int y = 0; y < temp.size(); y++){
        for(int x = 0; x < temp[y].size(); x++){
          Square currSquare = *temp[y][x];
          window.draw(*currSquare.getDrawable());
          currSquare.setObject(std::shared_ptr<Unit>(new Unit(x, y, x*50+23, y*50+23)));
          if(currSquare.getObject() != nullptr){
            std::shared_ptr<Unit> temp = std::dynamic_pointer_cast<Unit>(currSquare.getObject());
            sf::CircleShape shape = *std::dynamic_pointer_cast<sf::CircleShape>(temp->getDrawable());
            window.draw(shape);
          }
        }
      }
      window.display(); //display new shite
  }

  return 0;
}
