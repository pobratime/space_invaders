#include "update_settings_state.h"
#include "assets/assets.h"
#include "assets/ui_assets.h"
#include "game/update/update_audio.h"

void handle_settings_state(Game *game, float delta_time, bool key_states[]){

  // Update cooldown timer
  game->options_data.input_cooldown -= delta_time;

  // Only process input if cooldown has expired
  if (game->options_data.input_cooldown <= 0.0f) {
    if(key_states[SDL_SCANCODE_DOWN]){
      play_button_selection_sound(game, delta_time);
      if(game->options_data.current_button >= 5) game->options_data.current_button = 0;
      else game->options_data.current_button += 1;
      game->options_data.input_cooldown = 0.2f; // Set cooldown to prevent rapid changes

    }else if(key_states[SDL_SCANCODE_UP]){
      play_button_selection_sound(game, delta_time);
      if(game->options_data.current_button <= 0) game->options_data.current_button = 5;
      else game->options_data.current_button -= 1;
      game->options_data.input_cooldown = 0.2f; // Set cooldown to prevent rapid changes

    }else if(key_states[SDL_SCANCODE_LEFT]){
      game->options_data.input_cooldown = 0.1f; // Shorter cooldown for slider adjustments
      switch(game->options_data.current_button){
        case(0):{
          play_button_selection_sound(game, delta_time);
          if(game->options_data.sound_level <= 0) game->options_data.sound_level = 0;
          else game->options_data.sound_level -= 5;
          break;
        }
        case(1):{
          play_button_selection_sound(game, delta_time);
          if(game->options_data.music_level <= 0) game->options_data.music_level = 0;
          else game->options_data.music_level -= 5;
          break;
        }
        default: break;
      }
  }else if(key_states[SDL_SCANCODE_RIGHT]){
      game->options_data.input_cooldown = 0.1f; // Shorter cooldown for slider adjustments
      switch(game->options_data.current_button){
        case(0):{
          play_button_selection_sound(game, delta_time);
          if(game->options_data.sound_level >= 100) game->options_data.sound_level = 100;
          else game->options_data.sound_level += 5;
          break;
        }
        case(1):{
          play_button_selection_sound(game, delta_time);
          if(game->options_data.music_level >= 100) game->options_data.music_level = 100;
          else game->options_data.music_level += 5;
          break;
        }
        default: break;
      }
  }else if(key_states[SDL_SCANCODE_SPACE]){
      game->options_data.input_cooldown = 0.2f; // Set cooldown for space key
      switch(game->options_data.current_button){
        case(2):{
          play_button_clicked_sound(game, delta_time);
          game->options_data.current_resolution_int = 3;
          break;
        }
        case(3):{
          play_button_clicked_sound(game, delta_time);
          game->options_data.current_resolution_int = 1;
          break;
        }
        case(4):{
          play_button_clicked_sound(game, delta_time);
          game->options_data.current_resolution_int = 2;
          break;
        }
        case(5):{
          play_button_clicked_sound(game, delta_time);
          game->menu_data.current_button = 0;
          game->pause_data.current_button = 0;
          game->data_dynamic.state = game->last_state;
          break;
        }
        default: break;
      }
  }
}

  update_settings_buttons(game, delta_time);
}

void update_settings_buttons(Game *game, float detla_time){

  game->options_data.cur_sound = assets.ui.slider.idle;
  game->options_data.cur_music = assets.ui.slider.idle;
  game->options_data.cur_exit = assets.ui.exit_button.idle;

  // Update resolution checkboxes based on current resolution
  if(game->options_data.current_resolution_int == 3){
    game->options_data.cur_1920x1080 = assets.ui.box_1.checked;
  }else{
    game->options_data.cur_1920x1080 = assets.ui.box_1.idle;
  }
  if(game->options_data.current_resolution_int == 1){
    game->options_data.cur_1680x1050 = assets.ui.box_1.checked;
  }else{
    game->options_data.cur_1680x1050 = assets.ui.box_1.idle;
  }
  if(game->options_data.current_resolution_int == 2){
    game->options_data.cur_1280x800 = assets.ui.box_1.checked;
  }else{ 
    game->options_data.cur_1280x800 = assets.ui.box_1.idle;
  }

  switch(game->options_data.current_button){
    case(0):{
      // SOUND SLIDER IS SELECTED
      game->options_data.cur_sound = assets.ui.slider.selected;
      break;
    }
    case(1):{
      // MUSIC SLIDER IS SELECTED      
      game->options_data.cur_music = assets.ui.slider.selected;
      break;
    }
    case(2):{
      // FIRST RESOLUTION IS SELECTED
      if(game->options_data.current_resolution_int == 3){
        game->options_data.cur_1920x1080 = assets.ui.box_1.selected_checked;
      }else{
        game->options_data.cur_1920x1080 = assets.ui.box_1.selected;
      }
      break;
    }
    case(3):{
      // SECOND RESOLUTION IS SELECTED
      if(game->options_data.current_resolution_int == 1){
        game->options_data.cur_1680x1050 = assets.ui.box_1.selected_checked;
      }else{
        game->options_data.cur_1680x1050 = assets.ui.box_1.selected;
      }
      break;
    }
    case(4):{
      // THIRD RESOLUTION IS SELECTED
      if(game->options_data.current_resolution_int == 2){
        game->options_data.cur_1280x800 = assets.ui.box_1.selected_checked;
      }else{ 
        game->options_data.cur_1280x800 = assets.ui.box_1.selected;
      }
      break;
    }
    case(5):{
      game->options_data.cur_exit = assets.ui.exit_button.selected;
      break;
    }
    default: break;
  }
}

