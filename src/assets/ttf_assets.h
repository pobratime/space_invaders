#ifndef TTF_ASSETS_H
#define TTF_ASSETS_H

#include "SDL3/SDL.h"
#include "SDL3_ttf/SDL_ttf.h"

/**
 * Structure holding all text-related assets
 */
typedef struct {
  TTF_Font *font;          /* Main game font */

  /* Title textures */
  SDL_Texture *space;      /* "Space" part of the title */
  SDL_Texture *invaders;   /* "Invaders" part of the title */

  /* Player status */
  SDL_Texture *player_2_inactive; /* Indicator for inactive second player */

  /* Button labels */
  SDL_Texture *play;       /* Play button text */
  SDL_Texture *settings;   /* Settings button text */
  SDL_Texture *exit;       /* Exit button text */

  SDL_Texture *res_1680x1050;
  SDL_Texture *res_1280x800;
  SDL_Texture *res_1920x1080;

  SDL_Texture *settings_title;
  SDL_Texture *pause_title;

  SDL_Texture *music;
  SDL_Texture *sound;

  SDL_Texture *feedback;
  SDL_Texture *resume;
  SDL_Texture *paused;
  SDL_Texture *game;
  SDL_Texture *main_menu;

  SDL_Texture *return_button;

} TTF_assets;

/* Function declarations */
void load_ttf_assets(SDL_Renderer *renderer, TTF_assets *ttf);
void create_ttf_assets(SDL_Renderer *renderer, TTF_assets *ttf);

#endif /* TTF_ASSETS_H */
