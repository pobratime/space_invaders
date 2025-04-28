#include "level.h"
#include "enemy.h"
#include <stdlib.h>

Level level_1;

void update_level_enemies_movement(Level *level, float delta){

    for(int i = 0; i < level->number_of_enemies; i++){
        float movement_amount = level->enemies[i].movement.velocity * delta;
        level->enemies[i].movement.x += movement_amount * level->enemies[i].movement.direction;
        if(level->enemies[i].movement.x <= 160.0f){
            level->enemies[i].movement.x = 160.0f;
            level->enemies[i].movement.direction = 1;
        }else if(level->enemies[i].movement.x >= 750.0f - 160.0f){
            level->enemies[i].movement.x = 750.0f - 160.0f;
            level->enemies[i].movement.direction = -1;
        }
    }

}
void init_level_1(void){

    level_1.name = "Level number one";
    level_1.level_number = 1;
    level_1.is_boss_level = 0;
    level_1.number_of_enemies = 3;

    level_1.enemies = malloc(sizeof(Enemy) * 3);
    if(!level_1.enemies){
        fprintf(stderr, "Failed to allocate array for enemies in level 1.\n");
        return;
    }
    int dx = 0;
    for(int i = 0; i < 3; i++){
        level_1.enemies[i] = init_enemy_1();
        level_1.enemies[i].movement.x = 200 + dx;
        level_1.enemies[i].movement.y = 100;
        dx += 100;
    }
}
