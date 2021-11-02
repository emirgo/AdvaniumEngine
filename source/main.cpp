/*
    Author: Emirhan Gocturk
    Description: Advanium game engine 
        which belongs to Vaconia Entertainment
 */

#include "main.hpp"

#define ENGINE_NAME "Advanium Engine"
// Globals
// Window
SDL_Window* gWindow = NULL;
// Surface
SDL_Surface* gScreenSurface = NULL;
// Image to be laoded
SDL_Surface* gMarioWorld = NULL;

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
    logSystem::log("Failed to initialize SDL", status::code::ERROR);
  }
  else
  {
    logSystem::log("Initialized SDL", status::code::DEBUG);
    // create window
    gWindow = SDL_CreateWindow(ENGINE_NAME, SDL_WINDOWPOS_UNDEFINED, 
                SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
                SDL_WINDOW_OPENGL);

    if (gWindow == NULL)
    {
    }

  }

  return success;
}

int main(int argc, char* args[])
{
  init();
  return 0;
}