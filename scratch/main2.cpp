#include <SFML/Graphics.hpp>

int main()
{
  sf::VideoMode videoMode(320, 240);
  sf::RenderWindow window(videoMode, "KeyEvent window");
  window.setFramerateLimit(60);

  sf::RectangleShape rectangle;
  rectangle.setPosition(30, 30);
  rectangle.setSize(sf::Vector2f(50, 30));

  rectangle.setFillColor(sf::Color::Yellow);
  rectangle.setOutlineColor(sf::Color::Blue);
  rectangle.setOutlineThickness(3);

  while (window.isOpen()) {
    window.clear();
    window.draw(rectangle);
    window.display();

    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed ||
          (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
        window.close();
      }
      else if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
          case sf::Keyboard::Up:
            rectangle.move(0, -10);
            break;
          case sf::Keyboard::Down:
            rectangle.move(0, 10);
            break;
          case sf::Keyboard::Left:
            rectangle.move(-10, 0);
            break;
          case sf::Keyboard::Right:
            rectangle.move(10, 0);
            break;
        }
      }
    }
  }

  return 0;
}
