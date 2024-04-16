#ifndef ANGRY_BIRDS_GAME
#define ANGRY_BIRDS_GAME
#include "splashkit.h"
#include <vector>
#include "player.h"
#include "bird.h"
#include "pig.h"
#include "box.h"
#include "cage.h"
struct game_data {
    player_data player;
    bird_data current_bird;
    vector<bird_data> loaded_birds;
    vector<bird_data> projected_birds;
    vector<pig_data> pigs;
    vector<box_data> boxes;
    vector<cage_data> cages;
    timer game_timer;
    timer projectile;
    bool paused;
    int screen;
    bool intro_played;

    bool started;
    bool ended;
    bool bird_freed;
};
game_data new_game();
void draw_game(game_data &game);
void update_game(game_data &game);
void draw_game2(game_data &game);
void update_game2(game_data &game);
void collision_pigs(game_data &game);
void draw_start(game_data &game);
void update_game3(game_data &game);
void draw_game3(game_data &game);
#endif