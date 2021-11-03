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
SDL_Surface* gHelloWorld = NULL;

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

bool loadMedia()
{
    // load success flag
    bool success = true;

    // load splash image
    gHelloWorld = SDL_LoadBMP("logo.bmp");
    if (gHelloWorld == NULL)
    {
        logSystem::log(("Unable to load image"), 
                        status::code::ERROR);
        logSystem::log(SDL_GetError(), status::code::ERROR);
        success = false;
    }

    return success;
}

void close()
{
  //deallocate surface
  SDL_FreeSurface(gHelloWorld);
  gHelloWorld = NULL;
  logSystem::log("Deallocate surface", status::code::DEBUG);
  
  // destroy window
  SDL_DestroyWindow(gWindow);
  gWindow = NULL;
  logSystem::log("Deallocate window", status::code::DEBUG);

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
    if (!loadMedia())
    {
        logSystem::log("Failed to load media", status::code::ERROR);
    }
    else
    {
        
        bool isRunning = true;
        SDL_Event event;
        while (isRunning)
        {
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    isRunning = false;
                }
            }

            // apply the image
            SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
            // update the surface
            SDL_UpdateWindowSurface(gWindow);
        }
    }
  }

  // free resources and close SDL
  close();

  return 0;
}