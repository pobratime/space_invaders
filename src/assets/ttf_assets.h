#ifndef TTF_ASSETS_H
#define TTF_ASSETS_H

#include "SDL3/SDL.h"
#include "SDL3_ttf/SDL_ttf.h"

typedef struct{
  TTF_Font *font;

  // Title
  SDL_Texture *space;
  SDL_Texture *invaders;

  // Buttons
  SDL_Texture *play;
  SDL_Texture *settings;
  SDL_Texture *exit;

}TTF_assets;

void load_ttf_assets(SDL_Renderer *renderer, TTF_assets *ttf);
void create_ttf_assets(SDL_Renderer *renderer, TTF_assets *ttf);

#endif
