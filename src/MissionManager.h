#pragma once
#include <iostream>
#include "Mission.h"
#include <raylib.h>
#include "Base.h"
#include <future>
#include <chrono>
#include <thread>

#define VISIBLE_MISSIONS 5; 
class MissionManager {
	public: 
		MissionManager();
		std::string getMissionStrings(); 
		void completeMission(int missionNum, Base *b);
		void runMission(int missionNum,Base* b); 
		
	private:
		Mission missionList[5]; // there can only be 5 active missions at a time
		void generateMissions();
		Mission nullMission; 
 
};
