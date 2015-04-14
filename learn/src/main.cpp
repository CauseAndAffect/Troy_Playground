// Local Headers
#include <Game.hpp>
#include <GameStateStart.hpp>

int main()
{
  // Instantiate the game instance
  Game causeAndAffect;
  
  causeAndAffect.pushState(new GameStateStart(&game));
  causeAndAffect.gameLoop();
  
  return 0;
}
