#include "splashkit.h"
#include "game.h"

#include <vector>
using namespace std;
using std::vector;
void setup(game_data &game)
{

    if (game.player.level == 1)
    {
        pig_data a, b, c;
        a = new_pig(600, 567);
        b = new_pig(900, 500);
        c = new_pig(1100, 500);
        if (game.pigs.size() == 0)
        {
            game.pigs.push_back(a);
            game.pigs.push_back(b);
            game.pigs.push_back(c);
        }
    }
    else if (game.player.level == 2)
    {
        box_data a, b, c, d, e;
        pig_data p, q, r, s, t;
        a = new_box(600, 567);
        b = new_box(900, 490);
        c = new_box(900, 420);
        d = new_box(900, 340);
        e = new_box(950, 500);

        p = new_pig(600, 494);
        q = new_pig(980, 500);
        r = new_pig(500, 567);
        s = new_pig(900, 280);
        t = new_pig(1100, 500);
        if (game.boxes.size() == 0)
        {
            game.boxes.push_back(a);
            game.boxes.push_back(b);
            game.boxes.push_back(c);
            game.boxes.push_back(d);
            game.boxes.push_back(e);
        }
        if (game.pigs.size() == 0)
        {
            game.pigs.push_back(p);
            game.pigs.push_back(q);
            game.pigs.push_back(r);
            game.pigs.push_back(s);
            game.pigs.push_back(t);
        }
    }
    else if (game.player.level == 3)
    {
        box_data a, b, c, d, e, f, g;
        pig_data p, q, r, s, t, u, v;
        a = new_box(600, 567);
        b = new_box(900, 490);
        c = new_box(900, 420);
        d = new_box(900, 340);
        e = new_box(950, 500);
        f = new_box(700, 200);
        g = new_box(630, 260);

        p = new_pig(600, 494);
        q = new_pig(980, 500);
        r = new_pig(500, 567);
        s = new_pig(900, 280);
        t = new_pig(1100, 500);
        u = new_pig(700, 120);
        v = new_pig(630, 180);

        cage_data x, y;
        x = new_cage(700, 280);
        y = new_cage(630, 340);
        if (game.boxes.size() == 0)
        {
            game.boxes.push_back(a);
            game.boxes.push_back(b);
            game.boxes.push_back(c);
            game.boxes.push_back(d);
            game.boxes.push_back(e);
            game.boxes.push_back(f);
            game.boxes.push_back(g);
        }
        if (game.pigs.size() == 0)
        {
            game.pigs.push_back(p);
            game.pigs.push_back(q);
            game.pigs.push_back(r);
            game.pigs.push_back(s);
            game.pigs.push_back(t);
            game.pigs.push_back(u);
            game.pigs.push_back(v);
        }
        if (game.cages.size() == 0)
        {
            game.cages.push_back(x);
            game.cages.push_back(y);
        }
    }
}
game_data new_game()
{
    game_data game;
    game.player = new_player();
    game.game_timer = create_timer("TIMER");
    start_timer(game.game_timer);
    game.current_bird = new_bird(RED, 155, 390);
    game.screen = 1;
    game.intro_played = false;
    // setup(game);
    return game;
}

void launch(game_data &game)
{
    if (game.screen == 3)
    {
        point_2d mouse_pos = mouse_position();
        if (clicked(game.player, game.current_bird.bird_sprite))
        {
            if(mouse_pos.x < 250) {
            sprite_set_x(game.current_bird.bird_sprite, mouse_pos.x + 7);
            sprite_set_y(game.current_bird.bird_sprite, mouse_pos.y - 7);
            game.player.launch = true;
            } 
        }
        if (game.player.launch && mouse_up(LEFT_BUTTON) && mouse_pos.y > 250)
        {
            point_2d abc = sprite_position(game.current_bird.bird_sprite);
            const double distance = point_point_distance(point_at(155, 390), abc);
            const double angle = point_point_angle(point_at(155, 390), abc);

            write_line("Distance: " + to_string(distance));
            write_line("Angle: " + to_string(angle - 180));

            game.current_bird.angle = angle - 180;
            if (distance < 200)
            {
                game.current_bird.speed = distance / 6.5;
            }
            else
            {
                game.current_bird.speed = 40;
            }
            game.projected_birds.push_back(game.current_bird);
            // sprite_hide_layer(game.current_bird.bird_sprite, 0);
            game.current_bird.angle = 0;
            game.player.launch = false;
        }
    }
}
void cloud_animation(double x, double y)
{
    timer smh = create_timer("TIMER");
    start_timer(smh);
    if (timer_ticks(smh) < 200)
    {
        draw_bitmap("cloud1", x, y);
    }
    else if (timer_ticks(smh) >= 200 && timer_ticks(smh) < 400)
    {
        draw_bitmap("cloud2", x, y);
    }
    else if (timer_ticks(smh) >= 400 && timer_ticks(smh) < 600)
    {
        draw_bitmap("cloud3", x, y);
    }
    else if (timer_ticks(smh) >= 600 && timer_ticks(smh) < 800)
    {
        draw_bitmap("cloud4", x, y);
    }
    else if (timer_ticks(smh) >= 800 && timer_ticks(smh) < 1000)
    {
        draw_bitmap("cloud5", x, y);
    }
    else
    {
        free_timer(smh);
    }
}
void menu_bird(game_data &game)
{
    bird_data red = new_bird(RED, 40, 50);
    red.kind = RED;
    bird_data yellow = new_bird(YELLOW, 40, 150);
    yellow.kind = YELLOW;
    bird_data black = new_bird(BLACK, 40, 250);
    black.kind = BLACK;
    if (game.loaded_birds.size() <= 3)
    {
        game.loaded_birds.push_back(red);
        game.loaded_birds.push_back(yellow);
        game.loaded_birds.push_back(black);
    }
}

void collision_pigs(game_data &game)
{
    if (game.pigs.size() > 0 && game.projected_birds.size() > 0)
    {
        for (int i = 0; i < game.pigs.size(); i++)
        {

            if (sprite_collision(game.projected_birds[game.projected_birds.size() - 1].bird_sprite, game.pigs[i].pig_sprite))
            {
                // double x = sprite_x(game.pigs[i].pig_sprite);
                // double y = sprite_y(game.pigs[i].pig_sprite);
                // cloud_animation(x, y);
                game.pigs[i] = game.pigs[game.pigs.size() - 1];
                game.pigs.pop_back();
            }
        }
    }
}
void collision_boxes(game_data &game)
{
    if (game.boxes.size() > 0 && game.projected_birds.size() > 0)
    {
        for (int i = 0; i < game.boxes.size(); i++)
        {

            if (sprite_collision(game.projected_birds[game.projected_birds.size() - 1].bird_sprite, game.boxes[i].box_sprite))
            {
                // double x = sprite_x(game.pigs[i].pig_sprite);
                // double y = sprite_y(game.pigs[i].pig_sprite);
                // cloud_animation(x, y);
                if (!game.projected_birds[game.projected_birds.size() - 1].tune_played)
                {
                    play_sound_effect("ball");
                    game.projected_birds[game.projected_birds.size() - 1].tune_played = true;
                }
                game.projected_birds[game.projected_birds.size() - 1].angle = 90;
            }
        }
    }
}
void collision_cages(game_data &game)
{
    if (game.cages.size() > 0 && game.projected_birds.size() > 0)
    {
        for (int i = 0; i < game.cages.size(); i++)
        {
            if (sprite_collision(game.projected_birds[game.projected_birds.size() - 1].bird_sprite, game.cages[i].cage_sprite))
            {
                game.cages[i].some = true;
                new_fb_bird(game.cages[i]);
            }
            if (game.cages[i].some)
            {
                sprite_hide_layer(game.cages[i].cage_sprite, 0);

                update_fb_bird(game.cages[i]);
                draw_fb_bird(game.cages[i]);

                game.cages[i] = game.cages[game.cages.size() - 1];
                if (sprite_x(game.cages[i].fb_bird_sprite) < 0 || sprite_y(game.cages[i].fb_bird_sprite) > 720)
                {
                    game.cages.pop_back();
                }
            }
            else
            {

                update_cage(game.cages[i]);
                draw_cage(game.cages[i]);
            }
        }
    }
}
void update_game(game_data &game)
{
    mouse_switch(game.player);
    update_player(game.player);
    launch(game);

    // draw_projectile(game);

    if (game.projected_birds.size() > 0)
    {
        for (int i = 0; i < game.projected_birds.size(); i++)
        {
            update_bird(game.projected_birds[i]);
            bird_projectile(game.projected_birds[i]);

            draw_bird(game.projected_birds[i]);
        }
    }
}
void update_game2(game_data &game)
{

    menu_bird(game);
    for (int i = 0; i < game.loaded_birds.size(); i++)
    {
        if (clicked(game.player, game.loaded_birds[i].bird_sprite) && game.projected_birds.size() > 0 && game.projected_birds[game.projected_birds.size() - 1].dead)
        {

            game.current_bird = new_bird(game.loaded_birds[i].kind, 155, 390);
            game.current_bird.angle = game.projected_birds[game.projected_birds.size() - 1].angle;
        }
    }
    for (int j = 0; j < game.pigs.size(); j++)
    {
        update_pig(game.pigs[j]);
    }
}
void update_game3(game_data &game)
{
    if (key_typed(ESCAPE_KEY))
    {
        game = new_game();
        play_sound_effect("back");
        game.screen = 2;
    }
    for (int i = 0; i < game.boxes.size(); i++)
    {
        update_box(game.boxes[i]);
    }
    collision_pigs(game);
    collision_boxes(game);
    collision_cages(game);
}
void draw_start(game_data &game)
{
    draw_bitmap("loading", 0, 0, option_to_screen());
    if (!game.intro_played)
    {
        play_sound_effect("theme", 1);
        game.intro_played = true;
    }
    draw_text("Click to Start", COLOR_WHITE, "angry", 100, 417, 580, option_to_screen());
}
void draw_selection(game_data &game)
{
    draw_bitmap("selection", 0, 0, option_to_screen());
    draw_text("Click to Select the level", COLOR_WHITE, "angry", 100, 217, 80, option_to_screen());
    sprite level1, level2, level3;
    level1 = create_sprite(bitmap_named("button1"));
    sprite_set_x(level1, 230);
    sprite_set_y(level1, 300);
    draw_sprite(level1);
    level2 = create_sprite(bitmap_named("button2"));
    sprite_set_x(level2, 500);
    sprite_set_y(level2, 150);
    draw_sprite(level2);
    level3 = create_sprite(bitmap_named("button3"));
    sprite_set_x(level3, 1000);
    sprite_set_y(level3, 250);
    draw_sprite(level3);
    if (clicked(game.player, level1))
    {
        game.player.level = 1;
        game.screen++;
        play_sound_effect("select");
    }
    else if (clicked(game.player, level2))
    {
        game.player.level = 2;
        game.screen++;
        play_sound_effect("select");
    }
    else if (clicked(game.player, level3))
    {
        game.player.level = 3;
        game.screen++;
        play_sound_effect("select");
    }
}
void draw_stars(game_data game)
{
    if (game.player.level == 1)
    {
        int count = 3 - game.pigs.size();

        if (count > 0)
        {
            draw_bitmap("starleft", 375, 85);
        }
        if (count > 1)
        {
            draw_bitmap("starcenter", 548, 56);
        }
        if (count > 2)
        {
            draw_bitmap("starright", 724, 85);

            draw_text("Press escape to go back", COLOR_YELLOW, "angry", 50, 400, 260);
        }
    }
    else if (game.player.level == 2)
    {
        int count = 5 - (game.pigs.size());
        if (count > 0)
        {
            draw_bitmap("starleft", 375, 85);
        }
        if (count > 2)
        {
            draw_bitmap("starcenter", 548, 56);
        }
        if (count > 4)
        {
            draw_bitmap("starright", 724, 85);

            draw_text("Press escape to go back", COLOR_YELLOW, "angry", 50, 400, 260);
        }
    }
    else if (game.player.level == 3)
    {
        int star = 0;
        if (game.pigs.size() == 0)
        {
            star += 2;
        }

        if (game.cages.size() == 0)
        {
            star++;
        }
        if (star > 0)
        {
            draw_bitmap("starleft", 375, 85);
        }
        if (star > 1)
        {
            draw_bitmap("starcenter", 548, 56);
        }
        if (star > 2)
        {
            draw_bitmap("starright", 724, 85);
            play_sound_effect("star");
        }

        draw_text("Press escape to go back", COLOR_YELLOW, "angry", 50, 400, 260);
    }
}
void draw_game(game_data &game)
{

    if (game.screen == 1)
    {
        draw_start(game);
        if (mouse_clicked(LEFT_BUTTON))
        {
            play_sound_effect("confirm");
            game.screen++;
        }
    }
    else if (game.screen == 2)
    {
        draw_selection(game);
        setup(game);
    }
    else
    {
        draw_bitmap("bg", 0, 0, option_to_screen());
        if (!game.player.launch)
            draw_bitmap("launcher", 165, 380, option_to_screen());
        else
        {
            if (!game.current_bird.dead)
            {
                draw_bitmap("launcher2", 125, 400, option_to_screen());

                draw_line(COLOR_SADDLE_BROWN, 157, 435, sprite_x(game.current_bird.bird_sprite) + 40, sprite_y(game.current_bird.bird_sprite) + 40, option_line_width(12));
            }
        }
        draw_stars(game);
        draw_bird(game.current_bird);
    }
    draw_mouse(game.player);
}
void draw_game2(game_data &game)
{
    if (game.screen == 1)
    {
    }
    else if (game.screen == 2)
    {
    }
    else
    {
        for (int i = 0; i < game.pigs.size(); i++)
        {
            draw_pig(game.pigs[i]);
        }
        for (int j = 0; j < game.loaded_birds.size(); j++)
        {
            draw_bird(game.loaded_birds[j]);
        }
    }
}
void draw_game3(game_data &game)
{
    if (game.screen == 1)
    {
    }
    else if (game.screen == 2)
    {
    }
    else
    {
        for (int k = 0; k < game.boxes.size(); k++)
        {
            draw_box(game.boxes[k]);
        }
    }
}