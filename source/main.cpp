/*
    Author: Emirhan Gocturk
    Description: Advanium game engine 
        which belongs to Vaconia Entertainment
 */

#include "main.hpp"

/*
// Globals
// Window
SDL_Window* gWindow = NULL;
// Surface
SDL_Surface* gScreenSurface = NULL;
// Image to be laoded
SDL_Surface* gMarioWorld = NULL;
*/

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init()
{
  // init flag
  bool success = true;

  // init SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    logSystem::log("Failed to initialize SDL", 2);
  }
  else
  {

  }

  return success;
}

int main(int argc, char* args[])
{
  init();
  return 0;
}