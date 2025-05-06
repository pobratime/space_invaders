#include "render_playing.h"
#include "assets/assets.h"
#include "stdlib.h"
#include "math.h"

void render_playing(Game *game){
  // now we render the spicifc parts that are used while the game is being played
  // its importan that we pass the game here so that we can keep the game state
  // also its important that we pass the game here and in the other files to achive scaling with cur_res

  // PLAYER
  render_player(game);
  render_player_bullets(game);
  
  // ENEMIES
  render_enemies(game);
  render_enemy_bullets(game);

  // UI
  render_ui_elements(game);
  render_board_computer(game);
}

void render_player(Game *game){  
  float scale_x = game->options_data.x_scale; 
  float scale_y = game->options_data.y_scale;

  SDL_FRect rect = {
    game->player.movement.x * scale_x, game->player.movement.y * scale_y, 60.0f * scale_x, 60.0f * scale_y
  };

  SDL_FRect rect2 = {
    game->player.movement.x * scale_x + 20.0f * scale_x, game->player.movement.y * scale_y + 66.0f * scale_y, 20.0f * scale_x, 40.0f * scale_y,
  };

  switch(game->player.data.current_emission_int){
    case(1):{
      rect2.h = 20.0f * scale_y;
      break;
    }
    case(2):{
      rect2.h = 30.0f * scale_y;
      break; 
    }
    case(3):{
      rect2.h = 40.0f * scale_y;
      break;
    }
  }
  
  if(game->player.movement.velocity_x != 0){
    rect.w = 40.0f * scale_x; 
    rect2.x = game->player.movement.x * scale_y + 13 * scale_y; 
  }

  SDL_RenderTexture(
    game->renderer,
    assets.misc.bmp_file_2,
    &game->player.data.current_emission_rect,
    &rect2
  );

  SDL_RenderTexture(
    game->renderer,
    assets.spaceship.bmp_file_2,
    &game->player.data.current_player_rect,
    &rect
  );
}

void render_board_computer(Game *game){
  float scale_x = game->options_data.x_scale; 
  float scale_y = game->options_data.y_scale;
  
  SDL_FRect rect = {
    0.0f * scale_x, 800.0f * scale_y, 840.0f * scale_x, 200.0f * scale_y
  };
  SDL_FRect rect_2 = {
    840.0f * scale_x, 800.0f * scale_y, 840.0f * scale_x, 200.0f * scale_y
  };

  SDL_RenderTexture(
    game->renderer,
    assets.ui.bmp_file_2,
    &assets.ui.board,
    &rect
  );

  SDL_RenderTexture(
    game->renderer,
    assets.ui.bmp_file_2,
    &assets.ui.board,
    &rect_2
  );

  SDL_FRect inactive = {
    1000.0f * scale_x, 840.0f * scale_y, 475.0f * scale_x, 100.0f * scale_y
  };

  SDL_RenderTexture(
    game->renderer,
    assets.ttf.player_2_inactive,
    NULL,
    &inactive
  );
}

void render_player_bullets(Game *game){

}

void render_enemies(Game *game){

}

void render_enemy_bullets(Game *game){

}

void render_ui_elements(Game *game){

}

void render_scoreboard(Game *game){

}

void render_health_bar(Game *game){

}
