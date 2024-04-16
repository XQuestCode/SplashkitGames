#ifndef ANGRY_BIRDS_PIG
#define ANGRY_BIRDS_PIG
#include "splashkit.h"
#include <vector>
using namespace std;
enum pig_kind
{
    PING,
    KING
};
struct pig_data
{
    pig_kind kind;
    sprite pig_sprite;
};
pig_data new_pig(double x, double y);
void draw_pig(pig_data &pig);
void update_pig(pig_data &pig);
#endif