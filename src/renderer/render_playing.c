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
}

void render_player(Game *game){
  SDL_FRect rect = {
    game->player.movement.x, game->player.movement.y, 50.0f, 50.0f
  };

  SDL_FRect rect2 = {
    game->player.movement.x + 32.0f, game->player.movement.y + 53.0f, 5.0f, 15.0f,
  };

  SDL_FRect rect3 = {
    game->player.movement.x + 13.0f, game->player.movement.y + 53.0f, 5.0f, 15.0f,
  };

  SDL_RenderTexture(
    game->renderer,
    assets.misc.bmp_file,
    &game->data_dynamic.current_emission_1,
    &rect3
  );

  SDL_RenderTexture(
    game->renderer,
    assets.misc.bmp_file,
    &game->data_dynamic.current_emission_2,
    &rect2
  );

  SDL_RenderTexture(
    game->renderer,
    assets.spaceship.bmp_file,
    &game->data_dynamic.current_player_rect,
    &rect
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
