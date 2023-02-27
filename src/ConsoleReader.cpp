#include "ConsoleReader.h"
#include "UI.h"
#include <iostream>

using namespace std; 

ConsoleReader::ConsoleReader() {
	cout << "Console Reader Initialized!" << endl;
}
ConsoleReader::ConsoleReader(UI* uiObj) {
	cout << "Console Reader Initialized!" << endl; 
	this->uiObj = uiObj; 
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
}




