#pragma once
#include <raylib.h>
#include <vector>
#include <iostream>
#include <string>
#include <array>
#include <thread>
#include <chrono>
class Animation2D
{
	public:
		Animation2D(std::string imagePath,long frameDelaySeconds,int numFrames,Vector2 centPos,Vector2 dimensions); 
		void render(int repetitions);
		//int getPort(); 
	private:
		long frameDelaySeconds; 
		//int port; 
		int numFrames; 
		Texture spriteSheetTexture; 
		Rectangle currSprite; 
		Vector2 centPos; 
		//Image currImage; 
		std::string imagePath; 
}; 