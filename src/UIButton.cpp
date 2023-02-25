#include "UIButton.h"
#include <raylib.h>
#include <raymath.hpp>

using namespace std; 

UIButton::UIButton()
{
	this->name = "test";
	size.x = 50;
	size.y = 30; 
	buttonRect = Rectangle();
	buttonRect.x = pos.x;
	buttonRect.y = pos.y;
	buttonRect.width = size.x;
	buttonRect.height = size.y;
}
UIButton::UIButton(string name, int width, int height) {
	
	this->name = name; 
	size.x = (float)width; 
	size.y = (float)height; 
	buttonRect = Rectangle();
	buttonRect.x = pos.x;
	buttonRect.y = pos.y;
	buttonRect.width = size.x;
	buttonRect.height = size.y;
	
}
void UIButton::setPos(float posX, float posY) {
	pos.x = posX; 
	pos.y = posY; 
	buttonRect.x = posX; 
	buttonRect.y = posY; 
}
void UIButton::drawButton(bool active) {
	if (active) {
		DrawRectangle(pos.x, pos.y, size.x, size.y, BLACK);
		DrawText(name.c_str(), (int)pos.x, (int)pos.y, 10, WHITE);
	}
	//else cout << "button not active" << endl; 
}
bool UIButton::isMouseHover(Vector2 mousePos) {
	return CheckCollisionPointRec(mousePos, buttonRect); 
}
