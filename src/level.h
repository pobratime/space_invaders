#ifndef LEVEL_H
#define LEVEL_H

#include "enemy.h"

typedef struct{

  char *name;
  int level_number;

  int number_of_enemies;
  Enemy *enemies;
  
  float wave_timer;
  int current_wave;
  int number_of_waves;

  int is_complete;
  int is_boss_level;
}Level;

extern Level level_1;
void init_level_1(void);
void update_level_enemies_movement(Level *level, float delta);

#endif
