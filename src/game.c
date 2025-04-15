#include "game.h"
#include "init.h"
#include "player.h"
#include "renderer.h"
#include "sprite_map.h"
#include "level.h"

void start_game(void){
  Game game;
  if (init_game(&game) == -1) {
      return;
  }
  init_spritesheet(game.renderer);
  generate_level_1();
  game.current_level = *level_list.level_1;
  init_player(&game.player);
  game_loop(&game);
}

void game_loop(Game *game) {
  SDL_Event event;
  int running = 1;
  while (running) {
      while (SDL_PollEvent(&event)) {
          if (event.type == SDL_EVENT_QUIT) {
              running = 0;
          }else if(event.type == SDL_EVENT_KEY_DOWN){
            SDL_Keycode keycode = SDL_GetKeyFromScancode(event.key.scancode, event.key.mod, false);
            switch(keycode){
              case(SDLK_LEFT):
                game->player.x -= 10.0f;
                game->player.current_rect = game->player.steering_left_rect;
                break;
              case(SDLK_RIGHT):
                game->player.x += 10.0f;
                game->player.current_rect = game->player.steering_right_rect;
                break;
              case(SDLK_SPACE):
                break;
            }
          }else if(event.type == SDL_EVENT_KEY_UP){
            game->player.current_rect = game->player.normal_rect;
          }
      }
      SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
      SDL_RenderClear(game->renderer);

      render_game(game);

      SDL_RenderPresent(game->renderer);
      SDL_Delay(16);
  }
  shut_down_game(game);
}


void shut_down_game(Game *game){
  SDL_DestroyWindow(game->window);
  SDL_DestroyRenderer(game->renderer);
}
