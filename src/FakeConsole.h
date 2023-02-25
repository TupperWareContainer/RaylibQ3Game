#pragma once
#include <raylib.h>
#include <iostream>
#include "ConsoleReader.h"
using namespace std; 
class FakeConsole {
	public:
		FakeConsole(int width, int height, Color color, Vector2 pos, ConsoleReader* consoleReader);
		void onActive();
		void render();
	private:
		Vector2 pos; 
		Color color; 
		Rectangle background; 
		Rectangle blinker; 
		ConsoleReader* cReader; 
		string displayText; //used for display
		string writeOnlyText; //used for text size calculations 
		string cLineText; // used for reading console input
		unsigned int frameCounter; 
		char prompter;
		int dTextWidth; 
		int pTextWidth; 
		int newLineNum; 
		int cTextSize; 
		void checkForKeyPress(); 
};