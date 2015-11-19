#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream> //cout

sf::RectangleShape drawRectangle(float x, float y, int width, int height){
  sf::Vector2f temp = sf::Vector2<float>(width, height);
  sf::RectangleShape returnVal = sf::RectangleShape(temp);
  returnVal.setPosition(x, y);
  return returnVal;
}
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
      window.draw(drawRectangle(100,10,50,20));
      window.display(); //display new shite
  }

  return 0;
}
