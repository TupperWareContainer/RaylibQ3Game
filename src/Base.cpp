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
	money = 0; 
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
	unitList[0] = (BaseUnit(UNITTYPE::Command, startingCapacity, (int)centPos.x, (int)centPos.y)); 
	unitList[1] = BaseUnit();
	unitList[2] = BaseUnit();
	unitList[3] = BaseUnit();
	unitList[4] = BaseUnit();
	money = 0;
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
BaseUnit* Base::getBaseUnits() {
	return unitList; 
}
int Base::getCapacity() {
	return capacity; 
}
int Base::getNumGorbs() {
	return gorbList.size(); 
}
int Base::getNumUnits() {
	int arrSize = MAX_UNITS;
	int numUnits = 0; 
	for (int i = 0; i < arrSize; i++) {
		if (unitList[i].getType() != 5){
			numUnits++; 
		}
	}
	return numUnits; 
}
Vector2 Base::getCentPos() {
	return centPos; 
}
vector<Gorb> Base::getGorbs() {
	return gorbList; 
}
void Base::addUnit(BaseUnit b) {
	int unitType = b.getType(); 
	std::cout << "b.getType(): " << b.getType() << endl; 
	unitList[unitType] = b; 

}
void Base::addMoney(int amt) {
	money += amt; 
}
int Base::getMoney() {
	return money; 
}