#include "Connection.h"
#include <raylib.h>
#include "BaseUnit.h"

Connection::Connection(Vector2 startPos, Vector2 endPos) {

}
Connection::~Connection() {

}
void Connection::PartialRender() {
	DrawLineV(startPos, endPos, LIME); 
}
void Connection::FullRender() {
	Image bridgeImage = LoadImage("./assets/images/BridgeSection.png"); 
	Texture bridgeTexture = LoadTextureFromImage(bridgeImage); 
	UnloadImage(bridgeImage); 
	//DrawTextureV()
}
