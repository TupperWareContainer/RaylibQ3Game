#pragma once
#include <iostream>
#include "UI.h"
using namespace std; 
class ConsoleReader {
	public:
		ConsoleReader(); 
		ConsoleReader(UI* uiObj);
		string getInput();
		void filterFakeConsoleInput(string consoleInput); 
	private: 
		 string input; 
		 UI* uiObj; 
};
