#pragma once
#include <iostream>
#include <raylib.h>
#include "UIButton.h"
using namespace std; 
enum class UIMODE {
	TEST,
};
class UI {
public: 
	UI(); 
	//string checkForInput();
	void setButtonActive(int,bool);
	void drawUIButtons();
	UIButton getButton(int); 
	void drawUI(UIMODE);
private:
	bool buttons[10];
	UIButton buttonObjs[10]; 
	//void drawButton(int);

};

