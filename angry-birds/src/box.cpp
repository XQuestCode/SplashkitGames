#include "splashkit.h"
#include "box.h"

bitmap box_bitmap(box_kind kind)
{
    switch (kind)
    {

    case BOX2:
        return bitmap_named("box2");
    case BOX3:
        return bitmap_named("box3");
    default:
        return bitmap_named("box1");
    }
}
box_data new_box(double x, double y)
{
    box_data box;
    bitmap default_bitmap = box_bitmap(static_cast<box_kind>(rnd(2)));

    box.box_sprite = create_sprite(default_bitmap);
    sprite_set_x(box.box_sprite, x);
    sprite_set_y(box.box_sprite, y);
    return box;
}
void draw_box(box_data &box)
{
    draw_sprite(box.box_sprite);
}

void update_box(box_data &box)
{
    update_sprite(box.box_sprite);
}