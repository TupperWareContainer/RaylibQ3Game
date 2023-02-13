#pragma once
#include <raylib.h>
#include <math.h>
#include <iostream>
#include "BaseUnit.h"
using namespace std; 
using namespace UnitDef;
class Gorb {
	public:
		Gorb(string,int,double);
		UNITTYPE getBestUnit(); 
		UNITTYPE getCurrentUnit(); 
		string getName(); 
		double getMorale();
		int getSkill(int);
		void setSkill(int,int); 
	private:
		void generateSkills(); 
		UNITTYPE currentUnit; 
		int skills[5];
		string name; 
		double morale; 
		int level; 
};