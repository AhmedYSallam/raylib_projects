#ifndef COMMON
#define COMMON

#include <iostream>
#include <raylib.h>
#include <random>
#include <vector>
#include <chrono>
#include <deque>

extern Color background;
extern Color dark_green;

extern Rectangle rectangle;

extern int cell_size;
extern int num_cells;
extern int offset;
extern int window_size;

extern double lastUpdateTime;
extern double interval;

struct position{
        int x;
        int y;
};

position addPosition(position pos1, position pos2);
bool eventTriggered(double sec);
bool isPositionEqual(position pos1, position pos2);
bool isDequeinPos(std::deque<position> body, position new_pos);

#endif