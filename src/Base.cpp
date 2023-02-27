#include "BaseUnit.h"
//#include "Resource.h"
#include "Base.h"
#include "Gorb.h"
#include "MissionManager.h"
#include <iostream>
//@TODO: IMPLIMENT BASE STUFF
using namespace std; 
Base::Base() {
	centPos = { 50.0f,50.0f }; 
	capacity = 30; 

}
Base::Base(int startingCapacity, string name,int winHeight,int winWidth) {
	capacity = startingCapacity; 
	std::cout << "creating base" << endl; 
	int gorbsToGenerate = (int)(startingCapacity * 0.333); 
	for (int i = 0; i < gorbsToGenerate; i++) {
		std::cout << "Generating Gorbs" << endl; 
		gorbList.push_back(Gorb()); 
	}
	centPos = { (float)winWidth / 2.0f, (float)winHeight / 2.0f }; 
	this->name = name; 
	std::cout << "adding command unit" << endl; 
	missionManager = MissionManager(); 
	unitList.push_back(BaseUnit(UNITTYPE::Command, startingCapacity, (int)centPos.x, (int)centPos.y)); 
}
void Base::renderUnits() {
	for each (BaseUnit unit in unitList)
	{
		unit.Render();
	}
}
string Base::getName() {
	return name; 
}
int Base::getCapacity() {
	return capacity; 
}
int Base::getNumGorbs() {
	return gorbList.size(); 
}
int Base::getNumUnits() {
	return unitList.size(); 
}
MissionManager Base::getMissionManager(){
	return missionManager; 
}