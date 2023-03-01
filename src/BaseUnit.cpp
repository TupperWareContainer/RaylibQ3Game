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
	bounds.width = 32;
	bounds.height = 32;
	bounds.x = pos.x - (bounds.width / 2);
	bounds.y = pos.y - (bounds.height / 2);
	
}
BaseUnit::BaseUnit(UNITTYPE unitType, int startingCapacity, int posX, int posY) {
	this->unitType =static_cast<int>(unitType); 
	cout << "creating unit of type " << this->unitType << endl; 
	pos.x = posX; 
	pos.y = posY; 
	capacity = startingCapacity; 
	level = 1;
	canMove = false; 
	bounds = Rectangle();
	bounds.width = 32;
	bounds.height = 32;
	bounds.x = posX - (bounds.width / 2);
	bounds.y = posY - (bounds.height / 2);
	bounds.width = 32; 
	bounds.height = 32; 
	
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
	string path;
	switch (unitType)
	{
		case 0:
			path = "./assets/images/CommandUnitIcon.png"; 
			break; 
		case 1: 
			path = "./assets/images/Research.png";
			break; 
		case 2:
			path = "./assets/images/Support.png";
			break; 
		case 3:
			path = "./assets/images/Combat.png";
			break; 
		case 4:
			path = "./assets/images/Medical.png"; 
			break; 
		default:
			return; 
			break;
	}


	Image image = LoadImage(path.c_str());
	bounds.width = image.width; 
	bounds.height = image.height; 
	cout << "bounds.width: " << bounds.width << endl; 
	cout << "bounds.height: " << bounds.height << endl; 
	Texture texture = LoadTextureFromImage(image);
	UnloadImage(image);
	DrawTextureV(texture, pos, WHITE); 
	//DrawRectangleLines(bounds.x, bounds.y, bounds.width, bounds.height, GREEN); // draws collison 
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
	pos.x = mousePos.x -(bounds.width / 2); 
	pos.y = mousePos.y - (bounds.height / 2); 
	bounds.x = pos.x; 
	bounds.y = pos.y; 
}
vector<Gorb> BaseUnit::getGorbList() 
{
	return gorbList; 
}
bool BaseUnit::isMouseHover(Vector2 mousePos) {
	return CheckCollisionPointRec(mousePos, bounds); 
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
Rectangle BaseUnit::getRect() {
	return bounds; 
}
#pragma endregion
bool BaseUnit::equals(BaseUnit baseUnit) {
	bool output = (baseUnit.getCapacity() == getCapacity()) && (baseUnit.getLevel() == getLevel()) && (baseUnit.getType() == getType()); 
	return output; 
}
std::string BaseUnit::toString() {
	if (unitType == 5) {
		return ""; 
	}
	std::string output = ""; 
	output += "[UNIT: ";
	switch (unitType) {
		case 0:
			output += "Command || ";
			break; 
		case 1:
			output += "Research || ";
			break;
		case 2:
			output += "Support || ";
			break;
		case 3:
			output += "Combat || ";
			break;
		case 4:
			output += "Medical || ";
			break;
	}
	output += "CAPACITY: "; 
	
	output += to_string(capacity);
	output += "]";
	//cout << output << endl; 
	return output; ;
}