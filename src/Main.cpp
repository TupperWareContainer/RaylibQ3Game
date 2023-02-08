#include <iostream> 
#include <raylib.h> 

using namespace std; 

int main(int argc, char const *argv[])
{
    const int width = 400;
    const int height = 400; 
    InitWindow(width,height,"Test"); 
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE); 
        DrawText("Hello World!",(width * 0.5),(height * 0.5),20,BLACK); 
        EndDrawing(); 
    }
    CloseWindow(); 
    return 0;
}
