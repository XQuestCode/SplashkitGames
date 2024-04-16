#include "splashkit.h"
#include "pig.h"
#include <vector>
using namespace std;
using std::vector;

bitmap pig_bitmap(pig_kind kind)
{
    switch (kind)
    {
    case PING:
        return bitmap_named("pig1");
    case KING:
        return bitmap_named("pig2");
    default:
        return bitmap_named("pig1");
    }
}
pig_data new_pig(double x, double y)
{
    pig_data pig;
    bitmap default_bitmap = pig_bitmap(static_cast<pig_kind>(rnd(2)));

    pig.pig_sprite = create_sprite(default_bitmap);
    sprite_set_x(pig.pig_sprite, x);
    sprite_set_y(pig.pig_sprite, y);
    return pig;
}
void draw_pig(pig_data &pig)
{
    draw_sprite(pig.pig_sprite);
}

void update_pig(pig_data &pig)
{
    update_sprite(pig.pig_sprite);
}