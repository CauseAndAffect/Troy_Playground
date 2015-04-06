#ifndef GAME_STATE_HPP_
#define GAME_STATE_HPP_

#include <Game.hpp>

class GameState
{
public:
  Game * game;

  virtual void draw(const float dt) = 0;
  virtual void update(const float dt) = 0;
  virtual void handleInput() = 0;

};

#endif

