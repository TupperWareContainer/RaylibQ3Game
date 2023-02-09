#include <iostream> 
#include <raylib.h> 
#include "Player.h"
#include "UI.h"
using namespace std; 

int main(int argc, char const *argv[])
{
    UI ui; 
    Player p; 
    bool test = false; 
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
        if (IsKeyPressed(KEY_T)) {
            test = !test; 
        }
        BeginDrawing();
        ClearBackground(DARKBLUE); 
        ui.setButtonActive(1, test); 
        ui.drawUIButtons(); 
        DrawText("DEBUG",(width * 0.5),(height * 0.5),20,BLACK); 
        
        
        EndDrawing(); 
    }
    CloseWindow(); 
    return 0;
}
