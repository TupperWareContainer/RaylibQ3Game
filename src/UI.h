#pragma once
#include <iostream>
#include <raylib.h>
#include "UIButton.h"
using namespace std; 
class UI {
public: 
	UI(); 
	string checkForInput();
	void setButtonActive(int,bool); 
	void drawUIButtons(); 
	UIButton getButton(int); 

private:
	bool buttons[10];
	UIButton buttonObjs[10]; 
	void drawButton(int);
	

};