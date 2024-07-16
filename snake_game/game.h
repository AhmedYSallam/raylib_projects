#ifndef GAME
#define GAME

#include "snake.h"
#include "food.h"

class Game
{
public:
    Snake snake;
    Food food;
    bool run = true;
    int score = 0;

    void Draw();
    void Update();
    void Collision();
    void CheckCollisionWithBorder();
    void GameOver();
};

#endif