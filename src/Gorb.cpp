#include <iostream>
#include <math.h>
#include <raylib.h>
#include "Gorb.h"
#include "BaseUnit.h"
using namespace std; 

Gorb::Gorb(string name,int level, double startingMorale) 
{
	this->level = level;
	morale = startingMorale; 
	currentUnit = UNITTYPE::None; 
	generateSkills(); 


}
UNITTYPE Gorb::getBestUnit() 
{
	int greatestSkillIndex = 0; 
	int greatestSkillAmt = 0; 
	for (int i = 0; i < sizeof(skills); i++) 
	{
		if (skills[i] > greatestSkillAmt) {
			greatestSkillIndex = i; 
			greatestSkillAmt = skills[i]; 
		}
	}
	switch (greatestSkillIndex)
	{
		case 0:
			return UNITTYPE::; 
		case 1:
			return UNITTYPE::Research;
		case 2:
			return UNITTYPE::Support;
		case 3:
			return UNITTYPE::Combat; 
		case 4:
			return UNITTYPE::Medical; 
		default:
			return UNITTYPE::Support; 
	}
}
void Gorb::generateSkills() 
{
	for each (int skill in skills )
	{
		skill = rand() % 10; 
	}
}

#pragma region ACCESSORS AND MUTATORS
UNITTYPE Gorb::getCurrentUnit() {
	return currentUnit; 
}
string Gorb::getName() {
	return name; 
}
double Gorb::getMorale() {
	return morale; 
}
int Gorb::getSkill(int index) {
	return skills[index]; 
}
void Gorb::setSkill(int index,int newVal) {
	skills[index] = newVal; 
}
#pragma endregion

