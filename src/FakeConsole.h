#pragma once
#include <raylib.h>
#include <iostream>
using namespace std; 
class FakeConsole {
	public:
		FakeConsole(int width, int height, Color color, Vector2 pos);
		void onActive();
		void render();
	private:
		Vector2 pos; 
		Color color; 
		Rectangle background; 
		Rectangle blinker; 
		char prompter; 
		string displayText; 
		string writeOnlyText; //used for text size calculations 
		unsigned int frameCounter; 
		int dTextWidth; 
		int pTextWidth; 
		int newLineNum; 
		int cTextSize; 
		void checkForKeyPress(); 
};