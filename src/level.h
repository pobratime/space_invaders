#ifndef LEVEL_H
#define LEVEL_H

#include "enemy.h"

typedef struct{
  int level_number;
  int enemy_count;
  Enemy *enemies;
}Level;

typedef struct{
  Level *level_1;
  Level *level_2;
  Level *level_3;
}Level_list;

void generate_level_1(void);

extern Level_list level_list;

#endif
