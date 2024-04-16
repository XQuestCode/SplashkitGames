#ifndef ANGRY_BIRDS_PLAYER
#define ANGRY_BIRDS_PLAYER
#include "splashkit.h"
#include <vector>
/**
 * Different options for the kind of mouse pointers
 * Adjusts the image used.
 */
enum mouse_kind
{
    FINGER,
    HOLD,
};
struct player_data {
    mouse_kind kind;
    sprite mouse_sprite;
    int level;
    int birds;
    int score;
    bool launch;
};
player_data new_player();
void update_player(player_data &player_to_update);
bitmap mouse_bitmap(mouse_kind kind);
void draw_mouse(const player_data &player_to_draw);
void mouse_switch(player_data &player);
bool clicked(player_data &player, sprite some);
#endif
