// #include "splashkit.h"
#include "player.h"
#include "bird.h"
#include "pig.h"
#include "game.h"
using std::vector;
/**
 * Load the game images, sounds, etc.
 */
void load_resources()
{
    load_resource_bundle("game_bundle", "game_bundle.txt");
}
/**
 * Entry point.
 *
 * Manages the initialisation of data, the event loop, and quitting.
 */
int main()
{
    open_window("Something Awesome", 1280, 720);
    load_resources();
    game_data game = new_game();
    while (not quit_requested())
    { // for the inputs of user
        process_events();
        
        clear_screen(COLOR_AQUA);
        
        draw_game(game);
        draw_game2(game);
        draw_game3(game);
        update_game(game);
        update_game2(game);
        update_game3(game);
        refresh_screen(60);
    }
    return 0;
}