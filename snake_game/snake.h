#ifndef SNAKE
#define SNAKE

#include "commonUtils.h"

class Snake
{
private:
    //we can use Vector2 position = {x, y} instead but lets do it from scratch
    position direction = {0,0};
    bool addSegment = false;

public:
    std::deque<position> body = {position{6,9}, position{5,9}, position{4,9}};

    Snake();
    ~Snake();
    void Draw();
    void Update();
    void UpdateDirection(bool *running);
    void Grow();
    void Reset();
    bool isHeadinBody();

};

#endif