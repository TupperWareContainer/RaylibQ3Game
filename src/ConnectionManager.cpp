#include "ConnectionManager.h"
#include "BaseUnit.h"
#include "Connection.h"
#include <vector>
#include <iostream>


ConnectionManager::ConnectionManager() {
	connections = std::vector<Connection>(); 
	tempConnections = std::vector<Connection>(); 
	baseUnits = std::vector<BaseUnit>(); 
	segBegin = { 0,0 };
	segEnd = { 0,0 }; 
}
ConnectionManager::ConnectionManager(std::vector<BaseUnit> unitList) {
	connections = std::vector<Connection>();
	tempConnections = std::vector<Connection>();
	baseUnits = unitList;
	segBegin = { 0,0 };
	segEnd = { 0,0 };
}
void ConnectionManager::createConnection() {
	Connection c = Connection(segBegin, segEnd); 
	tempConnections.push_back(c); 
}
Connection ConnectionManager::getConnection(unsigned int index) {
	return connections[index]; 
}
Connection ConnectionManager::getTempConnection(unsigned int index) {
	return tempConnections[index];
}
void ConnectionManager::addConnection(Connection connection) {
	connections.push_back(connection); 
}
unsigned int ConnectionManager::getNumConnections() {
	return connections.size(); 
}
void ConnectionManager::renderConnections() {
	bool validBeginConnection = false; 
	bool validEndConnection = false; 
	for (int i = 0; i < baseUnits.size(); i++) {
		if(baseUnits.at(i).checkCollisonCircle(segBegin,3.0f) && !validBeginConnection){
			DrawCircleV(segBegin, 3.0f, GREEN);
			validBeginConnection = true; 
			std::cout << "Valid beginning connection found!" << endl; 
		}
		if (baseUnits.at(i).checkCollisonCircle(segEnd, 3.0f) && !validEndConnection) {
			DrawCircleV(segEnd, 3.0f, GREEN);
			validEndConnection = true; 
			std::cout << "Valid ending connection found!" << endl;
		}
		if (validBeginConnection && validEndConnection) break; 
	}
	if (!validBeginConnection) {
		DrawCircleV(segBegin, 3.0f, RED);
		
	}
	if (!validEndConnection) {
		DrawCircleV(segEnd, 3.0f, RED);
	}
	
	for (int i = 0; i < connections.size(); i++) {
		std::cout << "rendering segment at: " << segEnd.x << ", " << segEnd.y << " " << segBegin.x << ", " << segBegin.y << endl; 
		connections.at(i).PartialRender(); 
	}
	for (int i = 0; i < tempConnections.size(); i++) {
		std::cout << "rendering segment at: " << segEnd.x << ", " << segEnd.y << " " << segBegin.x << ", " << segBegin.y << endl;
		tempConnections.at(i).PartialRender();
	}
}

void ConnectionManager::setNewSegmentBeginning(Vector2 setBeginning) {
	segBegin = setBeginning; 
	std::cout << "segment beginning set" << endl; 
}
void  ConnectionManager::setNewSegmentEnd(Vector2 setEnd) {
	segEnd = setEnd; 
	std::cout << "segment end set" << endl;
}
void ConnectionManager::clearConnections() {
	connections.clear(); 
}
void ConnectionManager::clearConnection(unsigned int connectionIndex) {
	connections.erase(connections.begin() + connectionIndex); 
}
void ConnectionManager::clearTempConnections() {
	tempConnections.clear(); 
}
void ConnectionManager::saveTempConnections() {
	connections.insert(connections.end(), tempConnections.begin(), tempConnections.end()); 
	tempConnections.clear(); 
	std::cout << "temp connections saved!" << endl; 
}