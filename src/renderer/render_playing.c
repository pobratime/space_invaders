#include "render_playing.h"
#include "assets/assets.h"
#include "stdlib.h"
#include "SDL3_ttf/SDL_ttf.h"
#include "stdlib.h"

void render_playing(Game *game){
  // now we render the spicifc parts that are used while the game is being played
  // its importan that we pass the game here so that we can keep the game state
  // also its important that we pass the game here and in the other files to achive scaling with cur_res

  // PLAYER
  render_player(game);
  render_player_bullets(game);
  
  // UI
  render_ui_elements(game);
  render_board_computer(game);

  render_player_1_stats(game);
  render_player_bullets(game);
}

void render_player_bullets(Game *game){
  float scale_x = game->options_data.x_scale; 
  float scale_y = game->options_data.y_scale;

  for(int i = 0; i < 10; i++){
    if(game->player.bullets[i].active == 1){
      SDL_FRect rect = {
        game->player.bullets[i].x + 20.0f * scale_x, game->player.bullets[i].y + 10.0f * scale_y, 20.0f * scale_x, 20.0f * scale_y
      };
      SDL_RenderTexture(
        game->renderer,
        assets.projectile.bmp_file,
        &assets.projectile.bullet_1,
        &rect
      );
    }
  }
}

void render_player_1_stats(Game *game){


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


  SDL_RenderTexture(
    game->renderer,
    assets.ui.bmp_file_2,
    &assets.ui.board,
    &rect
  );

  SDL_FRect health_indicator = {
    rect.x + 170.0f * scale_x, rect.y + rect.h / 4.0f + 10.0f * scale_y, 30.0f * scale_x, 30.0f * scale_y
  };

  SDL_RenderTexture(
    game->renderer,
    assets.ui.bmp_file_3,
    &assets.ui.board_computer_parts.health,
    &health_indicator
  );

  SDL_FRect score_indicator = {
    health_indicator.x, health_indicator.y + rect.h / 4.0f, 30.0f * scale_x, 30.0f * scale_y
  };

  SDL_RenderTexture(
    game->renderer,
    assets.ui.bmp_file_3,
    &assets.ui.board_computer_parts.score,
    &score_indicator
  );

  float dx = 30.0f;
  for(int i = 0; i < game->player.data.health_points; i++){
    SDL_FRect health_point = {
      health_indicator.x + 20.0f * scale_x + dx * scale_x, health_indicator.y + health_indicator.h / 5.0f, 20.0f * scale_x, 20.0f * scale_y
    };
    SDL_RenderTexture(
      game->renderer,
      assets.ui.bmp_file_3,
      &assets.ui.board_computer_parts.health_point,
      &health_point
    );
    dx += 30.0f;
  }

  SDL_FRect score_points = {
    score_indicator.x + 50.0f * scale_x, score_indicator.y - 5.0f * scale_y, 150.0f * scale_x, 30.0f * scale_y
  };
  SDL_Color hacker_green = {57, 255, 20, 190}; /* Neon lime green */

  // TODO RENDER BIGGER NUMBERS
  char *score;
  score = malloc(sizeof(char) * 6);
  int tmp_score = (int)game->player.data.score;
  for(int i = 5; i > -1; i--){
    score[i] = ((tmp_score % 10) + '0');
    tmp_score /= 10;
  }

  SDL_Surface *score_text = TTF_RenderText_Blended(assets.ttf.font, score, 6, hacker_green);
  SDL_Texture *score_texture = SDL_CreateTextureFromSurface(game->renderer, score_text);
  SDL_DestroySurface(score_text);
  SDL_RenderTexture(
    game->renderer, 
    score_texture, 
    NULL, 
    &score_points
  );

  // TODO ABILITIES

  // PLAYER 2 BOARD COMPUTER
  // TODO WHEN ADDING 2nd PLAYER

  SDL_FRect rect_2 = {
    840.0f * scale_x, 800.0f * scale_y, 840.0f * scale_x, 200.0f * scale_y
  };

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

void render_ui_elements(Game *game){

}

void render_scoreboard(Game *game){

}

void render_health_bar(Game *game){

}
