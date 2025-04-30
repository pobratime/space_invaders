#include "ui_assets.h"
#include <stdio.h>

void load_ui_assets(SDL_Renderer *renderer, Ui_assets *ui){

  // TEMP LOADING WITH ABSOLUTE PATH
  SDL_Surface *ui_surface = SDL_LoadBMP("/Users/lukaajdukovic/Desktop/space_invaders/src/assets_bmp/ui.bmp");
  
  // loading with relative path TODO FIX LATER
  // SDL_Surface *ui_surface = SDL_LoadBMP("src/assets/ui.bmp");

  if(ui_surface == NULL)
    fprintf(stderr, "Error while loading a ui BMP file: %s\n", SDL_GetError());

  ui->bmp_file = SDL_CreateTextureFromSurface(renderer, ui_surface);
  if(ui->bmp_file == NULL)
    fprintf(stderr, "Error while creating a ui texture from a BMP file: %s\n", SDL_GetError());

  load_play_button_assets(ui);
  load_settings_button_assets(ui);
  load_exit_button_assets(ui);

  SDL_SetTextureScaleMode(ui->bmp_file, SDL_SCALEMODE_NEAREST);
  SDL_SetTextureBlendMode(ui->bmp_file, SDL_BLENDMODE_BLEND);

  SDL_DestroySurface(ui_surface);
}

void load_play_button_assets(Ui_assets *ui){
  SDL_FRect idle = {125.0f, 0.0f, 12.0f, 13.0f};
  SDL_FRect selected = {137.0f, 0.0f, 12.0f, 13.0f};
  SDL_FRect clicked = {149.0f, 1.0f, 12.0f, 11.0f};

  ui->play_button.idle = idle;
  ui->play_button.selected = selected;
  ui->play_button.clicked = clicked;
}


void load_settings_button_assets(Ui_assets *ui){
  SDL_FRect idle = {88.0f, 0.0f, 12.0f, 13.0f};
  SDL_FRect selected = {100.0f, 0.0f, 12.0f, 13.0f};
  SDL_FRect clicked = {112.0f, 1.0f, 12.0f, 11.0f};

  ui->settings_button.idle = idle;
  ui->settings_button.selected = selected;
  ui->settings_button.clicked = clicked;
}

void load_exit_button_assets(Ui_assets *ui){
  SDL_FRect idle = {88.0f, 28.0f, 12.0f, 13.0f};
  SDL_FRect selected = {100.0f, 28.0f, 12.0f, 13.0f};
  SDL_FRect clicked = {112.0f, 29.0f, 12.0f, 11.0f};

  ui->exit_button.idle = idle;
  ui->exit_button.selected = selected;
  ui->exit_button.clicked = clicked;
}
