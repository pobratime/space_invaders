#include "sound_assets.h"

#include "SDL3//SDL.h"

void load_sound_assets(Audio_assets *audio){

  if(!SDL_Init(SDL_INIT_AUDIO)){
    SDL_Log("failed to init sdl_audio: %s", SDL_GetError());
  }

  load_galactic_pulse_wav(audio);
  load_laser_gun_classic_wav(audio);
  load_button_selection_wav(audio);
  load_button_clicked_wav(audio);
}

void load_laser_gun_classic_wav(Audio_assets *audio){
  SDL_LoadWAV(
    "/Users/lukaajdukovic/Desktop/space_invaders/src/assets_bmp/audio/laser_gun_classic.wav",
    &audio->laser_gun_classic.spec,
    &audio->laser_gun_classic.buffer,
    &audio->laser_gun_classic.length
  );

}

void load_galactic_pulse_wav(Audio_assets *audio){
  SDL_LoadWAV(
    "/Users/lukaajdukovic/Desktop/space_invaders/src/assets_bmp/audio/galactic_pulse.wav", 
    &audio->galactic_pulse.spec, 
    &audio->galactic_pulse.buffer,
    &audio->galactic_pulse.length
  );
}

void load_button_selection_wav(Audio_assets *audio){
  SDL_LoadWAV(
    "/Users/lukaajdukovic/Desktop/space_invaders/src/assets_bmp/audio/button_beep.wav",
    &audio->button_selection.spec, 
    &audio->button_selection.buffer,
    &audio->button_selection.length
  );
  
  if (audio->button_selection.buffer == NULL) {
    SDL_Log("Failed to load button selection sound: %s", SDL_GetError());
  }
}

void load_button_clicked_wav(Audio_assets *audio){
  SDL_LoadWAV(
    "/Users/lukaajdukovic/Desktop/space_invaders/src/assets_bmp/audio/navigation_tone.wav",
    &audio->button_clicked.spec, 
    &audio->button_clicked.buffer,
    &audio->button_clicked.length
  );
  
  if (audio->button_clicked.buffer == NULL) {
    SDL_Log("Failed to load button clicked sound: %s", SDL_GetError());
  }
}
