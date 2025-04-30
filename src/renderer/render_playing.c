#include "render_playing.h"
#include "assets/assets.h"
#include "stdlib.h"
#include "math.h"

void render_playing(Game *game){
  // now we render the spicifc parts that are used while the game is being played
  // its importan that we pass the game here so that we can keep the game state
  // also its important that we pass the game here and in the other files to achive scaling with cur_res

  // PLAYER
  render_player(game);
  render_player_bullets(game);
  
  // ENEMIES
  render_enemies(game);
  render_enemy_bullets(game);

  // UI
  render_ui_elements(game);
}

void render_player(Game *game){
  SDL_FRect rect = {
    game->player.movement.x, game->player.movement.y, 50.0f, 50.0f
  };

  SDL_FRect rect2 = {
    game->player.movement.x + 32.0f, game->player.movement.y + 53.0f, 5.0f, 15.0f,
  };

  SDL_FRect rect3 = {
    game->player.movement.x + 13.0f, game->player.movement.y + 53.0f, 5.0f, 15.0f,
  };

  SDL_RenderTexture(
    game->renderer,
    assets.misc.bmp_file,
    &game->data_dynamic.current_emission_1,
    &rect3
  );

  SDL_RenderTexture(
    game->renderer,
    assets.misc.bmp_file,
    &game->data_dynamic.current_emission_2,
    &rect2
  );

  SDL_RenderTexture(
    game->renderer,
    assets.spaceship.bmp_file,
    &game->data_dynamic.current_player_rect,
    &rect
  );
}

// void render_player(Game *game) {

//   float x = game->player.movement.x;
//   float y = game->player.movement.y;
//   float w = 50.0f;
//   float h = 50.0f;

//   float velocity_x = game->player.movement.velocity_x;
//   float angle = 0.0f;

//   if (velocity_x < -5.0f) {
//     angle = 145.0f;
//   } else if (velocity_x > 5.0f) {
//     angle = 35.0f;
//   } else {
//     angle = 0.0f;
//   }

//   float rad = angle * (float)M_PI / 180.0f;
//   float scale = fabsf(cosf(rad));  // squash width to simulate turning
//   bool flip = angle > 90.0f;

//   float hw = (w * scale) / 2.0f;
//   float cx = x + w / 2.0f;

//   SDL_Vertex verts[4];
//   SDL_Vertex verts_left[4];
//   SDL_Vertex verts_right[4];

//   SDL_FColor white = {1.0f, 1.0f, 1.0f, 1.0f};

//   // Skewed vertex positions around center x
//   verts[0].position = verts_left[0].position = verts_right[0].position = (SDL_FPoint){cx - hw, y};         // Top-left
//   verts[1].position = verts_left[1].position = verts_right[1].position = (SDL_FPoint){cx + hw, y};         // Top-right
//   verts[2].position = verts_left[2].position = verts_right[2].position = (SDL_FPoint){cx + hw, y + h};     // Bottom-right
//   verts[3].position = verts_left[3].position = verts_right[3].position = (SDL_FPoint){cx - hw, y + h};     // Bottom-left

//   // Assign color
//   for (int i = 0; i < 4; ++i)
//     verts[i].color = white;

//   // Indices to draw two triangles (quad)
//   int indices[6] = {0, 1, 2, 2, 3, 0};

//   // Select spaceship sub-region of the texture
//   float norm = 79.0f;
//   float x1 = 8.0f / norm, y1 = 32.0f / norm;
//   float x2 = 16.0f / norm, y2 = 39.0f / norm;

//   if (!flip) {
//     verts[0].tex_coord = (SDL_FPoint){x1, y1};  // Top-left
//     verts[1].tex_coord = (SDL_FPoint){x2, y1};  // Top-right
//     verts[2].tex_coord = (SDL_FPoint){x2, y2};  // Bottom-right
//     verts[3].tex_coord = (SDL_FPoint){x1, y2};  // Bottom-left
//   } else {
//     // Horizontal flip of texture coordinates
//     verts[0].tex_coord = (SDL_FPoint){x2, y1};  // Top-left (flipped)
//     verts[1].tex_coord = (SDL_FPoint){x1, y1};  // Top-right (flipped)
//     verts[2].tex_coord = (SDL_FPoint){x1, y2};  // Bottom-right (flipped)
//     verts[3].tex_coord = (SDL_FPoint){x2, y2};  // Bottom-left (flipped)
//   }


//   SDL_RenderGeometry(
//     game->renderer,
//     assets.spaceship.bmp_file,
//     verts,
//     4,
//     indices,
//     6
//   );
// }

void render_player_bullets(Game *game){

}

void render_enemies(Game *game){

}

void render_enemy_bullets(Game *game){

}

void render_ui_elements(Game *game){

}

void render_scoreboard(Game *game){

}

void render_health_bar(Game *game){

}
