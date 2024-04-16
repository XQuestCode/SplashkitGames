#ifndef ANGRY_BIRDS_BIRD
#define ANGRY_BIRDS_BIRD
#include "splashkit.h"
#include <vector>
enum bird_type
{
    RED_BIRD,
    YELLOW_BIRD,
    BLACK_BIRD
};
enum bird_kind
{
    RED,
    RED2,
    RED_DEAD,
    YELLOW,
    YELLOW2,
    YELLOW3,
    YELLOW_DEAD,
    BLACK,
    BLACK2,
    BLACK3,
    BLACK_DEAD
};
/**
 * The bird data keeps track of all of the information related to the bird.
 *
 * @field   bird_sprite   The bird's sprite - used to track position and movement
 */
struct bird_data
{
    bird_kind kind;
    bird_type type;
    sprite bird_sprite;
    double speed;
    double angle;
    timer bird_timer;

    bool dead;  
    bool tune_played;
    bool ultimate;
};
bitmap bird_bitmap(bird_type kind);
bird_data new_bird(bird_kind kind, double x, double y);
void draw_bird(bird_data bird);
void update_bird(bird_data &bird);
void bird_switch(bird_data &bird, bird_kind target);
void bird_projectile(bird_data &bird);

#endif