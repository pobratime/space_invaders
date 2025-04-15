#include "level.h"
#include "enemy.h"
#include <stdlib.h>
#include "sprite_map.h"

Level_list level_list;

void generate_level_1(void){
  level_list.level_1 = malloc(sizeof(Level));
  
  if (level_list.level_1 == NULL) {
      fprintf(stderr, "Failed to allocate memory for level 1\n");
      return;
  }

  level_list.level_1->level_number = 1;
  level_list.level_1->enemy_count = 3;
  
  level_list.level_1->enemies = malloc(sizeof(Enemy) * level_list.level_1->enemy_count);
  if (level_list.level_1->enemies == NULL) {
      fprintf(stderr, "Failed to allocate memory for enemies\n");
      return;
  }

  float dx = 200;
  float dy = 400;
  for (int i = 0; i < level_list.level_1->enemy_count; i++) {
      level_list.level_1->enemies[i].x = dx;
      level_list.level_1->enemies[i].y = dy;
      level_list.level_1->enemies[i].health_points = 10;
      level_list.level_1->enemies[i].normal_rect = sprite_map.enemy_1_idle_rect;
      level_list.level_1->enemies[i].shooting_rect = sprite_map.enemy_1_shooting_rect;
      level_list.level_1->enemies[i].current_rect = sprite_map.enemy_1_idle_rect;

      dx += 100; 
  }
}
