#pragma once
#include "Connection.h"
#include <vector>
#include <raylib.h>
#include <iostream>

class ConnectionManager {
	public:
		ConnectionManager(); 
		/// <summary>
		/// Creates a new segment with stored beginning and end points set using the <c>setNewSegmentBeginning()</c> and <c>setNewSegmentEnd()</c> methods
		/// </summary>
		void createConnection();
		void addConnection(Connection); 
		unsigned int getNumConnections(); 
		void renderConnections(); 
		void setNewSegmentBeginning(Vector2); 
		void setNewSegmentEnd(Vector2); 
		Connection getConnection(unsigned int); 
	private:
		std::vector<Connection> connections; 
		Vector2 segBegin; 
		Vector2 segEnd; 
};