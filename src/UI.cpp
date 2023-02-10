#include "UI.h"
#include <iostream>
#include <raylib.h>
#include "UIButton.h"

using namespace std; 
UI::UI() {
	buttonObjs[0] = UIButton("test", 50, 10);
	buttonObjs[0].setPos(50, 50); 
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