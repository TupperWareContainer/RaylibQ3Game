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
#pragma region cheatCodes
	if (consoleInput.find("payday") != std::string::npos) {
		bObj->addMoney(10000); 
		std::cout << bObj->getMoney() << std::endl; 
		std::cout << "I NEED A MEDIC BAG" << std::endl; 
	}
#pragma endregion

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
		case 'V':
			uiObj->setMode(UIMODE::POPDISPLAY); 
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
			try {
				std::cout << "attempting to parse" << endl;
				int num = int(consoleInput.at(0)) - 48;
				if ((num <= 4) && bObj->getMoney() >= bDevObj->getUnitCost(num)) {
					bDevObj->startConstruction(bObj, num); 
				}
				else {
					std::cout << "Not enough money!" << std::endl; 
				}
			}
			catch (std::bad_alloc e) {
				std::cout << "Not a number" << endl;
			}
			break; 
		}
		case 6: 
		{
			try{ 
				std::cout << "attempting to parse" << endl;
				int num = int(consoleInput.at(0)) - 48;
				if ((num >= 0) && (num < bObj->getNumGorbs())) {
					//TODO: DISPLAY STATS OF GORB 
					uiObj->setGorbToDisplay(num); 
					uiObj->setMode(UIMODE::GSTATS); 
					uiObj->setDisplayGorbStats(true); 
				}
				else {
					uiObj->setMode(UIMODE::POPDISPLAY); 
					uiObj->setDisplayGorbStats(false); 
					std::cout << "Not a valid character" << std::endl;
				}
			}
			catch (std::out_of_range e) {
				std::cout << "Not a valid number" << endl;
			}
			break;
			break; 
		}
	}
}




