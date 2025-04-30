#ifndef UI_ASSETS_H
#define UI_ASSETS_H

#include "SDL3/SDL.h"

typedef struct{
  SDL_FRect clicked;
  SDL_FRect selected;
  SDL_FRect idle;
}Play_button;

typedef struct{
  SDL_FRect clicked;
  SDL_FRect selected;
  SDL_FRect idle;
}Settings_button;

typedef struct{
  SDL_FRect clicked;
  SDL_FRect selected;
  SDL_FRect idle;
}Exit_button;

typedef struct{
  SDL_Texture *bmp_file;

  Exit_button exit_button;
  Settings_button settings_button;
  Play_button play_button;
}Ui_assets;

void load_ui_assets(SDL_Renderer *renderer, Ui_assets *ui);
void load_play_button_assets(Ui_assets *ui);
void load_settings_button_assets(Ui_assets *ui);
void load_exit_button_assets(Ui_assets *ui);

#endif
