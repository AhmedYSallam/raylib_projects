#include "game.h"

int main()
{
    std::cout << "starting game" << "\n";
    InitWindow(window_size, window_size, "Snake Game");

    Game game;

    SetTargetFPS(60);
    while(WindowShouldClose()==false)
    {
        BeginDrawing();

        ClearBackground(background);
        DrawRectangleLinesEx(rectangle,5,dark_green);
        DrawText("Snake Game", offset-5, 20, 40, BLACK);
        DrawText(TextFormat("%i", game.score), offset-5, (offset+5) + cell_size*num_cells, 40, BLACK);
        game.Draw();
        if(eventTriggered(interval))
        {
            game.Update();
        }
        game.snake.UpdateDirection(&(game.run));
        EndDrawing();
    }

    CloseWindow();
} 