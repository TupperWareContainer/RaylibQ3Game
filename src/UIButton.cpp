#include "UIButton.h"
#include <raylib.h>
#include <raymath.hpp>

using namespace std; 
Vector2 pos = { 0,0 };
Vector2 size = { 10,10 };
string name; 
UIButton::UIButton(string name, int width, int height) {
	
	this->name = name; 
	size.x = (float)width; 
	size.y = (float)height; 
	
}
void UIButton::setPos(float posX, float posY) {
	pos.x = posX; 
	pos.y = posY; 
}
void UIButton::drawButton(bool active) {
	if (active) { 
		DrawRectangleV(pos, size, BLACK); 
		DrawText(name.c_str(), (int)pos.x, (int)pos.y, 10, WHITE);
	}
}
