#pragma once
#include <iostream>
#include <raylib.h>
#include <sstream>
#include "UIButton.h"
#include "Base.h"
#include "GameFonts.h"; 

using namespace std; 
enum class UIMODE {
	TEST,
	MOVE,
	DEFAULT,
	STATS,
	MISSION
};
class UI {
public: 
	UI(); 
	UI(int allotedWidth, int allotedHeight); 
	//string checkForInput();
	void setButtonActive(int,bool);
	void drawUIButtons();
	UIButton getButton(int); 
	void drawUI(Base b);
	void setMode(UIMODE mode);
	void printDefaultMenu(); 
private:
	bool buttons[10];
	UIButton buttonObjs[10]; 
	UIMODE uiMode; 
	//void drawButton(int);
	int sectionWidth; 
	int sectionHeight;
	GameFonts g; 
};

