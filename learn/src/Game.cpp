// Primary Header
#include <Game.hpp>

// Local Headers
#include <AnimationHandler.hpp>
#include <GameState.hpp>

// Standard Headers
#include <cstdio>

// SFML Headers
#include <SFML/System.hpp>

Game::Game()
{
  loadTextures();
  loadTiles();
  
  // Create instance of the main window
  window_.create(sf::VideoMode(800, 600), "Cause and Affect");
  window_.setFramerateLimit(60);
  
  // Set background image
  background_.setTexture(tesMgr.getRef("background");
}

Game::~Game()
{
  // Pop all states off the stack upon exit
  while (!states_.empty()) {
    popState();
  }
}

void Game::pushState(GameState * state)
{
  states_.push(state);
}

void Game::popState()
{
  // Deallocate memory for state then pop
  delete states_.top();
  states_.pop();
}

void Game::changeState(GameState * state)
{
  // Pop the newest state and replace with passed state
  if (!states_.empty()) {
    popState();
  }

  pushState(state);
}

GameState* Game::peekState()
{
  if (states_.empty()) {
    return NULL;
  }
  
  return states_.top();
}

void Game::gameLoop()
{
  sf::Clock clock;
  
  // Do this until user closes the window
  while (window_.isOpen()) {
    sf::Time elapsed = clock.restart();
    float dt = elapsed.asSeconds();
    
    // If no states on the stack, carry on
    if (peekState() == NULL) {
      continue;
    }
    
    // For every iteration, perform the following steps
    
    // Respond to inputs from the user
    peekState()->handleInput();
    // Update the state
    peekState()->update(dt);
    // Clear the window
    window_.clear(sf::Color::Black);
    // Draw new window 
    peekState()->draw(dt);
    // Display new window
    window_.display();
  }
}

void Game::loadTextures()
{
  // TODO:
  texMgr_.loadTexture();
}



















