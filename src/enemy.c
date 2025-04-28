#include "enemy.h"
#include "sprite_map.h"

void init_enemies(void){
  init_enemy_1();
}

Enemy init_enemy_1(void) {
  Enemy enemy;
  
  // Initialize all fields to avoid undefined behavior
  enemy.stripes.idle_rect = sprite_map.enemy_stripes.enemy_1_idle_rect;
  enemy.stripes.shooting_rect = sprite_map.enemy_stripes.enemy_1_shooting_rect;
  enemy.stripes.current_rect = sprite_map.enemy_stripes.enemy_1_idle_rect;
  
  // Initialize movement values
  enemy.movement.x = 0.0f;
  enemy.movement.y = 0.0f;
  enemy.movement.velocity = 100.0f;
  enemy.movement.max_speed = 100.0f;
  enemy.movement.acceleration = 1500.0f;
  enemy.movement.deacceleration = 2000.0f;
  enemy.movement.direction = 1;

  // Initialize bullet
  enemy.bullet.active = 0;
  enemy.bullet.x = 0.0f;
  enemy.bullet.y = 0.0f;
  enemy.bullet.velocity_y = 0.0f;
  enemy.bullet.bullet_rect = sprite_map.enemy_stripes.enemy_1_shooting_rect;
  
  // Initialize data
  enemy.data.health_points = 1.0f;
  
  return enemy;
}
