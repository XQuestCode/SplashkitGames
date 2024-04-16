#include "splashkit.h"
#include <vector>
#include "bird.h"
using namespace std;
bitmap bird_bitmap(bird_kind kind)
{
    switch (kind)
    {
    case RED:
        return bitmap_named("red");
    case RED2:
        return bitmap_named("red2");
    case RED_DEAD:
        return bitmap_named("red_dead");
    case YELLOW:
        return bitmap_named("yellow");
    case YELLOW2:
        return bitmap_named("yellow2");
    case YELLOW3:
        return bitmap_named("yellow3");
    case YELLOW_DEAD:
        return bitmap_named("yellow_dead");
    case BLACK:
        return bitmap_named("black");
    case BLACK2:
        return bitmap_named("black2");
    case BLACK3:
        return bitmap_named("black3");
    case BLACK_DEAD:
        return bitmap_named("black4");
    default:
        return bitmap_named("red");
    }
}
bird_data new_bird(bird_kind kind, double x, double y)
{
    bird_data bird;
    bitmap default_bitmap = bird_bitmap(kind);

    bird.bird_sprite = create_sprite(default_bitmap);
    bird.kind = kind;
    bird.tune_played = false;
    if (bird.kind == RED)
    {
        bird.type = RED_BIRD;
        sprite_add_layer(bird.bird_sprite, bird_bitmap(RED2), "RED2");
        sprite_hide_layer(bird.bird_sprite, 1);
        sprite_add_layer(bird.bird_sprite, bird_bitmap(RED2), "RED_DEAD");
        sprite_hide_layer(bird.bird_sprite, 2);
    }
    else if (bird.kind == YELLOW)
    {
        bird.type = YELLOW_BIRD;
        sprite_add_layer(bird.bird_sprite, bird_bitmap(RED2), "YELLOW2");
        sprite_hide_layer(bird.bird_sprite, 1);
        sprite_add_layer(bird.bird_sprite, bird_bitmap(RED2), "YELLOW3");
        sprite_hide_layer(bird.bird_sprite, 2);
        sprite_add_layer(bird.bird_sprite, bird_bitmap(RED2), "YELLOW_DEAD");
        sprite_hide_layer(bird.bird_sprite, 3);
    }
    else if (bird.kind == BLACK)
    {
        bird.type = BLACK_BIRD;
        sprite_add_layer(bird.bird_sprite, bird_bitmap(RED2), "BLACK2");
        sprite_hide_layer(bird.bird_sprite, 1);
        sprite_add_layer(bird.bird_sprite, bird_bitmap(RED2), "BLACK_DEAD");
        sprite_hide_layer(bird.bird_sprite, 2);
    }

    bird.ultimate = false;
    bird.dead = false;
    //bird.angle = 0;
    bird.speed = 0; 
   

    sprite_set_x(bird.bird_sprite, x);
    sprite_set_y(bird.bird_sprite, y);
    return bird;
}
void draw_bird(bird_data bird)
{
    draw_sprite(bird.bird_sprite);
}
void check_bird_status(bird_data &bird)
{
    double x = sprite_x(bird.bird_sprite);
    double y = sprite_y(bird.bird_sprite);
    if (!(x > 0 && x < 322 && (y > 520 && y< 720)))
    {
        if(x<0) {
            bird.dead = true;
        }
        if ( (x > 0 && x < 322 && y > 520) || (x > 322 && x < 730 && y > 591) || (x > 730 && x < 1280 && y > 520) || x > 1280 || y > 591)
        {
            sprite_set_dx(bird.bird_sprite, 0);
            bird.speed = 0;
            bird.dead = true;
        }
    }
}
void bird_switch(bird_data &bird, bird_kind target)
{
    // only do this if there is a change
    if (bird.kind != target)
    {
        // show then hide layers
        sprite_show_layer(bird.bird_sprite, static_cast<int>(target));
        sprite_hide_layer(bird.bird_sprite, static_cast<int>(bird.kind));

        // remember what is currently shown
        bird.kind = target;
    }
}
void update_bird(bird_data &bird)
{
    int i = 0;
    i++;

    if (bird.type == RED_BIRD)
    {

        if (i < 20 )
        {
            bird_switch(bird, RED2);
        }
        else if (i > 20 && i < 40 )
        {
            bird_switch(bird, RED);
        }
        if (bird.dead)
        {
            bird_switch(bird, RED_DEAD);
        }
    }
    if (bird.type == YELLOW_BIRD)
    {

        if (i < 20 )
        {
            bird_switch(bird, YELLOW2);
        }
        else if (i > 20 && i < 40 )
        {
            bird_switch(bird, YELLOW);
        }
        if (bird.ultimate && !bird.dead)
        {
            bird_switch(bird, YELLOW3);
        }
        if (bird.dead)
        {
            bird_switch(bird, YELLOW_DEAD);
        }
    }
    if (bird.type == BLACK_BIRD)
    {

        if (i < 20 )
        {
            bird_switch(bird, BLACK2);
        }
        else if (i > 20 && i < 40 )
        {
            bird_switch(bird, BLACK);
        }
        if (bird.ultimate && !bird.dead )
        {
            bird_switch(bird, BLACK3);
        }
        if (bird.dead)
        {
            bird_switch(bird, BLACK_DEAD);
        }
    }
    if (i > 40)
    {
        i = 0;
    }
    check_bird_status(bird);
    update_sprite(bird.bird_sprite);
}

void bird_projectile(bird_data &bird)
{
    sprite_set_dx(bird.bird_sprite, bird.speed);

    sprite_set_rotation(bird.bird_sprite, bird.angle);

    if (bird.angle > -90 && bird.angle < 90)
    {
        bird.angle += 2;
    }
    else if (bird.angle < -90 && bird.angle > 90)
    {
        //bird.angle -= 2;
    }
    if (bird.type == YELLOW_BIRD)
    {
        if (mouse_clicked(RIGHT_BUTTON))
        {
            bird.angle = 90;
            bird.speed = 25;
            bird.ultimate = true;
            play_sound_effect("jump");
        }
    }
    if (bird.type == BLACK_BIRD)
    {
        if (!bird.dead && mouse_clicked(RIGHT_BUTTON))
        {
            bird.angle = -45;
            bird.ultimate = true;
        }
    }
    
    update_bird(bird);
}
