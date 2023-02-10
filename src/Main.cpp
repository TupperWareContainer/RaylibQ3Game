#include <iostream> 
#include <raylib.h> 
#include "UI.h"
using namespace std; 

int main(int argc, char const *argv[])
{
    UI ui; 
   
    bool bPress = false; 
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
        if (bPress) {
            ClearBackground(GREEN); 
        }
        else {
            ClearBackground(DARKBLUE); 
        }
        ui.setButtonActive(0, test); 
        if (test) {
            ui.drawUIButtons();
            if (ui.getButton(0).isMouseHover(GetMousePosition())) {
                if (IsMouseButtonPressed(0)) {
                    bPress = !bPress; 
                }
            }
        }
       
        DrawText("DEBUG",(width * 0.5),(height * 0.5),20,BLACK); 
        
        
        EndDrawing(); 
    }
    CloseWindow(); 
    return 0;
}
