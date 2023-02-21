#include "BaseUnit.h"
#include <raylib.h> 
#include <iostream>
#include <list>

using namespace std; 
BaseUnit::BaseUnit() {
	this->unitType = 5;
	pos = { 10,10 };
	level = 1;
	capacity = 30;
	canMove = false; 
	bounds = Rectangle();
	bounds.x = pos.x;
	bounds.y = pos.y;
}
BaseUnit::BaseUnit(UNITTYPE unitType, int startingCapacity, int posX, int posY) {
	this->unitType =static_cast<int>(unitType); 
	pos.x = posX; 
	pos.y = posY; 
	capacity = startingCapacity; 
	level = 1;
	canMove = false; 
	bounds = Rectangle(); 
	bounds.x = posX; 
	bounds.y = posY; 
	
}
void BaseUnit::addGorb(Gorb gorb) {
	gorbList.push_back(gorb); 
}
void BaseUnit::addConnection(BaseUnit newConnection) {
	connectedTo.push_back(newConnection); 
}
void BaseUnit::removeConnection(BaseUnit connection) {
	for (int i = 0; i < connectedTo.size(); i++) {
		if (connectedTo[i].equals(connection)){
			connectedTo.erase(connectedTo.begin() + i); 
			return; 
		}
	}
}
bool BaseUnit::checkVald() {
	for (int i = 0; i < connectedTo.size(); i++) {
		if (connectedTo[i].getType() == 0) {
			return true; 
		}
	}
	return false; 
}
/// <summary>
/// Renders the base unit, the unit must be rendered after init of gamewindow 
/// </summary>
void BaseUnit::Render() 
{
	Image image = LoadImage("./assets/images/CommandUnitIcon.png");
	bounds.width = image.width; 
	bounds.height = image.height; 
	Texture texture = LoadTextureFromImage(image);
	UnloadImage(image);
	DrawTextureV(texture, pos, WHITE); 
} 
bool BaseUnit::checkCollisionRect(Rectangle collider) {
	return CheckCollisionRecs(bounds, collider); 
}
bool BaseUnit::checkCollisonCircle(Vector2 centerPos,float radius) {

	return CheckCollisionCircleRec(centerPos,radius,bounds); 
}
#pragma region ACCESSORS AND MUTATORS
void BaseUnit::setMoveable(bool movable) {
	canMove = movable;
}
void BaseUnit::setPosition(Vector2 mousePos) {
	pos.x = mousePos.x; 
	pos.y = mousePos.y; 
	bounds.x = pos.x; 
	bounds.y = pos.y; 
}
vector<Gorb> BaseUnit::getGorbList() 
{
	return gorbList; 
}
int BaseUnit::getLevel() 
{
	return level; 
}
int BaseUnit::getCapacity() {
	return capacity; 
}
Vector2 BaseUnit::getPosition() {
	return pos; 
}
bool BaseUnit::getMovable() {
	return canMove; 
}
int BaseUnit::getType() {
	return unitType; 
}
#pragma endregion
bool BaseUnit::equals(BaseUnit baseUnit) {
	bool output = (baseUnit.getCapacity() == getCapacity()) && (baseUnit.getLevel() == getLevel()) && (baseUnit.getType() == getType()); 
	return output; 
}