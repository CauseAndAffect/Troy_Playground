// Primary Header
#include <Game.hpp>

// Local Headers
#include <AnimationHandler.hpp>
#include <GameState.hpp>
#include <TextureManager.hpp>

// Standard Headers
#include <cstdio>

// SFML Headers
#include <SFML/System.hpp>

Game::Game()
{
  this->loadTextures();
  this->loadTiles();

  this->window.create(sf::VideoMode(800, 600), "City Builder");
  this->window.setFramerateLimit(60);

  this->background.setTexture(this->texmgr.getRef("background"));
}

Game::~Game()
{
  while(!this->states.empty()) {
    popState();
  }
}

void Game::pushState(GameState * state)
{
  this->states.push(state);
  return;
}

void Game::popState()
{
    delete this->states.top();
    this->states.pop();

    return;
}

void Game::changeState(GameState* state)
{
    if(!this->states.empty()) {
        popState();
    }
    pushState(state);

    return;
}

GameState* Game::peekState()
{
    if(this->states.empty()) {
      return NULL;
    }

    return this->states.top();
}

void Game::gameLoop()
{
  sf::Clock clock;

  while (this->window.isOpen()) {
    sf::Time elapsed = clock.restart();
    float dt = elapsed.asSeconds();

    if (peekState() == NULL) {
      continue;
    }
    peekState()->handleInput();
    peekState()->update(dt);
    this->window.clear(sf::Color::Black);
    peekState()->draw(dt);
    this->window.display();
  }
}

void Game::loadTextures()
{
  texmgr.loadTexture("grass",         "media/grass.png");
  texmgr.loadTexture("forest",        "media/forest.png");
  texmgr.loadTexture("water",         "media/water.png");
  texmgr.loadTexture("residential",   "media/residential.png");
  texmgr.loadTexture("commercial",    "media/commercial.png");
  texmgr.loadTexture("industrial",    "media/industrial.png");
  texmgr.loadTexture("road",          "media/road.png");

  texmgr.loadTexture("background", "media/background.png");
}

void Game::loadTiles()
{
    Animation staticAnim(0, 0, 1.0f);
    this->tileAtlas["grass"] =
        Tile(this->tileSize, 1, texmgr.getRef("grass"),
            { staticAnim },
            TileType::GRASS, 50, 0, 1);
    tileAtlas["forest"] =
        Tile(this->tileSize, 1, texmgr.getRef("forest"),
            { staticAnim },
            TileType::FOREST, 100, 0, 1);   
    tileAtlas["water"] =
        Tile(this->tileSize, 1, texmgr.getRef("water"),
            { Animation(0, 3, 0.5f),
            Animation(0, 3, 0.5f),
            Animation(0, 3, 0.5f) },
            TileType::WATER, 0, 0, 1);
    tileAtlas["residential"] =
        Tile(this->tileSize, 2, texmgr.getRef("residential"),
            { staticAnim, staticAnim, staticAnim,
            staticAnim, staticAnim, staticAnim },
            TileType::RESIDENTIAL, 300, 50, 6);
    tileAtlas["commercial"] =
        Tile(this->tileSize, 2, texmgr.getRef("commercial"),
            { staticAnim, staticAnim, staticAnim, staticAnim},
            TileType::COMMERCIAL, 300, 50, 4);
    tileAtlas["industrial"] =
        Tile(this->tileSize, 2, texmgr.getRef("industrial"),
            { staticAnim, staticAnim, staticAnim,
            staticAnim },
            TileType::INDUSTRIAL, 300, 50, 4);
    tileAtlas["road"] =
        Tile(this->tileSize, 1, texmgr.getRef("road"),
            { staticAnim, staticAnim, staticAnim,
            staticAnim, staticAnim, staticAnim,
            staticAnim, staticAnim, staticAnim,
            staticAnim, staticAnim },
            TileType::ROAD, 100, 0, 1);

    return;
}

