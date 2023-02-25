#include "ConnectionManager.h"
#include "BaseUnit.h"
#include "Connection.h"
#include <vector>
#include <iostream>



ConnectionManager::ConnectionManager() {
	connections = std::vector<Connection>();
	tempConnections = std::vector<Connection>();
	segBegin = { 0,0 };
	segEnd = { 0,0 };
	c1.x = segBegin.x;
	c1.y = segBegin.y;
	c1.width = 6;
	c1.height = 6;
	c2.x = segBegin.x;
	c2.y = segBegin.y;
	c2.width = 6;
	c2.height = 6;
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
void ConnectionManager::renderConnections(BaseUnit unitList[]) {
	bool validBeginConnection = false; 
	bool validEndConnection = false; 
	c1.x = segBegin.x;
	c1.y = segBegin.y;
	c2.x = segEnd.x;
	c2.y = segEnd.y;
	int size = MAXBASEUNITS; 
	Rectangle currRect; 
	for (int i = 0; i <size; i++) {
		currRect.x = unitList[i].getRect().x; 
		currRect.y = unitList[i].getRect().y;
		currRect.width = unitList[i].getRect().width;
		currRect.height = unitList[i].getRect().height;
		DrawRectangleLines(currRect.x,currRect.y,currRect.width,currRect.height, GREEN); 
		std::cout << "Base Unit Type: "<< unitList[i].getType() << " collisionDetection: " << CheckCollisionRecs(unitList[i].getRect(), c1) << " "  << CheckCollisionRecs(unitList[i].getRect(), c2) << endl;
		std::cout << "Iterator: " << i << endl; 
		if(CheckCollisionRecs(unitList[i].getRect(),c1) && !validBeginConnection){
			DrawRectangleV(segBegin, { c1.width,c1.height }, GREEN); 
			validBeginConnection = true; 
			std::cout << "Valid beginning connection found!" << endl; 
		}
		if (CheckCollisionRecs(unitList[i].getRect(), c2) && !validEndConnection) {
			DrawRectangleV(segEnd, { c2.width,c2.height }, GREEN);
			validEndConnection = true; 
			std::cout << "Valid ending connection found!" << endl;
		}
		if (validBeginConnection && validEndConnection) break; 
	}
	if (!validBeginConnection) {
		DrawRectangleV(segBegin, { c1.width,c1.height }, RED);
		std::cout << "Cannot find valid begin segment" << endl; 
		
	}
	if (!validEndConnection) {
		DrawRectangleV(segEnd, { c2.width,c2.height }, RED); 
		std::cout << "cannot find valid end segment" << endl; 
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
void ConnectionManager::updateConnections(BaseUnit units[]) {
	int arraySize = MAXBASEUNITS; 
	for each (Connection connection in connections)
	{
		connection.CheckCollison(units, arraySize);
	}
}