#include "update_playing_state.h"
#include "SDL3/SDL.h"
#include "assets/assets.h"
#include "game/game_states.h"
#include "stdlib.h"
#include "game/update/update_audio.h"

static float bullet_cooldown = 0.0f;
void handle_playing_state(Game *game, float delta_time, bool key_states[]){



    if(key_states[SDL_SCANCODE_LEFT]){
      move_player_left(&game->player);
    }

    if(key_states[SDL_SCANCODE_RIGHT]){
      move_player_right(&game->player);
    }

    if(key_states[SDL_SCANCODE_SPACE]){
      player_shoot(game, delta_time);
    }

    if(!key_states[SDL_SCANCODE_LEFT] && !key_states[SDL_SCANCODE_RIGHT]){
      move_player_idle(&game->player);
    }

    if(key_states[SDL_SCANCODE_P]){
      play_button_clicked_sound(game, delta_time);
      move_player_idle(&game->player);
      game->options_data.current_button = 0;
      game->data_dynamic.state = GAME_STATE_PAUSED;
    }
  
    update_player_movement(game, delta_time);
    update_player_emission(game, delta_time);
    update_player_bullets(game, delta_time);
}

void update_player_bullets(Game *game, float delta_time){

  bullet_cooldown += delta_time;
  for(int i = 0; i < 10; i++){
    if(game->player.bullets[i].active == 1){
      game->player.bullets[i].y -= 10.0f * game->options_data.y_scale; 
    }
    if(game->player.bullets[i].y <= 3.0f * game->options_data.y_scale){
      game->player.bullets[i].active = 0;
    }
  }
}

void player_shoot(Game *game, float delta_time) {
  
  // SDL_Log("function etnered %f\n", bullet_cooldown);
  // Fixed the extra semicolon after the if statement
  if(bullet_cooldown > 0.4f) {
    // Try to find an inactive bullet
    int bullet_found = 0;
    for(int i = 0; i < 10; i++) {
      if(game->player.bullets[i].active == 0) {
        // Activate the bullet

        game->player.bullets[i].active = 1;
        game->player.bullets[i].x = game->player.movement.x * game->options_data.x_scale;
        game->player.bullets[i].y = game->player.movement.y * game->options_data.y_scale;
        game->player.bullets[i].bullet_rect = assets.projectile.bullet_1;
        
        // Set bullet velocity/direction
        // SDL_Log("bullet shot %d %d\n", i, game->player.bullets[i].active);
        bullet_found = 1;
        break;
      }
    }
    
    // Only reset cooldown if a bullet was actually fired
    if (bullet_found) {
      bullet_cooldown = 0.0f;
      
      // Play bullet sound effect
      play_bullet_sound(game, delta_time);
    }
  }
}

void update_player_emission(Game *game, float delta_time){
  static float emission_timer = 0.0f;
  emission_timer += delta_time;

  if (emission_timer >= 0.25f) { // every 0.3 seconds

    switch (game->player.data.current_emission_int) {
      case (3):{
        game->player.data.current_emission_rect = assets.misc.emission_ship_1.em_1;
        game->player.data.current_emission_int = 1;
        break;
      }
      case (1):{
        game->player.data.current_emission_rect = assets.misc.emission_ship_1.em_2;
        game->player.data.current_emission_int = 2;
        break;
      }
      case (2):{
        game->player.data.current_emission_rect = assets.misc.emission_ship_1.em_3;
        game->player.data.current_emission_int = 3;
        break;
      }
    }

    emission_timer = 0.0f;
  }
}
void update_player_movement(Game *game, float delta_time){
  game->player.movement.x += game->player.movement.velocity_x * delta_time;

  // !!!
  // TODO DONT FORGET
  // !!!

  // implement player bouncing
  // if(game->player.movement.y > 650){
  //   game->player.movement.y -= 100.0f * delta_time;
  // }else if(game->player.movement.y >= 600){
  //   game->player.movement.y += 100.0f * delta_time;
  // }

  if(game->player.movement.velocity_x > 5.0f){
    game->player.data.current_player_rect = assets.spaceship.spaceship_1.steering_right;
  }else if(game->player.movement.velocity_x < -5.0f){
    game->player.data.current_player_rect = assets.spaceship.spaceship_1.steering_left;
  }else{
    game->player.data.current_player_rect = assets.spaceship.spaceship_1.idle;
  }

  // Bound check to ensure player doesn't go off bounds
  if(game->player.movement.x < 100) game->player.movement.x = 100;
  if(game->player.movement.x > 1550) game->player.movement.x = 1550;
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
