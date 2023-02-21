#include "Connection.h"
#include <raylib.h>
#include "BaseUnit.h"
#include <raymath.h>
using namespace std; 
Connection::Connection() {
	cout << "WARNING : CONNECTION OBJECTS HAVE BEEN INITIALIZED WITHOUT VALID START OR END POS" << endl; 
	startPos = { 0,0 }; 
	endPos = { 0,1 }; 
}
Connection::Connection(Vector2 startPos, Vector2 endPos) {
	this->startPos = startPos; 
	this->endPos = endPos; 
}
Connection::~Connection() {

}
void Connection::setEnd(Vector2 endPos) {
	this->endPos = endPos; 
}
void Connection::PartialRender() {
	cout << "Startpos: " << startPos.x << ", " << startPos.y << "\nEndpos: " << endPos.x << ", " << endPos.y << endl ;
	DrawLineEx(startPos, endPos,3.0f,LIME);
	
}
void Connection::FullRender() {
	Image bridgeImage = LoadImage("./assets/images/BridgeSection.png"); 
	Texture bridgeTexture = LoadTextureFromImage(bridgeImage); 
	UnloadImage(bridgeImage); 
	
}
