#include <iostream> 
#include <string>
#include <vector>
#include "ConnectionManager.h"
#include <raylib.h> 
#include "UI.h"
#include "ConsoleReader.h"
#include "BaseUnit.h" 
#include <stdlib.h>
using namespace std; 

// TODO: Impliment connection backend
int main(int argc, char const *argv[])
{
    
    cout << "debug testing sfzsfgsf" << (rand() % 101) << endl;
    UI ui; 
    ConsoleReader cr = ConsoleReader(); 
    BaseUnit bu; 
    vector<BaseUnit> bV = vector<BaseUnit>(); 
    bV.push_back(bu); 
    ConnectionManager cm = ConnectionManager(bV);
    bool test = false; 
    bool hasRendered = false; 
    bool moveMode = false; 
    bool drawMode = false, canDraw = false;
    unsigned int currPlacingSegment = 0; 
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
                    ui.setButtonActive(1, true); 
                    ui.setButtonActive(2, true); 
                    hasRendered = true; 
               }
            }
            if (hasRendered) {
                bu.Render(); /// IT WORKS
                ui.drawUIButtons(); 
                if (ui.getButton(1).isMouseHover(GetMousePosition())) {
                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) moveMode = !moveMode; 
                }
                if (ui.getButton(2).isMouseHover(GetMousePosition())) {
                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                        moveMode = false; 
                        drawMode = !drawMode;
                        canDraw = false; 
                        currPlacingSegment = 1; 
                        ClearBackground(BEIGE); 
                    }
                }
#pragma region DRAWMODE
                if (drawMode) {
                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) canDraw = true; 
                    if (currPlacingSegment == 1) {
                        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && canDraw) {
                            cm.setNewSegmentBeginning(GetMousePosition());
                            cout << "setting beginning to: " << GetMousePosition().x << ", " << GetMousePosition().y << endl;
                            currPlacingSegment++;
                            //ClearBackground(RED);
                            canDraw = false; 
                        }
                    }
                    if (currPlacingSegment == 2) {
                        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && canDraw) {
                            cm.setNewSegmentEnd(GetMousePosition());
                            currPlacingSegment++;
                        }
                    }
                    if (currPlacingSegment == 3) {
                        cm.createConnection(); 
                        currPlacingSegment++; 
                    }
                    if (IsKeyPressed(KEY_S)) {
                        cm.saveTempConnections(); 
                        ClearBackground(GREEN); 
                    }
                    if (IsKeyPressed(KEY_C) || IsKeyPressed(KEY_Q)) {
                        cm.clearTempConnections(); 
                        ClearBackground(RED); 
                        drawMode = false; 
                        currPlacingSegment = 0; 
                    }
                }
                cout << currPlacingSegment << endl; 
                cm.renderConnections();
#pragma endregion DRAWMODE
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && moveMode) bu.setMoveable(true);
                else bu.setMoveable(false);
                if (bu.getMovable()) {
                    bu.setPosition(GetMousePosition()); 
                }
            }
            
            DrawText("DEBUG",(width * 0.5),(height * 0.5),20,BLACK); 
        #pragma endregion
        EndDrawing(); 
    }
    CloseWindow(); 
    return 0;
}
