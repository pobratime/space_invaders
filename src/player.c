#include "player.h"
#include "sprite_map.h"
#include <SDL3/SDL.h>

// This function is used to intialize a starting settings for a player when player is created
void init_player(Player *player){

  // Loading player textures
  player->sprites.idle_rect = sprite_map.player_sprites.idle_rect;
  player->sprites.steering_left_rect = sprite_map.player_sprites.steering_left_rect;
  player->sprites.steering_right_rect = sprite_map.player_sprites.steering_right_rect;
  player->sprites.current_rect = player->sprites.idle_rect;

  // Setting bullet
  player->bullet.bullet_rect = sprite_map.player_sprites.bullet_rect;
  player->bullet.active = 0;

  // Setting player movement
  player->movement.x = 100;
  player->movement.y = 480;
  player->movement.acceleration = 1500.0f;
  player->movement.deacceleration = 2000.0f;
  player->movement.max_speed = 300.0f;
  player->movement.velocity_x = 0.0f;
 
  // Setting player data
  player->data.health_points = 3;
  player->data.score = 0;

}

// This function is used to have a smooth player movemment
// It uses delta_time to smooth out the movement animation transition when switich from left to right etc
void update_player_movement(Player *player, float delta){

  // Calcualting a new position of a player on x axis
  player->movement.x += player->movement.velocity_x * delta;

  // Bound check to ensure player doesn't go off bounds
  if(player->movement.x < 0) player->movement.x = 0;
  if(player->movement.x > 750) player->movement.x = 750;

  // Checking the player's velocity to determinate which texture is supposed to be used
  if(player->movement.velocity_x < -5.0f){
    player->sprites.current_rect = player->sprites.steering_left_rect;
  }else if(player->movement.velocity_x > 5.0f){
    player->sprites.current_rect = player->sprites.steering_right_rect;
  }else{
    player->sprites.current_rect = player->sprites.idle_rect;
  }
}

// FUNCTIONS BELOW ARE BASIC PLAYER FUNCTIONS WHICH CONTROL THE PLAYER'S BEHAVIOUR

void update_player_bullet(Player *player, float delta){
  if(!player->bullet.active) return;
  player->bullet.y -= 400.0f * delta;
  if(player->bullet.y <= 10) player->bullet.active = 0;
}

void player_move_left(Player *player){
  player->movement.velocity_x = -player->movement.max_speed;
  player->sprites.current_rect = player->sprites.steering_left_rect;
}

void player_move_right(Player *player){
  player->movement.velocity_x = player->movement.max_speed;
  player->sprites.current_rect = player->sprites.steering_right_rect;
}

void player_idle(Player *player){
  player->movement.velocity_x = 0.0f;
  player->sprites.current_rect = player->sprites.idle_rect;
}

void player_shoot(Player *player){
  player->bullet.active = 1;
  player->bullet.x = player->movement.x + 20;
  player->bullet.y = player->movement.y - 20;
  player->bullet.velocity_y = 10;
}
