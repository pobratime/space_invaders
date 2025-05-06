#ifndef UI_ASSETS_H
#define UI_ASSETS_H

#include "SDL3/SDL.h"

typedef struct{
  SDL_FRect checked;
  SDL_FRect idle;
  SDL_FRect selected;
  SDL_FRect selected_checked;
}Box;

typedef struct{
  SDL_FRect selected;
  SDL_FRect idle;
  SDL_FRect bar;
}Slider;

typedef struct{
  SDL_FRect selected;
  SDL_FRect idle;
  SDL_FRect clicked;
}Button;

typedef struct {
  SDL_Texture *bmp_file;   /* Primary UI texture */
  SDL_Texture *bmp_file_2; /* Secondary UI texture */

  SDL_FRect square_1;      /* First square asset */
  SDL_FRect square_2;      /* Second square asset */

  SDL_FRect board;         /* Main board asset */
  SDL_FRect board_side_l;  /* Left side of the board */
  SDL_FRect board_side_r;  /* Right side of the board */

  /* Button assets */
  Button exit_button;
  Button settings_button;
  Button play_button;
  Button feedback_button;
    
  Box box_1;
  Slider slider;
} Ui_assets;




/* Function declarations */
void load_ui_assets(SDL_Renderer *renderer, Ui_assets *ui);
void load_play_button_assets(Ui_assets *ui);
void load_settings_button_assets(Ui_assets *ui);
void load_exit_button_assets(Ui_assets *ui);
void load_square_assets(Ui_assets *ui);
void load_pilot_board(Ui_assets *ui);
void load_feedback_button_assets(Ui_assets *ui);


void load_box_1_checked(Ui_assets *ui);
void load_box_1_idle(Ui_assets *ui);
void load_box_1_selected(Ui_assets *ui);
void load_box_1_selected_checked(Ui_assets *ui);
void load_slider_selected(Ui_assets *ui);
void load_slider_idle(Ui_assets *ui);
void load_slider_bar(Ui_assets *ui);
#endif /* UI_ASSETS_H */
