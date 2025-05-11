#include "update_audio.h"
#include "assets/assets.h"
#include <stdlib.h>

void handle_audio(Game *game, float delta_time){

  float volume = (float)game->options_data.music_level / 100.0f;

  SDL_AudioDeviceID dev = SDL_GetAudioStreamDevice(game->music_audio_stream);
  
  SDL_SetAudioStreamGain(game->music_audio_stream, volume);

  if(SDL_GetAudioStreamQueued(game->music_audio_stream) < 4096){
    Uint8 *buffer_copy = malloc(assets.audio.galactic_pulse.length);
    for (Uint32 i = 0; i < assets.audio.galactic_pulse.length; i++) {
      buffer_copy[i] = assets.audio.galactic_pulse.buffer[i]; 
      // dont multiply just make the copy
    }
    SDL_PutAudioStreamData(game->music_audio_stream, buffer_copy, assets.audio.galactic_pulse.length);
    free(buffer_copy);
  } 
}

void play_bullet_sound(Game *game, float delta_time){

  float volume = (float)game->options_data.sound_level / 100.0f;

  SDL_AudioDeviceID dev = SDL_GetAudioStreamDevice(game->sound_audio_stream_2);

  // to avoid compiler warrnigns
  (void)dev;
  (void)delta_time;
  
  SDL_ClearAudioStream(game->sound_audio_stream_2);
  SDL_SetAudioStreamGain(game->sound_audio_stream_2, volume);

  // Create a copy of the buffer to avoid modifying the original data
  Uint8 *buffer_copy = malloc(assets.audio.laser_gun_classic.length);
  if (buffer_copy) {
    for (Uint32 i = 0; i < assets.audio.laser_gun_classic.length; i++) {
      buffer_copy[i] = assets.audio.laser_gun_classic.buffer[i];
    }
    SDL_PutAudioStreamData(game->sound_audio_stream_2, buffer_copy, assets.audio.laser_gun_classic.length);
    free(buffer_copy);
  }
}

void play_button_selection_sound(Game *game, float delta_time){

  float volume = (float)game->options_data.sound_level / 100.0f;

  SDL_AudioDeviceID dev = SDL_GetAudioStreamDevice(game->sound_audio_stream);

  SDL_SetAudioStreamGain(game->sound_audio_stream, volume);
  SDL_ClearAudioStream(game->sound_audio_stream);

  // Create a copy of the buffer to avoid modifying the original data
  Uint8 *buffer_copy = malloc(assets.audio.button_selection.length);
  if (buffer_copy) {
    for (Uint32 i = 0; i < assets.audio.button_selection.length; i++) {
      buffer_copy[i] = assets.audio.button_selection.buffer[i];
    }
    int result = SDL_PutAudioStreamData(game->sound_audio_stream, buffer_copy, assets.audio.button_selection.length);
    if (result < 0) {
      SDL_Log("Failed to put audio data into stream: %s", SDL_GetError());
    }
    free(buffer_copy);
  }
}

void play_button_clicked_sound(Game *game, float delta_time){
  
  float volume = (float)game->options_data.sound_level / 100.0f;

  SDL_AudioDeviceID dev = SDL_GetAudioStreamDevice(game->sound_audio_stream);

  SDL_SetAudioStreamGain(game->sound_audio_stream, volume);
  SDL_ClearAudioStream(game->sound_audio_stream);

  // Create a copy of the buffer to avoid modifying the original data
  Uint8 *buffer_copy = malloc(assets.audio.button_clicked.length);
  if (buffer_copy) {
    for (Uint32 i = 0; i < assets.audio.button_clicked.length; i++) {
      buffer_copy[i] = assets.audio.button_clicked.buffer[i];
    }
    int result = SDL_PutAudioStreamData(game->sound_audio_stream, buffer_copy, assets.audio.button_clicked.length);
    if (result < 0) {
      SDL_Log("Failed to put audio data into stream: %s", SDL_GetError());
    }
    free(buffer_copy);
  }
}
