#include "Connection.h"
#include <raylib.h>
#include "BaseUnit.h"
#include <raymath.h>

using namespace std; 
Connection::Connection() {
	cout << "WARNING : CONNECTION OBJECTS HAVE BEEN INITIALIZED WITHOUT VALID START OR END POS" << endl; 
	startPos = { 0,0 }; 
	endPos = { 0,1 }; 
	c1.x = startPos.x;
	c1.y = startPos.y;
	c1.width = 6;
	c1.height = 6;
	c2.x = endPos.x;
	c2.y = endPos.y;
	c2.width = 6;
	c2.height = 6;
}
Connection::Connection(Vector2 startPos, Vector2 endPos) {
	this->startPos = startPos; 
	this->endPos = endPos;
	c1.x = startPos.x;
	c1.y = startPos.y;
	c1.width = 6;
	c1.height = 6;
	c2.x = endPos.x;
	c2.y = endPos.y;
	c2.width = 6;
	c2.height = 6;
}
Connection::~Connection() {

}
BaseUnit Connection::getConnection(int connection) {
	connection = min(connection, 1); 
	return connectedTo[connection]; 
}
void Connection::setConnection(int connection, BaseUnit baseUnit) {
	connection = min(connection, 1);
	connectedTo[connection] = baseUnit; 
}
void Connection::setEnd(Vector2 endPos) {
	this->endPos = endPos; 
}
void Connection::PartialRender() {
	cout << "Startpos: " << startPos.x << ", " << startPos.y << "\nEndpos: " << endPos.x << ", " << endPos.y << endl ;
	DrawLineEx(startPos, endPos,3.0f,LIME);
	
}
void Connection::CheckCollison(BaseUnit baseUnits[],int size) {
	Rectangle currRect; 
	bool conOne = false, conTwo = false; 
	int fCon, sCon; 
	for (int i = 0; i < size; i++)
	{
		currRect = baseUnits[i].getRect(); 
		if (!conOne && CheckCollisionRecs(currRect, c1)) {
			conOne = true; 
			fCon = i; 
		}
		else if (!conTwo && CheckCollisionRecs(currRect, c2)) {
			conTwo = true; 
			sCon = i; 
		}
		if (conOne && conTwo) {
			break; 
		}
	}
	if (conOne && conTwo) {
		baseUnits[fCon].addConnection(baseUnits[sCon]); 
		baseUnits[sCon].addConnection(baseUnits[fCon]);
		cout << "Connection added between" << baseUnits[fCon].getType() << " & " << baseUnits[sCon].getType() << endl;
	}
}
void Connection::FullRender() {
	Image bridgeImage = LoadImage("./assets/images/BridgeSection.png"); 
	Texture bridgeTexture = LoadTextureFromImage(bridgeImage); 
	UnloadImage(bridgeImage); 
	
}
