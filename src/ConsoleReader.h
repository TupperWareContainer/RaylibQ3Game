#pragma once
#include <iostream>
#include "UI.h"
#include "MissionManager.h"
#include "Base.h"
#include "BaseDev.h"
#include "Gorb.h"
#include <vector>

using namespace std; 
class ConsoleReader {
	public:
		ConsoleReader(); 
		ConsoleReader(UI* uiObj, MissionManager* mObj, Base* bObj, BaseDev* bDevObj);
		string getInput();
		void filterFakeConsoleInput(string consoleInput); 
	private: 
		 string input; 
		 UI* uiObj; 
		 MissionManager* mObj; 
		 Base* bObj; 
		 BaseDev* bDevObj; 
};
