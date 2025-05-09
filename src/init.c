#include "init.h"
#include "assets/assets.h"

// Basic game init function
void init_game_window_and_renderer(Game *game){

  // If any of these fail return 0
  init_window(game);
  init_renderer(game);
}

void init_audio(Game *game){
  if(SDL_Init(SDL_INIT_AUDIO) < 0){  // Fixed logic - SDL_Init returns 0 on success
    game->running = 0;
    SDL_Log("Error while audio init: %s\n", SDL_GetError());
  }
}

// Creating a game window
void init_window(Game *game){

  if(SDL_Init(SDL_INIT_VIDEO) < 0){  // Fixed logic here too
    game->running = 0;
    SDL_Log("Error while window init: %s\n", SDL_GetError());
  };

  game->window = SDL_CreateWindow("Space Invaders", 1680.0f, 1050.0f, SDL_WINDOW_BORDERLESS);
  if(game->window == NULL){
    game->running = 0;
    SDL_Log("Error while creating a window: %s\n", SDL_GetError());
  }

  game->warning_window = SDL_CreateWindow("Warning!", 400.0f, 200.0f, SDL_WINDOW_POPUP_MENU);
}

// Creating a game renderer
void init_renderer(Game *game){

  game->renderer =  SDL_CreateRenderer(game->window, "");
  
  if(game->renderer == NULL){
    game->running = 0;
    SDL_Log("Error while creating a renderer: %s\n", SDL_GetError());
  }
}
