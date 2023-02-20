#include "ConnectionManager.h"
#include "Connection.h"
#include <vector>
#include <iostream>


ConnectionManager::ConnectionManager() {
	connections = std::vector<Connection>(); 
	segBegin = { 0,0 };
	segEnd = { 0,0 }; 
}
void ConnectionManager::createConnection() {
	Connection c = Connection(segBegin, segEnd); 
	connections.push_back(c); 
}
Connection ConnectionManager::getConnection(unsigned int index) {
	return connections[index]; 
}
void ConnectionManager::addConnection(Connection connection) {
	connections.push_back(connection); 
}
unsigned int ConnectionManager::getNumConnections() {
	return connections.size(); 
}
void ConnectionManager::renderConnections() {
	DrawCircleV(segEnd, 3.0f, RED); 
	DrawCircleV(segBegin, 3.0f, RED); 
	for (int i = 0; i < connections.size(); i++) {
		std::cout << "rendering segment at: " << segEnd.x << ", " << segEnd.y << " " << segBegin.x << ", " << segBegin.y << endl; 
		connections.at(i).PartialRender(); 
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