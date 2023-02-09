#pragma once
#include <iostream>
#include <raylib.h>
#include <raymath.hpp>
using namespace std; 
class UIButton {
public:
	UIButton(string,int,int);
	void setPos(float, float); 
	void drawButton(bool); 
	bool isMouseHover(Vector2); 
private: 
	Vector2 size; 
	Vector2 pos; 
	string name; 
	bool activated; 
};
