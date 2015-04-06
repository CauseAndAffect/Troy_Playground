#ifndef GAME_STATE_START_HPP_
#define GAME_STATE_START_HPP_

#include <SFML/Graphics.hpp>

// Local Headers
#include <GameState.hpp>

class GameStateStart : public GameState
{
private:

  sf::View view;
  void loadgame();

public:

  virtual void draw(const float dt);
  virtual void update(const float dt);
  virtual void handleInput();

  GameStateStart(Game* game);
};

#endif /* GAME_STATE_START_HPP */
