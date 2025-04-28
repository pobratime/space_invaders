#include "game.h"
#include "init.h"
#include "player.h"
#include "renderer.h"
#include "sprite_map.h"
#include "execution.h"
#include "level.h"
#include <stdlib.h>

void start_game(void){

  // creating a game instance with a check if game was succefuly created
  Game game;
  if (!init_game(&game)) {
    shut_down_game(&game);
    return;
  }

  // loading assets
  if(!load_assets(game.renderer)){
    shut_down_game(&game);
    return;
  }
  // creating a player instance
  init_player(&game.player);

  init_level_1();
  game.current_level = level_1;

  // running a main game loop
  game_loop(&game);
}

// Main game loop
void game_loop(Game *game) {
  SDL_Event event;
  int running = 1;

  Uint64 previous_time = SDL_GetTicks();
  Uint64 current_time;
  float delta_time;

  while (running) {

      current_time = SDL_GetTicks();
      delta_time = (current_time - previous_time) / 1000.0f;
      previous_time = current_time;

      while (SDL_PollEvent(&event)) {
          if (event.type == SDL_EVENT_QUIT) {
              running = 0;
          }else if(event.type == SDL_EVENT_KEY_DOWN){
            SDL_Keycode keycode = SDL_GetKeyFromScancode(event.key.scancode, event.key.mod, false);
            switch(keycode){
              case(SDLK_LEFT):
                player_move_left(&game->player);  
                break;
              case(SDLK_RIGHT):
                player_move_right(&game->player);
              case(SDLK_SPACE):
                break;
              default:
                break;
            }
          }else if(event.type == SDL_EVENT_KEY_UP){
            player_idle(&game->player);
          }
      }
      
      if(!game->player.bullet.active) player_shoot(&game->player);
      update_background(delta_time);
      update_player_bullet(&game->player, delta_time);
      update_player_movement(&game->player, delta_time);
      update_level_enemies_movement(&game->current_level, delta_time);

      SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
      SDL_RenderClear(game->renderer);

      render_game(game);

      SDL_RenderPresent(game->renderer);
      SDL_Delay(16);
  }
  shut_down_game(game);
}

// Update backgound function which ensures that the background animations is working
void update_background(float delta){

  sprite_map.background.y_level += sprite_map.background.scroll_speed * delta;
  if(sprite_map.background.y_level >= 600.0f){
    sprite_map.background.y_level = 0.0f;
  }
}


void shut_down_game(Game *game){
  if(game->window) SDL_DestroyWindow(game->window);
  if(game->renderer) SDL_DestroyRenderer(game->renderer);
  if(sprite_map.background.texture) SDL_DestroyTexture(sprite_map.background.texture);
  if(sprite_map.spritesheet) SDL_DestroyTexture(sprite_map.spritesheet);
}
