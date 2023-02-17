#pragma once
#include "raylib.h"
#include "ConnectionManager.h"
#include "BaseUnit.h"

using namespace std; 
class Connection {
	public:
		Connection(Vector2, Vector2);
		void PartialRender(); 
		void FullRender(); 
		~Connection();

	private:
		BaseUnit connectedTo[2]; 
		Vector2 startPos; 
		Vector2 endPos; 

};
