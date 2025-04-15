#include "renderer.h"
#include <SDL3/SDL.h>
#include "game.h"
#include "sprite_map.h"
#include "enemy.h"

void render_game(Game *game){
  render_background(game);
  render_player(game);
  render_enemies(game);
}

void render_background(Game *game){
    SDL_FRect dest_rect = {
        0.0f, 0.0f, 800.0f, 600.0f
    };
    
    SDL_RenderTexture(
        game->renderer,
        sprite_map.spritesheet,
        &sprite_map.background_rect,
        &dest_rect
    );
}

void render_player(Game *game){
    SDL_FRect dest_rect = {
        game->player.x, game->player.y, 50.0f, 50.0f
    };
    
    SDL_RenderTexture(
        game->renderer,
        sprite_map.spritesheet,
        &game->player.current_rect,
        &dest_rect
    );
}

void render_enemies(Game *game){
    for(int i = 0; i < game->current_level.enemy_count; i++){
        render_enemy(game, &game->current_level.enemies[i]);
    }
}

void render_enemy(Game *game, Enemy *enemy){
    SDL_FRect dest_rect = {
        enemy->x, enemy->y, 50.0f, 50.0f
    };
    SDL_RenderTexture(
        game->renderer,
        sprite_map.spritesheet,
        &enemy->current_rect,
        &dest_rect
    );
}
