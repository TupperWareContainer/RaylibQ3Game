#include "MissionManager.h"
#include "Mission.h"
#include <raylib.h>

MissionManager::MissionManager(){
	generateMissions(); 
}
void MissionManager::generateMissions() {
	int randType, randTime, randDiff; 
	int vMissions = VISIBLE_MISSIONS; 
	std::string name = "";
	for(int i = 0; i < vMissions; i++)
	{
		randType = rand() % 3 + 1; 
		randDiff = rand() % 3 + 1;
		randTime = rand() % 15 + 1;
		missionList[i] = Mission(static_cast<MissionType>(randType), (double)randTime, static_cast<Difficulty>(randDiff));
	}
}
std::string MissionManager::getMissionStrings() {
	std::string output = ""; 
	int i = 0; 
	for each (Mission mission in missionList)
	{
		output += "[";
		output += (char)(48 + i); 
		output += "]"; 
		output += mission.toString();
		output += "\n"; 
		i++; 
	}
	return output; 
}