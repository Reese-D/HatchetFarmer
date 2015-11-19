#include <SFML/Window.hpp>
#include "Grid.hpp"

sf::RectangleShape drawRectangle(float x, float y, int width, int height){
  sf::Vector2f temp = sf::Vector2<float>(width, height);
  sf::RectangleShape returnVal = sf::RectangleShape(temp);
  returnVal.setPosition(x, y);
  return returnVal;
}
int main()
{
  int gridWidth = 20;
  int gridHeight = 20;
  Grid* myGrid = new Grid(gridWidth, gridHeight, 50, 50);

  sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
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
            }
            break;
          default:
            break;
        }
      }

      window.clear(); //clear previous shite
      //window.draw(drawRectangle(100,10,50,20));
      for(int y = 0; y < myGrid->getGrid().size(); y++){
        for(int x = 0; x < myGrid->getGrid()[y].size(); x++){
          window.draw(myGrid->getGrid()[y][x].getDrawable());
        }
      }
      window.display(); //display new shite
  }

  return 0;
}
