#pragma once
#include <raylib.h>
#include <math.h>
#include <iostream>
using namespace std; 

class Gorb {
	public:
		Gorb(string,int,double);
		Gorb(); 
		int getBestUnit(); 
		int getCurrentUnit(); 
		string getName(); 
		double getMorale();
		int getSkill(int);
		void setSkill(int,int); 
		void renderGorb(int posX, int posY);
	private:
		void generateSkills(); 
		string generateName(); 
		int currentUnit; 
		int skills[5];
		string name; 
		double morale; 
		int level; 
		int decal; 
};