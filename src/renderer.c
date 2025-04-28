#include "renderer.h"
#include <SDL3/SDL.h>
#include "game.h"
#include "player.h"
#include "sprite_map.h"

// Main rendering function which calls subfunctions that render specific parts of the game
void render_game(Game *game){
  render_background(game);
  render_player(game);
  render_player_bullets(game);
  render_ui_elements(game);
  render_enemies(game);
  render_collisions_bullet_and_enemy(game);
}

// This function renderes a background in two parts so that we can achive an animation effect
void render_background(Game *game){

    // Selceting the position where the first part will appear
    SDL_FRect dest_rect1 = {
        0.0f, sprite_map.background.y_level, 800.0f, 600.0f
    };
    // Selecting the position where the second part will appear
    // This part is done like y_level - height
    SDL_FRect dest_rect2 = {
        0.0f,  sprite_map.background.y_level - 600.0f, 800.0f, 600.0f
    };

    // When we combine those two parts of the backgound where the game window is basicly split in two
    // we gain an animation that looks like we are flying trough the space

    // Render first part
    SDL_RenderTexture(
        game->renderer,
        sprite_map.background.texture,
        NULL,
        &dest_rect1
    );

    // Render second part
    SDL_RenderTexture(
        game->renderer,
        sprite_map.background.texture,
        NULL,
        &dest_rect2
    );
}

// Function that renders UI elements like scorboard and current level
void render_ui_elements(Game *game){

    // Position of the scoreboard
    SDL_FRect dest_rect1 = {
        0.0f, 50.0f, 150.0f, 100.0f
    };

    // Position of the level
    SDL_FRect dest_rect2 = {
        650.0, 50.0f, 150.0f, 100.0f
    };

    // Rendering the scoreboard
    SDL_RenderTexture(
        game->renderer,
        sprite_map.spritesheet,
        &sprite_map.ui_sprites.scoreboard,
        &dest_rect1
    );

    // Rendering the level
    SDL_RenderTexture(
        game->renderer,
        sprite_map.spritesheet,
        &sprite_map.ui_sprites.level,
        &dest_rect2
    );
}

// Player renderer function
void render_player(Game *game){

    // Selecting the position where the player rect will appear and scaling
    SDL_FRect dest_rect = {
        game->player.movement.x, game->player.movement.y, 50.0f, 50.0f
    };
    
    // Rendering the player
    SDL_RenderTexture(
        game->renderer,
        sprite_map.spritesheet,
        &game->player.sprites.current_rect,
        &dest_rect
    );
}

// Bullet renderer function
void render_player_bullets(Game *game){
    // If the bullet reached the top of the screen which mean y = 0 we don't render it because its time to reload
    if(!game->player.bullet.y) return;

    // Selecting the position of the bullet based on the current players position
    SDL_FRect dest_rect = {
        game->player.bullet.x, game->player.bullet.y, 10.0f, 30.0f
    };

    // Rendering a bullet
    SDL_RenderTexture(
        game->renderer,
        sprite_map.spritesheet,
        &game->player.bullet.bullet_rect,
        &dest_rect
    );
}

// Enemy render function
void render_enemies(Game *game){
    for(int i = 0; i < game->current_level.number_of_enemies; i++){
        if(game->current_level.enemies[i].data.health_points <= 0) continue;
        SDL_FRect dest_rect = {
            game->current_level.enemies[i].movement.x, 
            game->current_level.enemies[i].movement.y, 
            50.0f, 50.0f
        };
        SDL_RenderTexture(
            game->renderer,
            sprite_map.spritesheet,
            &game->current_level.enemies[i].stripes.current_rect,
            &dest_rect
        );
    }
}


void render_collisions_bullet_and_enemy(Game *game){
    SDL_FRect bullet_rect = {
        game->player.bullet.x,
        game->player.bullet.y,
        10.0f,
        30.0f
    };

    for(int i = 0; i < game->current_level.number_of_enemies; i++){
        if(game->current_level.enemies[i].data.health_points <= 0) continue;

        SDL_FRect enemy_rect = {
            game->current_level.enemies[i].movement.x,
            game->current_level.enemies[i].movement.y,
            50.0f,
            50.0f
        };

        if(SDL_HasRectIntersectionFloat(&bullet_rect, &enemy_rect)){
            game->current_level.enemies[i].data.health_points = 0;
            game->player.bullet.active = 0;
            game->player.bullet.y = 0;
            break;
        }
    }
}
