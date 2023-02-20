#pragma once
#include "Connection.h"
#include <vector>
#include <raylib.h>

class ConnectionManager {
	public:
		ConnectionManager(); 
		void createConnection(Vector2, Vector2); 
	private:
		std::vector<Connection> connections; 
};