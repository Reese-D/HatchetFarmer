#include <SFML/Window.hpp>
#include "Grid.hpp"
#include "Unit.hpp"
#include <type_traits>
#define SQUARE_WIDTH 50
#define SQUARE_HEIGHT 50



// #define DECL_TYPE_NAME(x) template<> struct type_name<x> { static const char* name() {return #x;} }
// template<typename T> struct type_name
// {
//     static const char* name() { static_assert(false, "You are missing a DECL_TYPE_NAME"); }
// };
//
// template<> struct type_name<Unit> { static const char* name() {return "Unit";} };
// template<> struct type_name<Swordsman> { static const char* name() {return "Swordsman";} };
// template<> struct type_name<Archer> { static const char* name() {return "Archer";} };
// template<> struct type_name<Building> { static const char* name() {return "Building";} };
//
// DECL_TYPE_NAME(Square);

sf::RectangleShape drawRectangle(float x, float y, int width, int height){
  sf::Vector2f temp = sf::Vector2<float>(width, height);
  sf::RectangleShape returnVal = sf::RectangleShape(temp);
  returnVal.setPosition(x, y);
  return returnVal;
}



bool stored = false;
std::shared_ptr<Unit> temporaryStoredUnit;
std::shared_ptr<Unit> oldStored;
int canMoveX, canMoveY;
void moveUnit(std::shared_ptr<Square> clicked, int mouseX, int mouseY){
  if(stored){
    if(clicked->getObject() == nullptr){
      clicked->swapObject(std::move(temporaryStoredUnit)
          , mouseX/SQUARE_WIDTH*50+23, mouseY/SQUARE_HEIGHT*50+23);
      stored = false;
    }else{
      oldStored = std::move(temporaryStoredUnit);
      stored = false;
    }
  }else{  //no prevoiusly selected unit
    std::string tempString = "Unit";
    if(clicked->getObject() != nullptr && tempString.compare(clicked->getObject()->myType()) == 0){
      oldStored = std::dynamic_pointer_cast<Unit>(clicked->getObject());
      temporaryStoredUnit = std::move(oldStored);
      clicked->getObject() = nullptr;
      stored = true;
    }
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
  (*myGrid->getGrid())[0][0]->setObject(std::shared_ptr<Unit>(new Unit(0, 0, 0*50+23, 0*50+23, Unit::Archer)));
  (*myGrid->getGrid())[1][1]->setObject(std::shared_ptr<Unit>(new Unit(1, 1, 1*50+23, 1*50+23, Unit::Swordsman)));
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

              std::shared_ptr<Square> clicked = temp[event.mouseButton.y/SQUARE_HEIGHT][event.mouseButton.x/SQUARE_WIDTH];
              moveUnit(clicked, event.mouseButton.x, event.mouseButton.y); //move the unit if possibruu

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
          // currSquare.setObject(std::shared_ptr<Unit>(new Unit(x, y, x*50+23, y*50+23)));
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
