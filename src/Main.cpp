#include <iostream> 
#include <raylib.h> 
#include "Player.h"
using namespace std; 

int main(int argc, char const *argv[])
{
    Player p; 
    const int width = 400;
    const int height = 400; 
    const int moveSpeed = 2000; 
    int dX = 0, dY = 0;
    InitWindow(width,height,"Test"); 
    while(!WindowShouldClose()){
        if(IsKeyDown(KEY_UP)){
            dY -= moveSpeed * GetFrameTime(); 
        }
        if(IsKeyDown(KEY_DOWN)){
            dY +=moveSpeed * GetFrameTime(); 
        }
        if(IsKeyDown(KEY_LEFT)){
            dX -= moveSpeed * GetFrameTime(); 
        }
        if(IsKeyDown(KEY_RIGHT)){
            dX += moveSpeed * GetFrameTime(); 
        }
       
        BeginDrawing();
        ClearBackground(WHITE); 
        DrawText("Hello World!",(width * 0.5),(height * 0.5),20,BLACK); 
        
        p.setPosition(dX,dY);
        p.renderPlayer(); 
        EndDrawing(); 
    }
    CloseWindow(); 
    return 0;
}
