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
		string inputText; 
		unsigned int frameCounter; 
		void checkForKeyPress(); 
};