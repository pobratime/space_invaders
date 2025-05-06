#include "ui_assets.h"
#include <stdio.h>

void load_ui_assets(SDL_Renderer *renderer, Ui_assets *ui) {
  /* Load the UI bitmaps */
  SDL_Surface *ui_surface = SDL_LoadBMP("/Users/lukaajdukovic/Desktop/space_invaders/src/assets_bmp/ui.bmp");
  SDL_Surface *ui_surface_2 = SDL_LoadBMP("/Users/lukaajdukovic/Desktop/space_invaders/src/assets_bmp/ui_2.bmp");

  /* Check if surfaces loaded correctly */
  if (ui_surface == NULL) {
    fprintf(stderr, "Error loading UI BMP file: %s\n", SDL_GetError());
    return;
  }
  
  if (ui_surface_2 == NULL) {
    fprintf(stderr, "Error loading UI 2 BMP file: %s\n", SDL_GetError());
    SDL_DestroySurface(ui_surface);  /* Clean up first surface if second fails */
    return;
  }

  /* Create textures from surfaces */
  ui->bmp_file = SDL_CreateTextureFromSurface(renderer, ui_surface);
  ui->bmp_file_2 = SDL_CreateTextureFromSurface(renderer, ui_surface_2);

  /* Check if textures created correctly */
  if (ui->bmp_file == NULL) {
    fprintf(stderr, "Error creating UI texture: %s\n", SDL_GetError());
    SDL_DestroySurface(ui_surface);
    SDL_DestroySurface(ui_surface_2);
    return;
  }
  
  if (ui->bmp_file_2 == NULL) {
    fprintf(stderr, "Error creating UI 2 texture: %s\n", SDL_GetError());
    SDL_DestroyTexture(ui->bmp_file);
    SDL_DestroySurface(ui_surface);
    SDL_DestroySurface(ui_surface_2);
    return;
  }

  /* Load all UI assets */
  load_play_button_assets(ui);
  load_settings_button_assets(ui);
  load_exit_button_assets(ui);
  load_square_assets(ui);
  load_pilot_board(ui);

  load_box_1_idle(ui);
  load_box_1_checked(ui);
  load_box_1_selected_checked(ui);
  load_box_1_selected(ui);

  load_slider_selected(ui);
  load_slider_idle(ui);
  load_slider_bar(ui);

  load_feedback_button_assets(ui);

  /* Configure texture properties */
  SDL_SetTextureScaleMode(ui->bmp_file, SDL_SCALEMODE_NEAREST);
  SDL_SetTextureBlendMode(ui->bmp_file, SDL_BLENDMODE_BLEND);

  SDL_SetTextureScaleMode(ui->bmp_file_2, SDL_SCALEMODE_NEAREST);
  SDL_SetTextureBlendMode(ui->bmp_file_2, SDL_BLENDMODE_BLEND);

  /* Clean up surfaces */
  SDL_DestroySurface(ui_surface);
  SDL_DestroySurface(ui_surface_2);
}

void load_pilot_board(Ui_assets *ui) {
  SDL_FRect board = {0.0f, 1.0f, 127.0f, 31.0f};
  ui->board = board;
}

void load_play_button_assets(Ui_assets *ui) {
  /* Define play button states */
  SDL_FRect idle = {125.0f, 0.0f, 12.0f, 13.0f};
  SDL_FRect selected = {137.0f, 0.0f, 12.0f, 13.0f};
  SDL_FRect clicked = {149.0f, 1.0f, 12.0f, 11.0f};

  /* Assign to structure */
  ui->play_button.idle = idle;
  ui->play_button.selected = selected;
  ui->play_button.clicked = clicked;
}

void load_settings_button_assets(Ui_assets *ui) {
  /* Define settings button states */
  SDL_FRect idle = {88.0f, 0.0f, 12.0f, 13.0f};
  SDL_FRect selected = {100.0f, 0.0f, 12.0f, 13.0f};
  SDL_FRect clicked = {112.0f, 1.0f, 12.0f, 11.0f};

  /* Assign to structure */
  ui->settings_button.idle = idle;
  ui->settings_button.selected = selected;
  ui->settings_button.clicked = clicked;
}

void load_exit_button_assets(Ui_assets *ui) {
  /* Define exit button states */
  SDL_FRect idle = {88.0f, 28.0f, 12.0f, 13.0f};
  SDL_FRect selected = {100.0f, 28.0f, 12.0f, 13.0f};
  SDL_FRect clicked = {112.0f, 29.0f, 12.0f, 11.0f};

  /* Assign to structure */
  ui->exit_button.idle = idle;
  ui->exit_button.selected = selected;
  ui->exit_button.clicked = clicked;
}

void load_feedback_button_assets(Ui_assets *ui){

  SDL_FRect idle = {125.0f, 14.0f, 12.0f, 13.0f};
  SDL_FRect selected = {137.0f, 14.0f, 12.0f, 13.0f};
  SDL_FRect clicked = {149.0f, 15.0f, 12.0f, 11.0f};

  ui->feedback_button.idle = idle;
  ui->feedback_button.selected = selected;
  ui->feedback_button.clicked = clicked;
}
void load_square_assets(Ui_assets *ui) {
  /* Define square assets */
  SDL_FRect rect_1 = {16.0f, 0.0f, 16.0f, 16.0f};
  SDL_FRect rect_2 = {0.0f, 0.0f, 16.0f, 16.0f};

  ui->square_1 = rect_1;
  ui->square_2 = rect_2;
}
void load_box_1_checked(Ui_assets *ui){
  SDL_FRect rect = {72.0f, 0.0f, 8.0f, 8.0f};
  ui->box_1.checked = rect;
}

void load_box_1_idle(Ui_assets *ui){
  SDL_FRect rect = {56.0f, 0.0f, 8.0f, 8.0f};
  ui->box_1.idle = rect;
}

void load_box_1_selected(Ui_assets *ui){
  SDL_FRect rect = {64.0f, 0.0f, 8.0f, 8.0f};
  ui->box_1.selected = rect;
}

void load_box_1_selected_checked(Ui_assets *ui){
  SDL_FRect rect = {80.0f, 0.0f, 8.0f, 8.0f};
  ui->box_1.selected_checked = rect;
}

void load_slider_selected(Ui_assets *ui){
  SDL_FRect rect = {50.0f, 25.0f, 5.0f, 7.0f};
  ui->slider.selected = rect;
}

void load_slider_idle(Ui_assets *ui){
  SDL_FRect rect = {50.0f, 16.0f, 5.0f, 7.0f};
  ui->slider.idle = rect;
}

void load_slider_bar(Ui_assets *ui){
  SDL_FRect rect = {32.0f, 9.0f, 24.0f, 8.0f};
  ui->slider.bar = rect;
}
