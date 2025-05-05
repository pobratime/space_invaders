#include "update_playing_state.h"
#include "SDL3/SDL.h"
#include "assets/assets.h"
#include "game/game_states.h"
#include "stdlib.h"

void handle_playing_state(Game *game, float delta_time, SDL_Scancode pressed_key){

  switch(pressed_key){
    case(SDL_SCANCODE_LEFT):{
      move_player_left(&game->player);
      break;
    }
    case(SDL_SCANCODE_RIGHT):{
      move_player_right(&game->player);
      break;
    }
    case(SDL_SCANCODE_SPACE):{
      break;
    }
    case(SDL_SCANCODE_CANCEL):{
      move_player_idle(&game->player);
      break;
    }
    case(SDL_SCANCODE_P):{
      game->data_dynamic.state = GAME_STATE_PAUSED;
      break;
    }
    default:{
      break;
    }
  }

  update_player_movement(game, delta_time);
  update_player_emission(game, delta_time);
}

void update_player_emission(Game *game, float delta_time){
  static float emission_timer = 0.0f;
  emission_timer += delta_time;

  if (emission_timer >= 0.2f) { // every 0.5 seconds
    int random_index = rand() % 4;

    switch (random_index) {
      case 0:
        game->data_dynamic.current_emission_1 = assets.misc.emission_ship_1.em_1;
        break;
      case 1:
        game->data_dynamic.current_emission_1 = assets.misc.emission_ship_1.em_2;
        break;
      case 2:
        game->data_dynamic.current_emission_1 = assets.misc.emission_ship_1.em_3;
        break;
      case 3:
        game->data_dynamic.current_emission_1 = assets.misc.emission_ship_1.em_4;
        break;
    }
  }
  if (emission_timer >= 0.2f) { // every 0.5 seconds
    int random_index = rand() % 4;

    switch (random_index) {
      case 0:
        game->data_dynamic.current_emission_2 = assets.misc.emission_ship_1.em_1;
        break;
      case 1:
        game->data_dynamic.current_emission_2 = assets.misc.emission_ship_1.em_2;
        break;
      case 2:
        game->data_dynamic.current_emission_2 = assets.misc.emission_ship_1.em_3;
        break;
      case 3:
        game->data_dynamic.current_emission_2 = assets.misc.emission_ship_1.em_4;
        break;
    }

    emission_timer = 0.0f;
  }
}
void update_player_movement(Game *game, float delta_time){
  game->player.movement.x += game->player.movement.velocity_x * delta_time;

  // implement player bouncing
  // if(game->player.movement.y > 650){
  //   game->player.movement.y -= 100.0f * delta_time;
  // }else if(game->player.movement.y >= 600){
  //   game->player.movement.y += 100.0f * delta_time;
  // }

  if(game->player.movement.velocity_x > 5.0f){
    game->data_dynamic.current_player_rect = assets.spaceship.spaceship_1.steering_right;
  }else if(game->player.movement.velocity_x < -5.0f){
    game->data_dynamic.current_player_rect = assets.spaceship.spaceship_1.steering_left;
  }else{
    game->data_dynamic.current_player_rect = assets.spaceship.spaceship_1.idle;
  }

  // Bound check to ensure player doesn't go off bounds
  if(game->player.movement.x < 280) game->player.movement.x = 280;
  if(game->player.movement.x > 1000) game->player.movement.x = 1000;
}

void move_player_left(Player *player){
  player->movement.velocity_x = -player->movement.max_speed;
}

void move_player_right(Player *player){
  player->movement.velocity_x = player->movement.max_speed;
}

void move_player_idle(Player *player){
  player->movement.velocity_x = 0.0f;
}
