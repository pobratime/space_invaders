#include "render_options.h"
#include "assets/assets.h"

void render_options(Game *game){

  // render_music_settings();
  // render_soung_settings();
  render_title_options(game);
  render_resolution_settings(game);
  render_sound_settings(game);
  render_return_button(game);
}

void render_return_button(Game *game){
  float scale_x = game->options_data.x_scale; 
  float scale_y = game->options_data.y_scale;

  SDL_FRect rect = {
    540.0f * scale_x, 900.0f * scale_y, 400.0f * scale_x, 100.0f * scale_y
  };

  SDL_FRect rect_1 = {
    rect.x + 450.0f * scale_x, rect.y, 100.0f * scale_x, 100.0f * scale_y
  };

  SDL_RenderTexture(
    game->renderer,
    assets.ttf.return_button,
    NULL,
    &rect
  );  

  SDL_RenderTexture(
    game->renderer,
    assets.ui.bmp_file,
    &game->options_data.cur_exit,
    &rect_1
  );
}

void render_title_options(Game *game){
  float scale_x = game->options_data.x_scale; 
  float scale_y = game->options_data.y_scale;

  SDL_FRect rect = {
    540.0f * scale_x, 100.0f * scale_y, 600.0f * scale_x, 200 * scale_y
  };

  SDL_RenderTexture(
    game->renderer,
    assets.ttf.settings_title,
    NULL,
    &rect
  );
}

void render_resolution_settings(Game *game){

  float scale_x = game->options_data.x_scale; 
  float scale_y = game->options_data.y_scale;

  SDL_FRect rect_1 = {
    1040.0f * scale_x, 400.0f * scale_y, 300.0f * scale_x, 100.0f * scale_y
  };
  SDL_FRect rect_2 = {
    1040.0f * scale_x, 550.0f * scale_y, 300.0f * scale_x, 100.0f * scale_y
  };
  SDL_FRect rect_3 = {
    1040.0f * scale_x, 700.0f * scale_y, 300.0f * scale_x, 100.0f * scale_y
  };

  SDL_RenderTexture(
    game->renderer,
    assets.ttf.res_1280x800,
    NULL,
    &rect_3
  );  
  
  SDL_RenderTexture(
    game->renderer,
    assets.ttf.res_1680x1050,
    NULL,
    &rect_2
  );  
  
  SDL_RenderTexture(
    game->renderer,
    assets.ttf.res_1920x1080,
    NULL,
    &rect_1
  );

  SDL_FRect rect_1_1 = {
    rect_1.x + rect_1.w + 50.0f * scale_x,
    rect_1.y,
    100.0f * scale_x,
    100.0f * scale_y
  };
  SDL_FRect rect_2_1 = {
    rect_2.x + rect_2.w + 50.0f * scale_x,
    rect_2.y,
    100.0f * scale_x,
    100.0f * scale_y
  };

  SDL_FRect rect_3_1 = {
    rect_3.x + rect_3.w + 50.0f * scale_x,
    rect_3.y,
    100.0f * scale_x,
    100.0f * scale_y
  };
  
  SDL_RenderTexture(
    game->renderer,
    assets.ui.bmp_file,
    &game->options_data.cur_1920x1080,
    &rect_1_1
  );
  SDL_RenderTexture(
    game->renderer,
    assets.ui.bmp_file,
    &game->options_data.cur_1680x1050,
    &rect_2_1
  );  
  SDL_RenderTexture(
    game->renderer,
    assets.ui.bmp_file,
    &game->options_data.cur_1280x800,
    &rect_3_1
  );
}

void render_sound_settings(Game *game){
  float scale_x = game->options_data.x_scale; 
  float scale_y = game->options_data.y_scale;

  SDL_FRect music = {
    150.0f * scale_x, 650.0f * scale_y, 300.0f * scale_x, 100.0f * scale_y
  };
  SDL_FRect sound = {
    150.0f * scale_x, 450.0f * scale_y, 300.0f * scale_x, 100.0f * scale_y
  };

  SDL_RenderTexture(
    game->renderer,
    assets.ttf.sound,
    NULL,
    &sound
  );
  SDL_RenderTexture(
    game->renderer,
    assets.ttf.music,
    NULL,
    &music
  );
  SDL_FRect sound_bar = {
    sound.x + sound.w + 50.0f * scale_x, sound.y + sound.h / 2.0f, 330.0f * scale_x, 50.0f * scale_y
  };
  SDL_FRect music_bar = {
    music.x + music.w + 50.0f * scale_x, music.y + music.h / 2.0f, 330.0f * scale_x, 50.0f * scale_y
  };
  SDL_FRect sound_slider = {
    sound_bar.x + game->options_data.sound_level * 30.0f * scale_x, sound_bar.y - sound_bar.h / 2.0f, 30.0f * scale_x, 70.0f * scale_y 
  };
  SDL_FRect music_slider = {
    music_bar.x + game->options_data.music_level * 30.0f * scale_x, music_bar.y - music_bar.h / 2.0f, 30.0f * scale_x, 70.0f * scale_y 
  };


  SDL_RenderTexture(
    game->renderer,
    assets.ui.bmp_file,
    &assets.ui.slider.bar,
    &sound_bar
  ); 
  SDL_RenderTexture(
    game->renderer,
    assets.ui.bmp_file,
    &assets.ui.slider.bar,
    &music_bar
  );
 
  SDL_RenderTexture(
    game->renderer,
    assets.ui.bmp_file,
    &game->options_data.cur_sound,
    &sound_slider
  ); 
  SDL_RenderTexture(
    game->renderer,
    assets.ui.bmp_file,
    &game->options_data.cur_music,
    &music_slider
  );
}
