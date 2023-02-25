#pragma once
#include <iostream>
#include <raylib.h>
#include "UIButton.h"
using namespace std; 
enum class UIMODE {
	TEST,
	MOVE,
	DEFAULT
};
class UI {
public: 
	UI(int allotedWidth, int allotedHeight); 
	//string checkForInput();
	void setButtonActive(int,bool);
	void drawUIButtons();
	UIButton getButton(int); 
	void drawUI(UIMODE);
	void printDefaultMenu(); 
private:
	bool buttons[10];
	UIButton buttonObjs[10]; 
	//void drawButton(int);
	int sectionWidth; 
	int sectionHeight; 
};

