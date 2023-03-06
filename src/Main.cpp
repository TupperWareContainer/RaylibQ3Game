#include <iostream> 
#include <string>
#include <vector>
//#include "ConnectionManager.h"
#include <raylib.h> 
#include "UI.h"
#include "FakeConsole.h"
#include "ConsoleReader.h"
#include "Base.h"
#include "BaseUnit.h" 
#include "MissionManager.h"
#include <stdlib.h>
#include "Animation2D.h"
using namespace std; 

int main(int argc, char const *argv[])
{
    SetTargetFPS(60); 
    cout << "debug testing sfzsfgsf" << (rand() % 101) << endl;
   
    Base base; 
   // BaseUnit bV[10]; 
    //ConnectionManager cm = ConnectionManager();
    bool hasRendered = false;
   /* bool test = false; 
    bool moveMode = false; 
    bool drawMode = false, canDraw = false;
    bool movingObj = false; 
    int movingObjIndex = -1; 
    unsigned int currPlacingSegment = 0; */
    string baseName; 
    int baseCapacity; 
    const int width = 800;
    const int height = 400; 
    InitWindow(width,height,"Test"); 
    UI ui = UI(width / 2, height);
    MissionManager m = MissionManager();
    BaseDev baseDev;
    ConsoleReader cr = ConsoleReader(&ui, &m,&base,&baseDev);
    ui.setMode(UIMODE::DEFAULT); 
    FakeConsole fakeConsole = FakeConsole(width / 2, height, BLACK, { width / 2.0f, 0 },&cr);
    while(!WindowShouldClose()){
        BeginDrawing();
        #pragma region Draw
        ClearBackground(BLUE);
        if (hasRendered == false) {
            cout << "Welcome to base builder!" << endl;
            cout << "Please enter the name of the base >>" << endl;
            baseName = cr.getInput();           
            cout << baseName << endl;
            cout << "Please enter the capacity of the base" << endl;
            baseCapacity = atoi(cr.getInput().c_str());
            cout << baseCapacity << endl;
            base = Base(30, baseName,width / 2,height);
            hasRendered = true;
            baseDev = BaseDev(10l,base); 
        }
        if (hasRendered) {
            fakeConsole.render(); 
            base.renderUnits(); 
            //cout << base.getMoney() << endl; 
            ui.drawUI(base,m,baseDev);
#pragma region deprecated



                // bV[0].Render(); /// IT WORKS
                /*ui.drawUIButtons(); 
                if (ui.getButton(1).isMouseHover(GetMousePosition())) {
                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                        moveMode = !moveMode;
                    }
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
                */
            
//#pragma region DRAWMODE
//                if (drawMode) {
//                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) canDraw = true; 
//                    if (currPlacingSegment == 1) {
//                        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && canDraw) {
//                            cm.setNewSegmentBeginning(GetMousePosition());
//                            cout << "setting beginning to: " << GetMousePosition().x << ", " << GetMousePosition().y << endl;
//                            currPlacingSegment++;
//                            //ClearBackground(RED);
//                            canDraw = false; 
//                        }
//                    }
//                    if (currPlacingSegment == 2) {
//                        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && canDraw) {
//                            cm.setNewSegmentEnd(GetMousePosition());
//                            currPlacingSegment++;
//                        }
//                    }
//                    if (currPlacingSegment == 3) {
//                        cm.createConnection(); 
//                        currPlacingSegment++; 
//                    }
//                    if (IsKeyPressed(KEY_S)) {
//                        cm.saveTempConnections(); 
//                        ClearBackground(GREEN); 
//                    }
//                    if (IsKeyPressed(KEY_C) || IsKeyPressed(KEY_Q)) {
//                        cm.clearTempConnections(); 
//                        ClearBackground(RED); 
//                        drawMode = false; 
//                        currPlacingSegment = 0; 
//                    }
//                    if (IsKeyPressed(KEY_D)) {
//                        cm.clearConnections();
//                        cm.clearTempConnections(); 
//                        currPlacingSegment = 0;
//                    }
//                }
//                cout << currPlacingSegment << endl; 
//                cm.renderConnections(bV);
//#pragma endregion DRAWMODE
//#pragma region MOVEMODE
//                if (moveMode) {
//                    cout << "Movemode" << endl; 
//                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
//                        cout << "Looking for movable obj" << endl;
//                        for(int i = 0; i < sizeof(bV)
//                    }
//                    else {
//                        movingObj = false; 
//                    }
//                }
//#pragma endregion
#pragma endregion
        }
            
            DrawText("DEBUG",(width * 0.016),(height * 0.016),20,BLACK); 
        #pragma endregion
        EndDrawing(); 
    }
    CloseWindow(); 
    return 0;
}
