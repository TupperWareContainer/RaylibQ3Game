#pragma once
#include "Connection.h"
#include "BaseUnit.h"
#include <vector>
#include <raylib.h>
#include <iostream>
#define MAXBASEUNITS 10; 
class ConnectionManager {
	public:
		ConnectionManager(); 
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
		void renderConnections(BaseUnit*);
		void setNewSegmentBeginning(Vector2); 
		void setNewSegmentEnd(Vector2); 
		Connection getConnection(unsigned int); 
		Connection getTempConnection(unsigned int);
		void saveTempConnections(); 
		void updateConnections(BaseUnit* ); 
		void clearConnections(); 
		void clearConnection(unsigned int); 
		void clearTempConnections(); 
	private:
		std::vector<Connection> connections; 
		std::vector<Connection> tempConnections; 
		Rectangle c1;
		Rectangle c2; 
		Vector2 segBegin; 
		Vector2 segEnd; 
		
};