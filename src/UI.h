#pragma once
#include <iostream>
#include <raylib.h>
using namespace std; 
class UI {
public: 
	
	
	static string checkForInput();
	static void setButtonActive(int,bool); 
	void drawUIButtons(); 

private:
	void drawButton(int);
	

};