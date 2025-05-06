#include "update_settings_state.h"
#include "assets/assets.h"

void handle_settings_state(Game *game, float delta_time, SDL_Scancode pressed_key){

  switch(pressed_key){
    case(SDL_SCANCODE_DOWN):{
      if(game->options_data.current_button >= 5) game->options_data.current_button = 0;
      else game->options_data.current_button += 1;
      break;
    } 
    case(SDL_SCANCODE_UP):{ 
      if(game->options_data.current_button <= 0) game->options_data.current_button = 4;
      else game->options_data.current_button -= 1;
      break;
    }
    case(SDL_SCANCODE_LEFT):{
      switch(game->options_data.current_button){
        case(0):{
          if(game->options_data.sound_level <= 0) game->options_data.sound_level = 0;
          else game->options_data.sound_level -= 1;
          break;
        }
        case(1):{
          if(game->options_data.music_level <= 0) game->options_data.music_level = 0;
          else game->options_data.music_level -= 1;
          break;
        }
        default: break;
      }
      break;
    }
    case(SDL_SCANCODE_RIGHT):{      
      switch(game->options_data.current_button){
        case(0):{
          if(game->options_data.sound_level >= 10) game->options_data.sound_level = 10;
          else game->options_data.sound_level += 1;
          break;
        }
        case(1):{
          if(game->options_data.music_level >= 10) game->options_data.music_level = 10;
          else game->options_data.music_level += 1;
          break;
        }
        default: break;
      }
      break;
    }
    case(SDL_SCANCODE_SPACE):{
      switch(game->options_data.current_button){
        case(2):{
          game->options_data.current_resolution_int = 3;
          break;
        }
        case(3):{
          game->options_data.current_resolution_int = 1;
          break;
        }
        case(4):{
          game->options_data.current_resolution_int = 2;
          break;
        }
        case(5):{
          game->menu_data.current_button = 0;
          game->pause_data.current_button = 0;
          game->data_dynamic.state = game->last_state;
          break;
        }
        default: break;
      }
      break;
    }
    default: break;
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

