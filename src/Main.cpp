#include <iostream> 
#include <raylib.h> 
#include "UI.h"
#include "ConsoleReader.h"
#include "BaseUnit.h" 
#include <stdlib.h>
using namespace std; 

int main(int argc, char const *argv[])
{
    UI ui; 
    ConsoleReader cr = ConsoleReader(); 
    BaseUnit bu; 
    bool bPress = false; 
    bool test = false; 
    bool hasRendered = false; 
    string baseName; 
    int baseCapacity; 
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
        ClearBackground(BLUE);
         /*   if (bPress) {
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
                ui.drawUI(UIMODE::TEST);
                if (ui.getButton(0).isMouseHover(GetMousePosition())) {
                    if (IsMouseButtonPressed(0)) {
                        bPress = !bPress; 
                    }
                }
            }*/
       
            if (test == false) {
                if (hasRendered == false) {
                    cout << "Welcome to base builder!" << endl;
                    cout << "Please enter the name of the base >>" << endl;
                    baseName = cr.getInput();
                    cout << baseName << endl;
                    cout << "Please enter the capacity of the base" << endl;
                    baseCapacity = atoi(cr.getInput().c_str());
                    cout << baseCapacity << endl;
                    bu = BaseUnit(UNITTYPE::Command, baseCapacity, 30, 30);
                  
                    hasRendered = true; 
               }
            }
            if (hasRendered) {
                bu.Render(); /// IT WORKS
            }
            
            DrawText("DEBUG",(width * 0.5),(height * 0.5),20,BLACK); 
        #pragma endregion
        EndDrawing(); 
    }
    CloseWindow(); 
    return 0;
}
