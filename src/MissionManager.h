#pragma once
#include <iostream>
#include "Mission.h"
#include <raylib.h>
#define VISIBLE_MISSIONS 5; 
class MissionManager {
	public: 
		MissionManager();
		std::string getMissionStrings(); 
	private:
		Mission missionList[5]; // there can only be 5 active missions at a time
		void generateMissions();
};
