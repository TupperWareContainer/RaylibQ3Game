#pragma once
#include <raylib.h>
#include <iostream>
#include <sstream>


enum class MissionType
{
	Null,
	ResourceGather = 1,
	DefenseContract = 2,
	RaidRival = 3 
};
enum class Difficulty {
	Easy = 1,
	Moderate = 2,
	Hard = 3
};
class Mission {
public:
	Mission(); 
	Mission(MissionType missionType, double timeToComplete, Difficulty difficulty);
	int getDifficulty(); 
	int getMissionType(); 
	double getTimeToComplete();
	int getMoneyReward(); 
	std::string toString(); 
private:
	MissionType missionType;
	double timeToComplete;
	Difficulty difficulty;
	int moneyReward; 
};