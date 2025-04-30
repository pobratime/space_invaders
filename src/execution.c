#include "execution.h"
#include "game/game.h"
#include "init.h"
#include "renderer/renderer.h"
#include <stdlib.h>
#include "game/update/game_update.h"
#include "assets/assets.h" 

void start_game(void) {

  // Game instance
  Game game;

  init_game_window_and_renderer(&game);
  load_assets(game.renderer); 
  init_game_data(&game);

  // Start a game loop
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

    SDL_Scancode pressed_key = SDL_SCANCODE_UNKNOWN;

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        running = 0;
      }else if(event.type == SDL_EVENT_KEY_DOWN){
        switch(event.key.scancode){
          case(SDL_SCANCODE_LEFT):{
            pressed_key = SDL_SCANCODE_LEFT;
            break;
          }
          case(SDL_SCANCODE_RIGHT):{
            pressed_key = SDL_SCANCODE_RIGHT;
            break;
          }
          case(SDL_SCANCODE_UP):{
            pressed_key = SDL_SCANCODE_UP;
            break;
          }
          case(SDL_SCANCODE_DOWN):{
            pressed_key = SDL_SCANCODE_DOWN;
            break;
          }
          case(SDL_SCANCODE_SPACE):{
            pressed_key = SDL_SCANCODE_SPACE;
            break;
          }
          default:{
            break;
          }
        }
      }else if(event.type == SDL_EVENT_KEY_UP){
        pressed_key = SDL_SCANCODE_CANCEL;
      }
    }

    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
    SDL_RenderClear(game->renderer);

    update_game(game, delta_time, pressed_key);
    render_game(game);

    SDL_RenderPresent(game->renderer);
    SDL_Delay(16);
  }
  // shut_down_game(game);
}
