#ifndef GAME_HPP_
#define GAME_HPP_

// Local Headers
#include <TextureManager.hpp>
#include <Tile.hpp>

// Standard Headers
#include <map>
#include <string>
#include <stack>

// 3rd Party Headers
#include <SFML/Graphics.hpp>

class GameState;

class Game
{
public:
  Game();
  ~Game();
  
  const uint8_t TILE_SIZE;
  
  std::stack<GameState*> states_;
  
  sf::RenderWindow window_;
  TextureManager texMgr_;
  sf::Sprint background_;
  
  std::map<std::string, Tile> tileAtlas_;
  
  void pushState(GameState * state);
  void popState();
  void changeState(GameState * state);
  GameState * peekState();
  
  void gameLoop();
  
private:
  void loadTextures();
  void loadTiles();

};

#endif
