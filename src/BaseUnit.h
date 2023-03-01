#pragma once
#include <raylib.h>
#include <iostream>
#include "Gorb.h"
#include <vector>
#include <sstream>

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
		int getType(); 
		void setPosition(Vector2); 
		void setMoveable(bool);
		void addGorb(Gorb); 
		void addConnection(BaseUnit); 
		void removeConnection(BaseUnit); 
		bool checkCollisionRect(Rectangle); 
		bool checkCollisonCircle(Vector2, float);
		bool isMouseHover(Vector2); 
		Vector2 getPosition(); 
		vector<Gorb> getGorbList();
		bool getMovable(); 
		bool checkVald(); 
		bool equals(BaseUnit); 
		Rectangle getRect(); 
		std::string toString(); 
	

	private:
		int level;
		Rectangle bounds; 
		bool canMove; 
		int unitType; 
		vector<Gorb> gorbList; 
		vector<BaseUnit> connectedTo; 
		Vector2 pos; 
		int capacity; 
		
};
