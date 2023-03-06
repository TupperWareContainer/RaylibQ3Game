#include "UI.h"
#include <iostream>
#include <raylib.h>
#include <sstream>
#include "UIButton.h"
#include "Base.h"
#include "GameFonts.h"; 
#include "BaseUnit.h"
#include "MissionManager.h"

using namespace std; 
UI::UI() {
	
	buttonObjs[0] = UIButton("test", 50, 10);
	buttonObjs[1] = UIButton("Move", 50, 10);
	buttonObjs[2] = UIButton("Draw", 50, 10);
	buttonObjs[0].setPos(50, 50);
	buttonObjs[1].setPos(300, 300);
	buttonObjs[2].setPos(300, 350);
	gorbToDisplay = 0; 
	displayGorbStats = false; 
	uiMode = UIMODE::DEFAULT;
}
UI::UI(int allotedWidth, int allotedHeight) {
	buttonObjs[0] = UIButton("test", 50, 10);
	buttonObjs[1] = UIButton("Move", 50, 10); 
	buttonObjs[2] = UIButton("Draw", 50, 10); 
	buttonObjs[0].setPos(50, 50); 
	buttonObjs[1].setPos(300, 300); 
	buttonObjs[2].setPos(300, 350); 
	sectionWidth = allotedWidth; 
	sectionHeight = allotedHeight; 
	gorbToDisplay = 0; 
	displayGorbStats = false;
	uiMode = UIMODE::DEFAULT; 
}
void UI::setButtonActive(int button, bool active) 
{
	buttons[button] = active; 
	//cout << "setButtonActive(): button activated!" << endl; 
}

void UI::drawUIButtons() 
{
	//cout << "drawing ui buttons"; 
	for (int i = 0; i < sizeof(buttons); i++) {
		//cout << "drawing button no " << i << endl; 
		buttonObjs[i].drawButton(buttons[i]);
	}
}
//void UI::drawButton(int button) {
//	switch (button) {
//	case 1:
//		buttonObjs[0].setPos(50, 50);
//		buttonObjs[0].drawButton(true); 
//	}
//}
UIButton UI::getButton(int button) {
	return buttonObjs[button]; 
}
void UI::printDefaultMenu() {
	cout << "What would you like to do?" << endl; 
	cout << "" << endl; 
}
void UI::setMode(UIMODE mode) {
	uiMode = mode; 
	cout << "UIMODE change recieved" << endl; 
}
void UI::drawUI(Base b,MissionManager m,BaseDev baseDev) {
	switch (uiMode)
	{
		case UIMODE::TEST:
			buttonObjs[0].drawButton(true); 
			break;
		case UIMODE::MOVE:
			buttonObjs[0].drawButton(true); 
			break; 
		case UIMODE::DEFAULT:
			DrawText("[L]ist Stats\n[M]issions\n[B]ase Development\n[V]iew Pops", sectionWidth / 16, sectionHeight / 16,15,BLACK); 
			break; 
		case UIMODE::STATS:
		{ //what the fuck 
			
			DrawRectangle(sectionWidth / 16, sectionHeight / 16, 100, 100, BLACK);
			DrawTextEx(g.boldFont, "Stats:", { (float)sectionWidth / 16, (float)sectionHeight / 16 }, 18, 0, BLUE);
			DrawTextEx(g.boldFont, ("Name: " + b.getName()).c_str(), { (float)sectionWidth / 16, ((float)sectionHeight / 16 + 15) }, 15, 0, LIME);
			stringstream sStream; 
			sStream << "Capacity: " << b.getCapacity();
			DrawTextEx(g.boldFont, sStream.str().c_str(), { (float)sectionWidth / 16, ((float)sectionHeight / 16 + 30) }, 15, 0, LIME);
			sStream.str("");
			sStream << "Pops: " << b.getNumGorbs(); 
			DrawTextEx(g.boldFont, sStream.str().c_str(), { (float)sectionWidth / 16, ((float)sectionHeight / 16 + 45) }, 15, 0, LIME); 
			sStream.str("");
			sStream << "Units: " << b.getNumUnits(); 
			DrawTextEx(g.boldFont, sStream.str().c_str(), { (float)sectionWidth / 16, ((float)sectionHeight / 16 + 60) }, 15, 0, LIME);
			sStream.str(""); 
			sStream << "Money: " << b.getMoney(); 
			DrawTextEx(g.boldFont, sStream.str().c_str(), { (float)sectionWidth / 16, ((float)sectionHeight / 16 + 75) }, 15, 0, LIME);
			sStream.str(""); 
			cout << "Rendering Stat Mode" << endl;
			break;
		}
		case UIMODE::MISSION:
		{
			DrawRectangle(sectionWidth / 16, sectionHeight / 16, 270,130, BLACK);
			DrawTextEx(g.boldFont, "Missions:", { (float)sectionWidth / 16, (float)sectionHeight / 16 }, 18, 0, RED);
			DrawTextEx(g.boldFont, m.getMissionStrings().c_str(), { (float)sectionWidth / 16, (float)sectionHeight / 16 +15}, 15, 0, LIME);
			break; 
		}
		case UIMODE::UNITBUILDER:
		{
			DrawRectangle(sectionWidth / 16, sectionHeight / 16, 270, 130, BLACK);
			DrawTextEx(g.boldFont, "Units:", { (float)sectionWidth / 16, (float)sectionHeight / 16 }, 18, 0, ORANGE);
			DrawTextEx(g.boldFont, baseDev.getUnitStrings().c_str(), { (float)sectionWidth / 16, (float)sectionHeight / 16 + 15 }, 15, 0, LIME);
			break; 
		}
		case UIMODE::POPDISPLAY:
		{
			DrawRectangle(sectionWidth / 16, sectionHeight / 16, 270, 130, BLACK); 
			DrawTextEx(g.boldFont, "Pops:", { (float)sectionWidth / 16, (float)sectionHeight / 16 }, 18, 0,  YELLOW);
			gorbVector = *b.getGorbs();
			int gorbHeight = 0, gorbWidth = 0;
			int gorbNum = 0; 
			for each (Gorb gorb in gorbVector)
			{ 
				gorbString.clear();
				gorbString = to_string(gorbNum);
				gorb.renderGorb((sectionWidth / 16) + 16* gorbWidth, ((sectionHeight / 16) + 16) + 16 * gorbHeight);
				DrawTextEx(g.boldFont, gorbString.c_str(), { (float)(((sectionWidth / 16)) + 16 * gorbWidth), (float)(((sectionHeight / 16) + 16) + 16 * gorbHeight) },12,0,RAYWHITE);
				gorbHeight++; 
				if (gorbHeight >= 3) {
					gorbWidth++; 
					gorbHeight = 0; 
				}
				gorbNum++;
			}
			//gorbString = ""; 
		/*	for each (Gorb gorb in gorbs)
			{
				gorbString += gorb.toString() + "\n"; 
			}*/
			//DrawTextEx(g.boldFont, gorbString.c_str(), { (float)sectionWidth / 16, (float)(sectionHeight / 16) * 5 }, 12, 0, LIME); 
			//gorbString.clear(); 
		}
		case UIMODE::GSTATS:
		{
			if (displayGorbStats) {
				gorbVector = *b.getGorbs();
				DrawRectangle(sectionWidth / 16, sectionHeight / 16, 270, 130, BLACK);
				DrawTextEx(g.boldFont, "Gorb Stats:", { (float)sectionWidth / 16, (float)sectionHeight / 16 }, 18, 0, GREEN);
				DrawTextEx(g.boldFont, gorbVector.at(gorbToDisplay).toString().c_str(), { (float)sectionWidth / 16, ((float)sectionHeight / 16) + 15 }, 12, 0, LIME);
			}
		}
		default:
			break;
	}
}
void UI::setGorbToDisplay(int gorbNum) {
	gorbToDisplay = gorbNum; 
}
int UI::getMode() {
	return static_cast<int>(uiMode); 
}
void UI::setDisplayGorbStats(bool b) {
	displayGorbStats = b; 
}