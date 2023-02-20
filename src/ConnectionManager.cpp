#include "ConnectionManager.h"
#include "Connection.h"
#include <vector>

ConnectionManager::ConnectionManager() {
	connections = std::vector<Connection>(); 
}
void ConnectionManager::createConnection(Vector2 startPos, Vector2 endPos) {
	connections.push_back(Connection(startPos, endPos)); 
}