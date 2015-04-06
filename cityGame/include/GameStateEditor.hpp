#ifndef GAME_STATE_EDITOR_HPP_
#define GAME_STATE_EDITOR_HPP_

#include <SFML/Graphics.hpp>

// Local Headers
#include <GameState.hpp>
#include <Map.hpp>

enum class ActionState { NONE, PANNING};

class GameStateEditor : public GameState
{
private:

  ActionState actionState;

  sf::View gameView;
  sf::View guiView;

  Map map;

  sf::Vector2i panningAnchor;
  float zoomLevel;

public:

  virtual void draw(const float dt);
  virtual void update(const float dt);
  virtual void handleInput();

  GameStateEditor(Game* game);
};

#endif /* GAME_STATE_EDITOR_HPP */
