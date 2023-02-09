#include "UI.h"
#include <iostream>
#include <raylib.h>
#include "UIButton.h"

bool buttons[10]; 

void UI::setButtonActive(int button, bool active) 
{
	buttons[button] = active; 
}

void UI::drawUIButtons() 
{
	for (int i = 0; i < sizeof(buttons); i++) {
		if (buttons[i] == true) {
			drawButton(i); 
		}
	}
}
void UI::drawButton(int button) {
	switch (button) {
	case 1:
		UIButton button = UIButton("test", 50, 10);
		button.setPos(50, 50);
		button.drawButton(true); 
	}
}