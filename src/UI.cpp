#include "UI.h"
#include <iostream>
#include <raylib.h>
#include "UIButton.h"

using namespace std; 
UI::UI(int allotedWidth, int allotedHeight) {
	buttonObjs[0] = UIButton("test", 50, 10);
	buttonObjs[1] = UIButton("Move", 50, 10); 
	buttonObjs[2] = UIButton("Draw", 50, 10); 
	buttonObjs[0].setPos(50, 50); 
	buttonObjs[1].setPos(300, 300); 
	buttonObjs[2].setPos(300, 350); 
	sectionWidth = allotedWidth; 
	sectionHeight = allotedHeight; 
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
void UI::drawUI(UIMODE UI) {
	switch (UI)
	{
	case UIMODE::TEST:
		buttonObjs[0].drawButton(true); 
		break;
	case UIMODE::MOVE:
		buttonObjs[0].drawButton(true); 
	case UIMODE::DEFAULT:
		DrawText("[L]ist Stats\n", sectionWidth / 16, sectionHeight / 16,15,BLACK); 
	default:
		break;
	}
}