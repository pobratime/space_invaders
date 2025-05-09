#ifndef SOUND_ASSETS_H
#define SOUND_ASSETS_H

#include "SDL3/SDL.h"

typedef struct{
  SDL_AudioSpec spec;
  Uint8 *buffer;
  Uint32 length;
}Audio;

typedef struct{
  Audio galactic_pulse;
  Audio laser_gun_classic;
  Audio button_selection;
  Audio button_clicked;
}Audio_assets;


void load_sound_assets(Audio_assets *audio);
void load_galactic_pulse_wav(Audio_assets *audio);
void load_laser_gun_classic_wav(Audio_assets *audio);
void load_button_selection_wav(Audio_assets *audio);
void load_button_clicked_wav(Audio_assets *audio);

#endif
