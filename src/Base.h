#pragma once 
#include "BaseUnit.h"
//#include "Resource.h"
#include "Gorb.h"
#include <vector>
#include <iostream>
#include "MissionManager.h"


using namespace std; 

class Base {

	public:
		Base(); 
		Base(int startingCapacity,string name, int winHeight, int winWidth);
		void renderUnits(); 
		void addUnit(int unitType, int startingCapacity, int posX, int posY); 
		void addGorb(Gorb gorb); 
		string getName(); 
		int getCapacity(); 
		int getNumGorbs(); 
		int getNumUnits(); 
		MissionManager getMissionManager(); 

	private:
		string name; 
		vector<BaseUnit> unitList; 
		vector<Gorb> gorbList; 
		Vector2 centPos;
		int capacity; 
		MissionManager missionManager; 
		//Resource resources[3]; 
		
};