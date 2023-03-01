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
		void addUnit(BaseUnit b); 
		void addGorb(Gorb gorb); 
		BaseUnit* getBaseUnits(); 
		void addMoney(int amt); 
		string getName(); 
		Vector2 getCentPos(); 
		int getCapacity(); 
		int getNumGorbs(); 
		int getNumUnits(); 
		int getMoney(); 

	private:
		string name; 
		BaseUnit unitList[5];
		vector<Gorb> gorbList; 
		Vector2 centPos;
		int capacity; 
		int money; 
		//Resource resources[3]; 
		
};