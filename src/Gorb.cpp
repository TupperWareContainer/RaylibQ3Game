#include <iostream>
#include <math.h>
#include <raylib.h>
#include "Gorb.h"
using namespace std; 

Gorb::Gorb(string name,int level, double startingMorale) 
{
	this->level = level;
	morale = startingMorale; 
	currentUnit = 5; 
	generateSkills(); 


}
int Gorb::getBestUnit() 
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
			return 0; 
		case 1:
			return 1;
		case 2:
			return 2;
		case 3:
			return 3;
		case 4:
			return 4;
		default:
			return 5;
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
int Gorb::getCurrentUnit() {
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

