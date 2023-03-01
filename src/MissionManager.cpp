#include "MissionManager.h"
#include "Mission.h"
#include <raylib.h>
#include "Base.h"
#include <future>
#include <chrono>
#include <thread>

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
	nullMission = Mission(); 
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
void MissionManager::completeMission(int missionNum, Base *b) {
	b->addMoney(missionList[missionNum].getMoneyReward()); 
	missionList[missionNum] = nullMission; 
}
void MissionManager::runMission(int missionNum,Base* b) {
	std::cout << "started timer at: " << GetTime() << std::endl; 
	std::chrono::seconds missionTime((long)missionList[missionNum].getTimeToComplete());
	std::thread([=]() {
		std::cout <<"\nstarting timer for " << (long)missionList[missionNum].getTimeToComplete() << " seconds" << std::endl;
		std::this_thread::sleep_for(missionTime); 
		completeMission(missionNum, b); 
		std::cout << "ended timer at: " << GetTime() << std::endl;
	}).detach();
	
	
	
}
