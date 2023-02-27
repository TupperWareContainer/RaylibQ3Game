#include "Mission.h"
#include <raylib.h> 
#include <iostream>

Mission::Mission() {
	missionType = MissionType::DefenseContract; 
	difficulty = Difficulty::Easy; 
	timeToComplete = 10; 
}
Mission::Mission(MissionType missionType, double timeToComplete, Difficulty difficulty) {
	this->missionType = missionType; 
	this->difficulty = difficulty; 
	this->timeToComplete = timeToComplete;
}
int Mission::getDifficulty() {
	return (int)difficulty; 
}
int Mission::getMissionType() {
	return (int)missionType; 
}
double Mission::getTimeToComplete() {
	return timeToComplete; 
}
std::string Mission::toString() {
	std::string output = "["; 

	switch (missionType) {
		case MissionType::DefenseContract:
			output += "Defense Contract"; 
			break; 
		case MissionType::ResourceGather:
			output += "Gather Resources"; 
			break; 
		case MissionType::RaidRival:
			output += "Raid Rival"; 
			break; 
		default:
			break; 
	}
	output += " || "; 
	switch (difficulty)
	{
		case Difficulty::Easy:
			output += "Easy"; 
			break; 
		case Difficulty::Moderate:
			output += "Moderate"; 
			break; 
		case Difficulty::Hard: 
			output += "Hard"; 
			break; 
		default:
			break;
	}
	output += "]"; 
	return output; 
}