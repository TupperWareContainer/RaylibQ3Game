#pragma once
#include <raylib.h>
#include <iostream>
#include <list>
#include "Gorb.h"

namespace UnitDef {
	enum UNITTYPE
	{
		Command,
		Research,
		Support,
		Combat,
		Medical,
		None
	};
}
using namespace std;
using namespace UnitDef;
class BaseUnit {
	public:
		BaseUnit(); 
		BaseUnit(UNITTYPE,int, int,int);
		void Render();
		int getLevel();
		int getCapacity(); 
		void addGorb(Gorb); 
		Vector2 getPosition(); 
		list<Gorb> getGorbList(); 

	private:
		int level;
		UNITTYPE unitType; 
		list<Gorb> gorbList; 
		Vector2 pos; 
		int capacity; 
		
};
