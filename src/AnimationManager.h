#pragma once
#include <raylib.h>
#include <iostream>
#include <future>
#include <chrono>
#include <thread>
#include "Animation2D.h"
class AnimationManager {
	public:
		AnimationManager(); 
		void runAnimation(Animation2D* animation, int repetitions); 
};
