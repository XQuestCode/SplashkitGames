#include "splashkit.h"
#include "cage.h"

bitmap cage_bitmap(cage_kind kind)
{
    switch (kind)
    {

    case CAGE1:
        return bitmap_named("captured_bird");
    case CAGE2:
        return bitmap_named("captured_bird2");
    default:
        return bitmap_named("captured_bird");
    }
}
bitmap fb_bitmap(free_birds kind)
{
    switch (kind)
    {

    case BIRD1:
        return bitmap_named("free_bird");
    case BIRD2:
        return bitmap_named("free_bird2");
    default:
        return bitmap_named("free_bird");
    }
}
cage_data new_cage(double x, double y)
{
    cage_data cage;
    bitmap default_bitmap = cage_bitmap(static_cast<cage_kind>(rnd(-1,2)));

    cage.cage_sprite = create_sprite(default_bitmap);
    sprite_set_x(cage.cage_sprite, x);
    sprite_set_y(cage.cage_sprite, y);
    cage.some = false;
    return cage;
}
void new_fb_bird(cage_data &fb_bird)
{
    bitmap default_bitmap;
    if (fb_bird.kind == CAGE1)
    {
        default_bitmap = fb_bitmap(BIRD1);
    }
    else
    {
        default_bitmap = fb_bitmap(BIRD2);
    }

    fb_bird.fb_bird_sprite = create_sprite(default_bitmap);
    sprite_set_x(fb_bird.fb_bird_sprite, sprite_x(fb_bird.cage_sprite));
    sprite_set_y(fb_bird.fb_bird_sprite, sprite_y(fb_bird.cage_sprite));
    if (fb_bird.some)
    {
        sprite_set_dx(fb_bird.fb_bird_sprite, 5);

        sprite_set_rotation(fb_bird.fb_bird_sprite, rnd(100, 145));
    }
}
void draw_cage(cage_data &cage)
{
    draw_sprite(cage.cage_sprite);
}
void draw_fb_bird(cage_data &cage)
{
    draw_sprite(cage.fb_bird_sprite);
}
void update_cage(cage_data &cage)
{
    update_sprite(cage.cage_sprite);
}
void update_fb_bird(cage_data &cage)
{
    update_sprite(cage.fb_bird_sprite);
}