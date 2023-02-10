#include <iostream> 
#include <raylib.h> 
#include "UI.h"
#include "ConsoleReader.h"
using namespace std; 

int main(int argc, char const *argv[])
{
    UI ui; 
    ConsoleReader cr = ConsoleReader(); 
    bool bPress = false; 
    bool test = false; 
    const int width = 400;
    const int height = 400; 
    const int moveSpeed = 2000; 
    int dX = 0, dY = 0;
    InitWindow(width,height,"Test"); 
    while(!WindowShouldClose()){
        if (IsKeyPressed(KEY_T)) {
            test = !test; 
        }
        BeginDrawing();
        #pragma region Draw
            if (bPress) {
                ClearBackground(GREEN); 
            }
            else {
                ClearBackground(DARKBLUE); 
            }
            if (!test) {
                cout << "Please enter \"test\"\n";
                if (cr.getInput().compare("test") == 0) {
                    test = !test;
                }
            }
            
            if (test) {
                ui.drawUIButtons();
                if (ui.getButton(0).isMouseHover(GetMousePosition())) {
                    if (IsMouseButtonPressed(0)) {
                        bPress = !bPress; 
                    }
                }
            }
      
            DrawText("DEBUG",(width * 0.5),(height * 0.5),20,BLACK); 
        #pragma endregion
        EndDrawing(); 
    }
    CloseWindow(); 
    return 0;
}
