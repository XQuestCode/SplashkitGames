#ifndef ANGRY_BIRDS_BOX
#define ANGRY_BIRDS_BOX
#include "splashkit.h"
enum box_kind
{
    BOX2,
    BOX3

};
struct box_data
{
    box_kind kind;
    sprite box_sprite;
};
box_data new_box(double x, double y);
void draw_box(box_data &box);
void update_box(box_data &box);
#endif