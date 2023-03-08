#pragma once
#include <iostream>
#include "Base.h"
#include "BaseUnit.h"
#include <future>
#include <chrono>
#include <thread>
class BaseDev {
	public:
		BaseDev(); 
		BaseDev(long buildTime, Base b); 
		void startConstruction(Base *b, int unitType); 
		void completeConstruction(Base *b, int unitType); 
		int getUnitCost(int unitType); 
		bool getIsBuilding();
		std::string getUnitStrings(); 
	private: 
		BaseUnit unitList[4]; 
		BaseUnit nullUnit; 
		bool isBuilding; 
		long buildTime; 
		int unitCost; 

};
