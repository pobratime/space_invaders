#include "init.h"

// Basic game init function
int init_game_window_and_renderer(Game *game){

  // If any of these fail return 0
  if(!init_window(game) || !init_renderer(game)) return 0;

  return 1;
}

// Creating a game window
int init_window(Game *game){

  game->window = SDL_CreateWindow("Space Invaders", 1680.0f, 1050.0f, SDL_WINDOW_BORDERLESS);
  if(game->window == NULL){
    fprintf(stderr, "Error while creating a window: %s\n", SDL_GetError());
    return 0;
  }

  game->warning_window = SDL_CreateWindow("Warning!", 400.0f, 200.0f, SDL_WINDOW_POPUP_MENU);

  return 1;
}

// Creating a game renderer
int init_renderer(Game *game){

  game->renderer =  SDL_CreateRenderer(game->window, "");
  
  if(game->renderer == NULL){
    fprintf(stderr, "Error while creating a renderer: %s\n", SDL_GetError());
    return 0;
  }

  return 1;
}
