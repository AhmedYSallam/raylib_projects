#include "snake.h"

Snake::Snake()
{

}

Snake::~Snake()
{

}

void Snake::Draw()
{

    for(unsigned int i=0; i<body.size(); i++)
    {
        Rectangle rectangle = {(float)offset + body[i].x*cell_size, (float)offset + body[i].y*cell_size, (float)cell_size, (float)cell_size};
        DrawRectangleRounded(rectangle, 0.5, 6, dark_green);
    }

}

void Snake::Update()
{
    body.push_front(addPosition(body[0] , direction));
    if(addSegment==true)
    {
        addSegment = false;
    }
    else
    {
        body.pop_back();
    }

}

void Snake::UpdateDirection(bool *running)
{   
    if(IsKeyPressed(KEY_UP) && direction.y!=1)
    {
        *running = true;
        direction = {0,-1};
    }
    if (IsKeyPressed(KEY_DOWN) && direction.y!=-1)
    {
        *running = true;
        direction = {0,1};
    }
    if (IsKeyPressed(KEY_LEFT) && direction.x!=1)
    {
        *running = true;
        direction = {-1, 0};
    }
    if (IsKeyPressed(KEY_RIGHT) && direction.x!=-1)
    {
        *running = true;
        direction = {1,0};
    }
}

void Snake::Grow()
{
    addSegment = true;
}

void Snake::Reset()
{
    body = {position{6,9}, position{5,9}, position{4,9}};
    direction = {0,0};
}

bool Snake::isHeadinBody()
{
    for(int i=0; i<body.size(); i++)
    {
        if(i==0)
        {

        }
        else
        {
            if(isPositionEqual(body[i], body[0]))
            {
                return true;
            }
        }
    }
    return false;
}

