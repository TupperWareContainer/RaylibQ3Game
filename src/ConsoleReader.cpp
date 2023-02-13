#include "ConsoleReader.h"
#include <iostream>

using namespace std; 

ConsoleReader::ConsoleReader() {
	cout << "Console Reader Initialized!" << endl; 
}

string ConsoleReader::getInput() {
	cin >> input; 
	return input; 
}


