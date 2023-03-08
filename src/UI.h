#pragma once
#include <iostream>
#include <raylib.h>
#include <sstream>
#include "UIButton.h"
#include "BaseUnit.h"
#include "Base.h"
#include "GameFonts.h" 
#include "MissionManager.h"
#include "BaseDev.h"
#include <vector>

using namespace std; 
enum class UIMODE {
	TEST = 0,
	MOVE = 1,
	DEFAULT = 2,
	STATS = 3,
	MISSION = 4,
	UNITBUILDER = 5, 
	POPDISPLAY = 6,
	GSTATS = 7
};
class UI {
public: 
	UI(); 
	UI(int allotedWidth, int allotedHeight); 
	//string checkForInput();
	void setButtonActive(int,bool);
	void drawUIButtons();
	UIButton getButton(int); 
	void drawUI(Base b, MissionManager m,BaseDev baseDev);
	void setMode(UIMODE mode);
	void printDefaultMenu(); 
	void setGorbToDisplay(int gorbNum); 
	int getMode();
	void setDisplayGorbStats(bool b); 
private:
	bool buttons[10];
	UIButton buttonObjs[10]; 
	string loadMessage; 
	UIMODE uiMode; 
	//void drawButton(int);
	int sectionWidth; 
	int sectionHeight;
	GameFonts g; 
	string gorbString; 
	int gorbToDisplay; 
	vector<Gorb> gorbVector; 
	bool displayGorbStats; 
};

