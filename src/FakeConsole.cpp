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
	blinker.height = 8; 
	blinker.x = background.x + background.width / 16; 
	blinker.y = background.y + background.height / 16; 

}
void FakeConsole::render() {
	DrawRectangle(background.x, background.y, background.width, background.height, color); 
	//DrawRectangle()
}
