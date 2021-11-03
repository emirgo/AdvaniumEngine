/*
    Author: Emirhan Gocturk
    Description: Advanium game engine 
        which belongs to Vaconia Entertainment
 */

#include "main.hpp"

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
      logSystem::log("Failed to create window", status::code::ERROR);
      logSystem::log(SDL_GetError(), status::code::ERROR);
      success = false;
    }
    else
    {
      // get window surface
      gScreenSurface = SDL_GetWindowSurface(gWindow);
    }

  }

  return success;
}

void close()
{
  //deallocate surface
  SDL_FreeSurface(gMarioWorld);
  gMarioWorld = NULL;
  logSystem::log("Deallocate surface", status::code::DEBUG);
  
  // destroy window
  SDL_DestroyWindow(gWindow);
  gWindow = NULL;
  logSystem::log("Deallocate surface", status::code::DEBUG);

  // quit SDL
  SDL_Quit();
  logSystem::log("Quit SDL", status::code::DEBUG);
}

int main(int argc, char* args[])
{
  if (!init())
  {
    logSystem::log("Failed to initialize", status::code::ERROR);
  }
  else
  {
    // load media
    // apply the image to the surface
    // update window surface
    // wait
  }

  // free resources and close SDL
  close();

  return 0;
}