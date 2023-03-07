#include "AnimationManager.h"
#include <raylib.h>
#include <iostream>
#include <future>
#include <chrono>
#include <thread>
#include "Animation2D.h"

AnimationManager::AnimationManager() {

}
void AnimationManager::runAnimation(Animation2D* animation, int repetitions) {
	std::thread([=]() {
		std::cout << "running animation on " << std::this_thread::get_id() << std::endl; 
		animation->render(repetitions); 
	}).detach(); 
}