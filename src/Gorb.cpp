#include <iostream>
#include <math.h>
#include <raylib.h>
#include "Gorb.h"
using namespace std; 

Gorb::Gorb(string name,int level, double startingMorale) 
{
	this->level = level;
	morale = startingMorale; 
	currentUnit = 5; 
	generateSkills(); 
	decal = rand() % 5 + 1; 

}
Gorb::Gorb() {
	currentUnit = 5; 
	morale = 1; 
	level = 1; 
	name = generateName(); 
	generateSkills(); 
}
string Gorb::generateName() {
	int randFirst = rand() % 10 + 1; 
	int randSecond = rand() % 5 + 1;
	string output = ""; 
	
	switch (randFirst)
	{
		case 1:
			output += "Gor"; 
			break; 
		case 2:
			output += "Gow";
				break; 
		case 3:
			output += "Gwo"; 
			break; 
		case 4: 
			output += "Gro"; 
			break; 
		case 5:
			output += "Gol"; 
			break; 
		case 6: 
			output += "Glo";
			break; 
		case 7: 
			output += "Kor"; 
			break; 
		case 8: 
			output += "Kro"; 
			break; 
		case 9: 
			output += "Kow"; 
			break; 
		case 10:
			output += "Kwo"; 
			break; 

		default:
			break;
	}
	switch (randSecond)
	{
		case 1:
			output += "bum"; 
			break; 
		case 2:
			output += "bom"; 
		case 3: 
			output += "bow"; 
			break; 
		case 4: 
			output += "bwo"; 
			break; 
		case 5: 
			output += "bo"; 
			break; 
		
	}
	return output; 
}
int Gorb::getBestUnit() 
{
	int greatestSkillIndex = 0; 
	int greatestSkillAmt = 0; 
	for (int i = 0; i < sizeof(skills); i++) 
	{
		if (skills[i] > greatestSkillAmt) {
			greatestSkillIndex = i; 
			greatestSkillAmt = skills[i]; 
		}
	}
	switch (greatestSkillIndex)
	{
		case 0:
			return 0; 
		case 1:
			return 1;
		case 2:
			return 2;
		case 3:
			return 3;
		case 4:
			return 4;
		default:
			return 5;
	}
}
void Gorb::generateSkills() 
{
	for each (int skill in skills )
	{
		skill = rand() % 10; 
	}
}
void Gorb::renderGorb(int posX, int posY) {
	Image image; 
	Texture2D imageTexture; 
	switch (decal) {
		case 1:
			image = LoadImage("./assets/images/Gorb.png"); 
			imageTexture = LoadTextureFromImage(image); 
			UnloadImage(image); 
			break; 
		case 2:
			image = LoadImage("./assets/images/Gorb2.png");
			imageTexture = LoadTextureFromImage(image);
			UnloadImage(image);
			break;
		case 3:
			image = LoadImage("./assets/images/Gorb3.png");
			imageTexture = LoadTextureFromImage(image);
			UnloadImage(image);
			break;
		case 4:
			image = LoadImage("./assets/images/Gorb4.png");
			imageTexture = LoadTextureFromImage(image);
			UnloadImage(image);
			break;
		case 5:
			image = LoadImage("./assets/images/Gorb5.png");
			imageTexture = LoadTextureFromImage(image);
			UnloadImage(image);
			break;
	}
	DrawTexture(imageTexture,posX,posY,WHITE);
}
#pragma region ACCESSORS AND MUTATORS
int Gorb::getCurrentUnit() {
	return currentUnit; 
}
string Gorb::getName() {
	return name; 
}
double Gorb::getMorale() {
	return morale; 
}
int Gorb::getSkill(int index) {
	return skills[index]; 
}
void Gorb::setSkill(int index,int newVal) {
	skills[index] = newVal; 
}
#pragma endregion

