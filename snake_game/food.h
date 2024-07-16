#ifndef FOOD
#define FOOD

#include "commonUtils.h"

class Food
{
private:

    position pos;
    Texture2D texture;

public:

    Food();
    ~Food();
    void Draw();
    void Eaten(std::deque<position> body);
    position RandomPos(std::deque<position> body);
    void RandomPos(position* pose);
    position RandomPos();
    position* getPos();
    bool isNewPosInSnake(std::deque<position> body, position new_pos);

};

#endif