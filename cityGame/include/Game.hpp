#ifndef GAME_HPP_
#define GAME_HPP_

#include <map>
#include <string>
#include <stack>
#include <SFML/Graphics.hpp>

// Local Headers
#include <TextureManager.hpp>
#include <Tile.hpp>

class GameState;

class Game
{
private:
  void loadTextures();
  void loadTiles();

public:
  Game();
  ~Game();

  const static int tileSize = 8;

  std::stack<GameState*> states;

  sf::RenderWindow window;
  TextureManager texmgr;
  sf::Sprite background;

  std::map<std::string, Tile> tileAtlas;

  void pushState(GameState * state);
  void popState();
  void changeState(GameState * state);
  GameState * peekState();

  void gameLoop();
};

#endif

