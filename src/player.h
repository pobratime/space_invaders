#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3/SDL.h>

typedef struct{
  SDL_FRect current_rect;
  SDL_FRect normal_rect;
  SDL_FRect steering_left_rect;
  SDL_FRect steering_right_rect;
  float x, y;
  float health_points;
  float score;
}Player;

int init_player(Player *player);

#endif
