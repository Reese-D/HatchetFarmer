#include "./include/SFML/Graphics.hpp"
#include <iostream> //cout

//g++ -I/usr/local/Cellar/sfml/2.3_1/include -L/usr/local/Cellar/sfml/2.3_1/lib -lsfml-window -lsfml-graphics -lsfml-system Test.cpp -o Test.out -Wall
int main()
{
  sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
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
      window.draw(shape);
      window.display(); //display new shite
  }

  return 0;
}
