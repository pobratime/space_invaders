#include "execution.h"
#include "game/game.h"
#include "game/game_states.h"
#include "init.h"
#include "renderer/renderer.h"
#include <stdlib.h>
#include "game/update/game_update.h"
#include "assets/assets.h" 
#include "SDL3/SDL.h"

void start_game(void) {

  // Game instance
  Game game;

  init_game_window_and_renderer(&game);
  init_audio(&game);
  load_assets(game.renderer); 
  init_game_data(&game);
  create_game(&game);
  
  // Start a game loop
  game_loop(&game);
}

// Main game loop
void game_loop(Game *game) {

  SDL_Event event;
  Uint64 previous_time = SDL_GetTicks();
  Uint64 current_time;
  float delta_time;

  game->sound_audio_stream = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &assets.audio.galactic_pulse.spec, NULL, NULL);
  game->music_audio_stream = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &assets.audio.button_selection.spec, NULL, NULL);
  game->sound_audio_stream_2 = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &assets.audio.laser_gun_classic.spec, NULL, NULL);

  // Start the audio stream playback
  if (game->music_audio_stream) {
    SDL_ResumeAudioDevice(SDL_GetAudioStreamDevice(game->music_audio_stream));
  } else {
    SDL_Log("Failed to open music audio stream: %s", SDL_GetError());
  }
  
  // Start the sound effects audio stream playback
  if (game->sound_audio_stream) {
    SDL_ResumeAudioDevice(SDL_GetAudioStreamDevice(game->sound_audio_stream));
  } else {
    SDL_Log("Failed to open sound effects audio stream: %s", SDL_GetError());
  }
  
  if (game->sound_audio_stream_2) {
    SDL_ResumeAudioDevice(SDL_GetAudioStreamDevice(game->sound_audio_stream_2));
  } else {
    SDL_Log("Failed to open sound effects audio 2 stream: %s", SDL_GetError());
  }
  
  bool key_states[SDL_SCANCODE_COUNT] = {false};

  while (game->running) {
    
    current_time = SDL_GetTicks();
    delta_time = (current_time - previous_time) / 1000.0f;
    previous_time = current_time;

    // SDL_GetKeyboardState(NULL);
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        game->running = 0;
      }else if(event.type == SDL_EVENT_KEY_DOWN){
        SDL_GetKeyboardState(NULL);
        key_states[event.key.scancode] = true;
      }else if(event.type == SDL_EVENT_KEY_UP){
        SDL_GetKeyboardState(NULL);
        key_states[event.key.scancode] = false;
      }
    }

    game->player.data.score += 1;

    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
    SDL_RenderClear(game->renderer);

    update_game(game, delta_time, key_states);
    render_game(game);

    SDL_RenderPresent(game->renderer);
    SDL_Delay(7);
  }
  // shut_down_game(game);
}
