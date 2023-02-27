#include "ConsoleReader.h"
#include "UI.h"
#include <iostream>
#include "MissionManager.h"

using namespace std; 

ConsoleReader::ConsoleReader() {
	cout << "Console Reader Initialized!" << endl;
}
ConsoleReader::ConsoleReader(UI* uiObj, MissionManager* mObj, Base* bObj) {
	cout << "Console Reader Initialized!" << endl; 
	this->uiObj = uiObj; 
	this->mObj = mObj;
	this->bObj = bObj; 
}

string ConsoleReader::getInput() {
	cin >> input; 
	return input; 
}
void ConsoleReader::filterFakeConsoleInput(string consoleInput) {
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
		default:
			break;
	}
	switch (uiObj->getMode()) {
		case 4: {
			int num = int(consoleInput.at(0)) - 48;
			if (num <= 4) {
				mObj->runMission(num, *bObj); 
			}
		}
	}
}




