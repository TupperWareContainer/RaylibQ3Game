#include "FakeConsole.h"
#include <raylib.h>
#include <iostream>
using namespace std;

FakeConsole::FakeConsole(int width, int height, Color color,Vector2 pos) {
	background.width = width; 
	background.height = height; 
	background.x = pos.x; 
	background.y = pos.y; 
	this->color = color; 
	this->pos = pos; 
	prompter = '>'; 
	blinker.width = 16;
	blinker.height = 4; 
	blinker.x = background.x + background.width / 16; 
	blinker.y = background.y + background.height / 16; 
	frameCounter = 0;
}
void FakeConsole::render() {
	checkForKeyPress(); 
	DrawRectangle(background.x, background.y, background.width, background.height, color); 
	frameCounter++; 
	DrawText(inputText.c_str(), blinker.x, blinker.y - 13, 13, RAYWHITE); 
	if (frameCounter >= GetFPS() * 2) {
		DrawRectangle(blinker.x, blinker.y, blinker.width, blinker.height, RAYWHITE);
		
	}
	if (frameCounter >= GetFPS() * 4) {
		frameCounter = 0;
	}
	
}
void FakeConsole::checkForKeyPress() {
	
	cout << (int)(background.width - (background.width / 16)) << endl;
	cout << MeasureText(inputText.c_str(), 12) << endl;
	int key = GetCharPressed(); 
	if (key >= 32 && key <= 126) { // text size = 6; 
		int textSize = 0; 
		int textSize = MeasureText(inputText.c_str(), 13);
		
		int allotedWidth = (int)(background.width - (background.width / 16));
		
		if (textSize < allotedWidth) {
			if (textSize > allotedWidth) {
				inputText += "\n";
				cout << "adding new line" << endl;
			}

		}
		
		inputText += (char)key; 
		cout << "textSize % allotedWidth = " << textSize % allotedWidth << endl; 
	}
	if (IsKeyPressed(KEY_ENTER)) {
		inputText += "\n"; 
	}
	if (IsKeyPressed(KEY_BACKSPACE) && inputText.size() > 0) {
		inputText.pop_back(); 
		inputText.shrink_to_fit(); 
	}
}
