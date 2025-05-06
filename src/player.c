#include "player.h"
#include <SDL3/SDL.h>
#include "assets/assets.h"

// This function is used to intialize a starting settings for a player when player is created
void init_player(Player *player){

  // Setting bullet
  player->bullet.active = 0;

  // Setting player movement
  player->movement.x = 825;
  player->movement.y = 680;
  player->movement.acceleration = 1500.0f;
  player->movement.deacceleration = 2000.0f;
  player->movement.max_speed = 400.0f;
  player->movement.velocity_x = 0.0f;
 
  // Setting player data
  player->data.health_points = 3;
  player->data.score = 0;

  player->data.current_player_rect = assets.spaceship.spaceship_1.idle;
  player->data.current_emission_rect = assets.misc.emission_ship_1.em_1;
  player->data.current_emission_int = 1;

}

// This function is used to have a smooth player movemment
// It uses delta_time to smooth out the movement animation transition when switich from left to right etc


// FUNCTIONS BELOW ARE BASIC PLAYER FUNCTIONS WHICH CONTROL THE PLAYER'S BEHAVIOUR

void update_player_bullet(Player *player, float delta){
  if(!player->bullet.active) return;
  player->bullet.y -= 400.0f * delta;
  if(player->bullet.y <= 10) player->bullet.active = 0;
}

void player_move_left(Player *player){
  player->movement.velocity_x = -player->movement.max_speed;
  // game->data.current_player_rect = assets.spaceship.spaceship_1.steering_left;
}

void player_move_right(Player *player){
  player->movement.velocity_x = player->movement.max_speed;
  // current_player_rect = assets.spaceship.spaceship_1.steering_right;
}

void player_idle(Player *player){
  player->movement.velocity_x = 0.0f;
  // current_player_rect = assets.spaceship.spaceship_1.idle;
}

void player_shoot(Player *player){
  player->bullet.active = 1;
  player->bullet.x = player->movement.x + 20;
  player->bullet.y = player->movement.y - 20;
}
