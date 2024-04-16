#include "splashkit.h"
#include "player.h"
using namespace std;
bitmap mouse_bitmap(mouse_kind kind)
{
    switch (kind)
    {
    case FINGER:
        return bitmap_named("click");
    case HOLD:
        return bitmap_named("hold");
    default:
        return bitmap_named("click");
    }
}
player_data new_player()
{
    player_data result;
    bitmap default_bitmap = mouse_bitmap(FINGER);
    result.launch = false;
    result.level = 0;
    result.mouse_sprite = create_sprite(default_bitmap);
    sprite_add_layer(result.mouse_sprite, mouse_bitmap(HOLD), "HOLD");
    sprite_hide_layer(result.mouse_sprite, 1);
    hide_mouse();
    point_2d mouse_pos = mouse_position();
    sprite_set_position(result.mouse_sprite, mouse_pos);
    return result;  
}
void draw_mouse(const player_data &player_to_draw)
{
    draw_sprite(player_to_draw.mouse_sprite);
}
void update_player(player_data &player_to_update)
{
    point_2d mouse_pos = mouse_position();
    sprite_set_position(player_to_update.mouse_sprite, mouse_pos);
    update_sprite(player_to_update.mouse_sprite);
}
void mouse_switch(player_data &player)
{
    
    if (mouse_down(LEFT_BUTTON)  && player.kind != HOLD)
    {
        sprite_show_layer(player.mouse_sprite, static_cast<int>(1));
        
        sprite_hide_layer(player.mouse_sprite, static_cast<int>(0));
        
        player.kind = HOLD;
    }
    else if(mouse_up(LEFT_BUTTON))
    {   
        sprite_show_layer(player.mouse_sprite, static_cast<int>(0));
        sprite_hide_layer(player.mouse_sprite, static_cast<int>(1));
        player.kind = FINGER;
    }
}
bool clicked(player_data &player, sprite some)
{
    if (sprite_collision(player.mouse_sprite, some) && mouse_down(LEFT_BUTTON))
    {   
        player.launch = true;
        return true;
    }
    else
    {
        return false;
    }
}