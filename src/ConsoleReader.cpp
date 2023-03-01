#include "ConsoleReader.h"
#include "UI.h"
#include <iostream>
#include "MissionManager.h"
#include "BaseDev.h"

using namespace std; 

ConsoleReader::ConsoleReader() {
	cout << "Console Reader Initialized!" << endl;
}
ConsoleReader::ConsoleReader(UI* uiObj, MissionManager* mObj, Base* bObj, BaseDev* bDevObj) {
	cout << "Console Reader Initialized!" << endl; 
	this->uiObj = uiObj; 
	this->mObj = mObj;
	this->bObj = bObj; 
	this->bDevObj = bDevObj; 
}

string ConsoleReader::getInput() {
	cin >> input; 
	return input; 
}
void ConsoleReader::filterFakeConsoleInput(string consoleInput) {
	if (consoleInput.empty()) {
		return; 
	}
	switch (consoleInput.at(0))
	{
		case 'L':
			uiObj->setMode(UIMODE::STATS);
			break;
		case 'E':
			uiObj->setMode(UIMODE::DEFAULT);
			break; 
		case 'M':
			uiObj->setMode(UIMODE::MISSION); 
			break;
		case 'B':
			uiObj->setMode(UIMODE::UNITBUILDER); 
			break; 
		default:
			break;
	}
	switch (uiObj->getMode()) {
		case 4: 
		{
			try {
				std::cout << "attempting to parse" << endl; 
				int num = int(consoleInput.at(0)) - 48;
				if (num <= 4) {
					mObj->runMission(num, bObj);
				}
			}
			catch(std::bad_alloc e) {
				std::cout << "Not a number" << endl; 
			}
			break; 
		}
		case 5:
		{
			try { // TODO: ADD MONEY DETECTION
				std::cout << "attempting to parse" << endl;
				int num = int(consoleInput.at(0)) - 48;
				if (num <= 4) {
					bDevObj->startConstruction(bObj, num); 
				}
			}
			catch (std::bad_alloc e) {
				std::cout << "Not a number" << endl;
			}
			break; 
		}
	}
}




