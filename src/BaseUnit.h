#pragma once
#include <raylib.h>
#include <iostream>
#include <list>
#include "Gorb.h"

enum class UNITTYPE
{
	Command = 0,
	Research = 1,
	Support = 2,
	Combat = 3,
	Medical = 4,
	None = 5
};
using namespace std;
class BaseUnit {
	public:
		BaseUnit();
		BaseUnit(UNITTYPE,int, int,int);
		void Render();
		int getLevel();
		int getCapacity(); 
		void setPosition(Vector2); 
		void setMoveable(bool);
		void addGorb(Gorb); 
		Vector2 getPosition(); 
		list<Gorb> getGorbList();
		bool getMovable(); 
	

	private:
		int level;
		bool canMove; 
		int unitType; 
		list<Gorb> gorbList; 
		Vector2 pos; 
		int capacity; 
		
};
