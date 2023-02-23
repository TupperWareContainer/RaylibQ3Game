#pragma once 
#include "BaseUnit.h"
//#include "Resource.h"
#include "Gorb.h"
#include <vector>
#include <iostream>

using namespace std; 

class Base {

	public:
		Base(); 
		Base(int startingCapacity,string name, int winHeight, int winWidth);
		void renderUnits(); 
		void addUnit(int unitType, int startingCapacity, int posX, int posY); 
		void addGorb(Gorb gorb); 

	private:
		string name; 
		vector<BaseUnit> unitList; 
		vector<Gorb> gorbList; 
		Vector2 centPos;
		int capacity; 
		//Resource resources[3]; 
		
};