#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>


//update time of game
double lastUpdateTime = 0; //initial
bool EventTriggered(double interval)
{
    double currentTime = GetTime(); //gettime=second(s)
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    InitWindow(500, 620, "Tetris [Arko]");
    SetTargetFPS(60);

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    Game game = Game();

    //main game loop
    while (WindowShouldClose() == false)
    {
        UpdateMusicStream(game.music); //music plays
        
        game.HandleInput();
        if (EventTriggered(0.2)) //block freefall 200 millisecond
        {
            game.MoveBlockDown();
        }

        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE); //font,text,{position,positon},font size,spacing,color
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
        if (game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue); //{pos,pos,pos,pos},roundness,segments,color

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2); //font,text,font size,spacing between letter

        DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE); //textSize.x= weight of the text
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}