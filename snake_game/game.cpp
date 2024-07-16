#include "game.h"

void Game::Draw()
{
    food.Draw();
    snake.Draw();
}

void Game::Update()
{
    if(run==true)
    {
        snake.Update();
        Collision();
        CheckCollisionWithBorder();        
    }

}

void Game::Collision()
{
    if(isPositionEqual(snake.body[0], *(food.getPos())))
    {
        food.Eaten(snake.body);
        snake.Grow();
        score++;
    }
    if(snake.isHeadinBody())
    {
        GameOver();
    }
}

void Game::CheckCollisionWithBorder()
{
    if(snake.body[0].x == num_cells || snake.body[0].x == -1)
    {
        GameOver();
    }
    if(snake.body[0].y == num_cells || snake.body[0].y == -1)
    {
        GameOver();  
    }
}

void Game::GameOver()
{
    snake.Reset();
    food.RandomPos(food.getPos());
    run = false;
    score = 0;
}

