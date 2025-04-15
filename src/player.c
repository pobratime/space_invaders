#include "player.h"
#include "sprite_map.h"
#include <SDL3/SDL.h>

int init_player(Player *player){
  
  player->steering_left_rect = sprite_map.player_steering_left_rect;
  player->steering_right_rect = sprite_map.player_steering_right_rect;
  player->normal_rect = sprite_map.player_normal_rect;
  player->current_rect = player->normal_rect;
  player->health_points = 3;
  player->score = 0;
  player->x = 400.0f;
  player->y = 500.0f;

  return 1;  
}
