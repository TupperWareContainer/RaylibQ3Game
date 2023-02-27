#pragma once
#include <iostream>
#include "UI.h"
#include "MissionManager.h"
#include "Base.h"
using namespace std; 
class ConsoleReader {
	public:
		ConsoleReader(); 
		ConsoleReader(UI* uiObj, MissionManager* mObj, Base* bObj);
		string getInput();
		void filterFakeConsoleInput(string consoleInput); 
	private: 
		 string input; 
		 UI* uiObj; 
		 MissionManager* mObj; 
		 Base* bObj; 
};
