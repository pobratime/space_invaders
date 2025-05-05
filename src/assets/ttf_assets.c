#include "ttf_assets.h"

void load_ttf_assets(SDL_Renderer *renderer, TTF_assets *ttf){

  if (TTF_Init() == -1) {
    fprintf(stderr, "Error initializing SDL_ttf: %s\n", SDL_GetError());
    return;
}

  ttf->font = TTF_OpenFont("/Users/lukaajdukovic/Desktop/space_invaders/src/assets_bmp/font.ttf", 400);
  if(ttf->font == NULL){
    fprintf(stderr, "Error while loading a font ttf file: %s\n", SDL_GetError());
  }
  create_ttf_assets(renderer, ttf);
}

void create_ttf_assets(SDL_Renderer *renderer, TTF_assets *ttf){
  SDL_Color text_color = {255.0f, 255.0f, 255.0f, 190.0f};
  SDL_Surface *space_surface = TTF_RenderText_Blended(ttf->font, "Space", 5, text_color);
  ttf->space = SDL_CreateTextureFromSurface(renderer, space_surface);
  SDL_Surface *invaders_surface = TTF_RenderText_Blended(ttf->font, "Invaders", 8, text_color);
  ttf->invaders = SDL_CreateTextureFromSurface(renderer, invaders_surface);

  SDL_DestroySurface(space_surface);
  SDL_DestroySurface(invaders_surface);
}
