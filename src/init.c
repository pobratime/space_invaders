#include "init.h"
#include "game.h"

int init_game(Game *game){
  if(!init_window(game) || !init_renderer(game)) return -1;
  return 1;
}

int init_window(Game *game){

  game->window = SDL_CreateWindow("Space Invaders", 800, 600, 0);
  if(game->window == NULL){
    fprintf(stderr, "Error while creating a window: %s\n", SDL_GetError());
    return -1;
  }

  return 1;
}

int init_renderer(Game *game){

  game->renderer =  SDL_CreateRenderer(game->window, "");
  if(game->renderer == NULL){
    fprintf(stderr, "Error while creating a renderer: %s\n", SDL_GetError());
    return -1;
  }

  return 1;
}
