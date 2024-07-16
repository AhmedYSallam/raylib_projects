#include "food.h"

Food::Food()
{
    Image image = LoadImage("graphics/apple.png"); // returns an image, in raylib an image contains pixel data of graphical image
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
    pos = RandomPos();
}

Food::~Food()
{
    UnloadTexture(texture);
}

void Food::Draw()
{
    //DrawRectangle(pos.x*cell_size, pos.y*cell_size, cell_size, cell_size, dark_orange);
    DrawTexture(texture, offset + pos.x*cell_size, offset + pos.y*cell_size, WHITE); // draw the texture
}

position Food::RandomPos(std::deque<position> body)
{
    int min = 0;
    int max = num_cells-1;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min, max);
    int x = distr(gen);
    int y = distr(gen);
    position tmp = {x,y};
    while(isNewPosInSnake(body, tmp))
    {
        x = distr(gen);
        y = distr(gen);
        tmp = {x,y};
    }
    return tmp;
    
}
void Food::RandomPos(position* pose)
{
    int min = 0;
    int max = num_cells-1;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min, max);
    int x = distr(gen);
    int y = distr(gen);
    *pose = {x,y};
}

position Food::RandomPos()
{
    int min = 0;
    int max = num_cells-1;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min, max);
    int x = distr(gen);
    int y = distr(gen);
    position tmp = {x,y};
    return tmp;
    
}

position* Food::getPos()
{
    return &pos;
}

void Food::Eaten(std::deque<position> body)
{
    pos = RandomPos(body);
}

bool Food::isNewPosInSnake(std::deque<position> body, position new_pos)
{
    for(int i=0; i<body.size(); i++)
    {
        if(isPositionEqual(body[i], new_pos))
        {
            return true;
        }
    }
    return false;
}


