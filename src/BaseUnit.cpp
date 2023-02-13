#include "BaseUnit.h"
#include <raylib.h> 
#include <iostream>
#include <list>

using namespace std; 
BaseUnit::BaseUnit(UNITTYPE unitType, int startingCapacity, int posX, int posY) {
	this->unitType = unitType; 
	pos.x = posX; 
	pos.y = posY; 
	capacity = startingCapacity; 
	level = 1; 
}
void BaseUnit::addGorb(Gorb gorb) {
	gorbList.push_front(gorb); 
}
/// <summary>
/// Renders the base unit, the unit must be rendered after init of gamewindow 
/// </summary>
void BaseUnit::Render() 
{
	Image image = LoadImage("assets/images/Placeholder.png"); 
	Texture2D texture = LoadTextureFromImage(image); 
	UnloadImage(image); //unloads the image after saving to VRAM via texture conversion 
	DrawTextureV(texture, pos, WHITE); 
}
#pragma region ACCESSORS AND MUTATORS
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
#pragma endregion
