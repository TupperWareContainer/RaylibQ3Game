#pragma once
#include <raylib.h>
#include <vector>

using namespace std; 
/// <summary>
/// Connections are essentially roads that allow units to communicate with eachother, sorta like cities:skylines 
/// </summary>
class ConnectionManager {
	public:
		ConnectionManager(); 
		

	private:
		vector<Connection> connections; 

};