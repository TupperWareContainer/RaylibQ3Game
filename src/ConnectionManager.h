#pragma once
#include "Connection.h"
#include "BaseUnit.h"
#include <vector>
#include <raylib.h>
#include <iostream>

class ConnectionManager {
	public:
		ConnectionManager(); 
		ConnectionManager(std::vector<BaseUnit>);
		/// <summary>
		/// Creates a new segment with stored beginning and end points set using the <c>setNewSegmentBeginning()</c> and <c>setNewSegmentEnd()</c> methods
		/// </summary>
		void createConnection();
		void addConnection(Connection); 
		unsigned int getNumConnections(); 
		/// <summary>
		///<p>Renders the connections managed by this connection manager.</p>
		/// Renders "permenant" connections first before rendering temporary connections
		/// </summary>
		void renderConnections(); 
		void setNewSegmentBeginning(Vector2); 
		void setNewSegmentEnd(Vector2); 
		Connection getConnection(unsigned int); 
		Connection getTempConnection(unsigned int);
		void saveTempConnections(); 
		void clearConnections(); 
		void clearConnection(unsigned int); 
		void clearTempConnections(); 
	private:
		std::vector<Connection> connections; 
		std::vector<Connection> tempConnections; 
		std::vector<BaseUnit> baseUnits; 
		Vector2 segBegin; 
		Vector2 segEnd; 
		
};