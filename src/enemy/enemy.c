#include "enemy.h"

void init_enemies(void){
  init_enemy_1();
}

void enemy_shoot(Enemy *enemy){
  enemy->bullet.active = 1;
  enemy->bullet.type = 1;
  enemy->bullet.x = enemy->movement.x;
  enemy->bullet.y = enemy->movement.y;
}

Enemy init_enemy_1(void) {
  Enemy enemy;

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
  
  // Initialize data
  enemy.data.health_points = 1.0f;
  
  return enemy;
}
