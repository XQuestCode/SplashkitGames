#ifndef ANGRY_BIRDS_cage
#define ANGRY_BIRDS_cage
#include "splashkit.h"
enum cage_kind
{
    CAGE1,
    CAGE2,

};
enum free_birds
{
    BIRD1,
    BIRD2
};

struct cage_data
{
    cage_kind kind;
    free_birds fb_kind;
    sprite cage_sprite;
    sprite fb_bird_sprite;
    bool some;
};
cage_data new_cage(double x, double y);
void draw_cage(cage_data &cage);
void update_cage(cage_data &cage);
void update_fb_bird(cage_data &cage);
void draw_fb_bird(cage_data &cage);
void new_fb_bird(cage_data &fb_bird);
#endif