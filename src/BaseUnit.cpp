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
}
BaseUnit::BaseUnit(UNITTYPE unitType, int startingCapacity, int posX, int posY) {
	this->unitType =static_cast<int>(unitType); 
	pos.x = posX; 
	pos.y = posY; 
	capacity = startingCapacity; 
	level = 1; 
	canMove = false; 
	
}
void BaseUnit::addGorb(Gorb gorb) {
	gorbList.push_front(gorb); 
}
/// <summary>
/// Renders the base unit, the unit must be rendered after init of gamewindow 
/// </summary>
void BaseUnit::Render() 
{
	Image image = LoadImage("./assets/images/CommandUnitIcon.png");
	Texture texture = LoadTextureFromImage(image);
	UnloadImage(image);
	DrawTextureV(texture, pos, WHITE); 
} 
#pragma region ACCESSORS AND MUTATORS
void BaseUnit::setMoveable(bool movable) {
	canMove = movable;
}
void BaseUnit::setPosition(Vector2 mousePos) {
	pos.x = mousePos.x; 
	pos.y = mousePos.y; 
}
list<Gorb> BaseUnit::getGorbList() 
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
#pragma endregion
