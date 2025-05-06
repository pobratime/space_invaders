#include "ttf_assets.h"
#include <stdio.h>

void load_ttf_assets(SDL_Renderer *renderer, TTF_assets *ttf) {
  /* Initialize SDL_ttf */
  if (TTF_Init() != 1) {
    fprintf(stderr, "Error initializing SDL_ttf: %s\n", SDL_GetError());
    return;
  }

  /* Load the font file */
  ttf->font = TTF_OpenFont("/Users/lukaajdukovic/Desktop/space_invaders/src/assets_bmp/font.ttf", 400);
  if (ttf->font == NULL) {
    fprintf(stderr, "Error loading font file: %s\n", SDL_GetError());
    return;
  }
  
  /* Create text textures */
  create_ttf_assets(renderer, ttf);
}

void create_ttf_assets(SDL_Renderer *renderer, TTF_assets *ttf) {
  /* Define text colors */
  SDL_Color white_text = {255, 255, 255, 190};
  SDL_Color hacker_green = {57, 255, 20, 190}; /* Neon lime green */
  
  /* Create title textures */
  SDL_Surface *space_surface = TTF_RenderText_Blended(ttf->font, "SPACE", 5 ,white_text);
  SDL_Surface *invaders_surface = TTF_RenderText_Blended(ttf->font, "INVADERS", 8, white_text);
  SDL_Surface *player_2_surface = TTF_RenderText_Blended(ttf->font, "Player 2 inactive", 17, hacker_green);
  SDL_Surface *res_1 = TTF_RenderText_Blended(ttf->font, "1680x1050", 9, white_text);
  SDL_Surface *res_2 = TTF_RenderText_Blended(ttf->font, "1280x800", 8, white_text);
  SDL_Surface *res_3 = TTF_RenderText_Blended(ttf->font, "1920x1080", 9, white_text);
  SDL_Surface *music = TTF_RenderText_Blended(ttf->font, "Music", 5, white_text);
  SDL_Surface *sound = TTF_RenderText_Blended(ttf->font, "Sound", 5, white_text);
  SDL_Surface *settings = TTF_RenderText_Blended(ttf->font, "SETTINGS", 8, white_text);
  SDL_Surface *pause = TTF_RenderText_Blended(ttf->font, "PAUSED", 6, white_text);
  SDL_Surface *return_button = TTF_RenderText_Blended(ttf->font, "RETURN", 6, white_text);
  SDL_Surface *play = TTF_RenderText_Blended(ttf->font, "PLAY", 4, white_text);
  SDL_Surface *exit = TTF_RenderText_Blended(ttf->font, "EXIT", 4, white_text);
  SDL_Surface *feedback = TTF_RenderText_Blended(ttf->font, "ISSUES", 6, white_text);
  SDL_Surface *game = TTF_RenderText_Blended(ttf->font, "GAME", 4, white_text);
  SDL_Surface *paused = TTF_RenderText_Blended(ttf->font, "PAUSED", 6, white_text);
  SDL_Surface *resume = TTF_RenderText_Blended(ttf->font, "RESUME", 6, white_text);
  SDL_Surface *main_menu = TTF_RenderText_Blended(ttf->font, "MAIN MENU", 9, white_text);

  /* Check if surfaces were created successfully */
  if (!space_surface || !invaders_surface || !player_2_surface) {
    fprintf(stderr, "Error creating text surfaces: %s\n", SDL_GetError());
    /* Clean up any surfaces that were successfully created */
    if (space_surface) SDL_DestroySurface(space_surface);
    if (invaders_surface) SDL_DestroySurface(invaders_surface);
    if (player_2_surface) SDL_DestroySurface(player_2_surface);
    return;
  }
  
  /* Create textures from surfaces */
  ttf->space = SDL_CreateTextureFromSurface(renderer, space_surface);
  ttf->invaders = SDL_CreateTextureFromSurface(renderer, invaders_surface);
  ttf->player_2_inactive = SDL_CreateTextureFromSurface(renderer, player_2_surface);
  ttf->res_1680x1050 = SDL_CreateTextureFromSurface(renderer, res_1);
  ttf->res_1280x800 = SDL_CreateTextureFromSurface(renderer, res_2);
  ttf->res_1920x1080 = SDL_CreateTextureFromSurface(renderer, res_3);
  ttf->music = SDL_CreateTextureFromSurface(renderer, music);
  ttf->sound = SDL_CreateTextureFromSurface(renderer, sound);
  ttf->settings_title = SDL_CreateTextureFromSurface(renderer, settings);
  ttf->pause_title = SDL_CreateTextureFromSurface(renderer, pause);
  ttf->return_button = SDL_CreateTextureFromSurface(renderer, return_button);
  ttf->play = SDL_CreateTextureFromSurface(renderer, play);
  ttf->exit = SDL_CreateTextureFromSurface(renderer, exit);
  ttf->feedback = SDL_CreateTextureFromSurface(renderer, feedback);
  ttf->game = SDL_CreateTextureFromSurface(renderer, game);
  ttf->paused = SDL_CreateTextureFromSurface(renderer, paused);
  ttf->resume = SDL_CreateTextureFromSurface(renderer, resume);
  ttf->main_menu = SDL_CreateTextureFromSurface(renderer, main_menu);

  /* Check if textures were created successfully */
  if (!ttf->space || !ttf->invaders || !ttf->player_2_inactive) {
    fprintf(stderr, "Error creating text textures: %s\n", SDL_GetError());
  }
  
  /* Clean up surfaces */
  SDL_DestroySurface(space_surface);
  SDL_DestroySurface(invaders_surface);
  SDL_DestroySurface(player_2_surface);
  SDL_DestroySurface(res_1);
  SDL_DestroySurface(res_2);
  SDL_DestroySurface(res_3);
}
