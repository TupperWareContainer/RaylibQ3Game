#include "BaseDev.h"
#include <iostream>
#include "Base.h"
#include "BaseUnit.h"
#include <future>
#include <chrono>
#include <thread>

BaseDev::BaseDev() {

}
BaseDev::BaseDev(long buildTime, Base b) {
	this->buildTime = buildTime; 
	nullUnit = BaseUnit(); 
	unitCost = 1000; 
	unitList[0] = BaseUnit(UNITTYPE::Research, 30, b.getCentPos().x + 32, b.getCentPos().y); 
	unitList[1] = BaseUnit(UNITTYPE::Support, 30, b.getCentPos().x - 32, b.getCentPos().y);
	unitList[2] = BaseUnit(UNITTYPE::Combat, 30, b.getCentPos().x, b.getCentPos().y + 32);
	unitList[3] = BaseUnit(UNITTYPE::Medical, 30, b.getCentPos().x, b.getCentPos().y - 32);
}
void BaseDev::completeConstruction(Base *b, int unitType) 
{
	b->addUnit(unitList[unitType]); 
	std::cout << "Unit Added" << endl; 
	unitList[unitType] = nullUnit; 
}
void BaseDev::startConstruction(Base *b, int unitType) {
	std::chrono::seconds buildTime(buildTime);
	std::thread([=]() {
		std::cout << "\nstarting timer for " << this->buildTime << " seconds" << std::endl;
		std::this_thread::sleep_for(buildTime);
		completeConstruction(b, unitType);
		std::cout << "ended timer at: " << GetTime() << std::endl;
	}).detach();
}
int BaseDev::getUnitCost(int unitNum) {
	return unitCost; 
}
std::string BaseDev::getUnitStrings() {
	std::string output = ""; 
	int i = 0; 
	for each (BaseUnit bu in unitList)
	{
		output += "[";
		output += char(i + 48);
		output += "]";
		if (bu.getType() != 5) {
			output += bu.toString(); 
			output += "[";
			output += std::to_string(unitCost); 
			output += "]";
		}
		output += "\n";
		i++;
	}
	//std::cout << output << std::endl; 
	return output; 
}