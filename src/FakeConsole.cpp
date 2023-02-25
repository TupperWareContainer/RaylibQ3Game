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
	dTextWidth = 0; 
	pTextWidth = 0; 
	cTextSize = 0; 
	newLineNum = 0; 
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
	int allotedWidth = (int)(background.width - (background.width / 16));
	cout << "\ninputText.size() " << inputText.size() << endl;
	cout << "MeasureText input " << MeasureText(inputText.c_str(), 13) << endl;
	cout << "writeOnlyText.size() " << writeOnlyText.size() << endl;
	cout << "MeasureText writeonly " << MeasureText(writeOnlyText.c_str(), 13) << endl;
	cout << "allotedWidth: " << allotedWidth << endl;
	cout << "cTextSize: " << cTextSize << "\n" << endl;

	int key = GetCharPressed(); 
	if (key >= 32 && key <= 126) { // text size = 6;
		int textSize = MeasureText(writeOnlyText.c_str(), 13);

		dTextWidth = (textSize - pTextWidth); 
		cTextSize += dTextWidth; 
		
		if (cTextSize >= allotedWidth) {
			inputText += "\n";
			cout << "adding new line" << endl;
			newLineNum++; 
			cTextSize = 0; 
		}
		pTextWidth = textSize; 
		inputText += (char)key; 
		writeOnlyText += (char)key; 
		cout << "textSize % allotedWidth = " << textSize % allotedWidth << endl; 
	}
	if (IsKeyPressed(KEY_ENTER)) {
		inputText += "\n"; 
	}
	if (IsKeyPressed(KEY_BACKSPACE) && inputText.size() > 0) {
		if (inputText.at(inputText.size() - 1) == '\n') {
			newLineNum--;
		}
		if (newLineNum > 0) {
			cTextSize = MeasureText(writeOnlyText.c_str(), 13) / newLineNum;
		}
		writeOnlyText.pop_back();
		writeOnlyText.shrink_to_fit();
		inputText.pop_back(); 
		inputText.shrink_to_fit(); 
		
	}
}
