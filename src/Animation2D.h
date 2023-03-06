#pragma once
#include <raylib.h>
#include <vector>
#include <iostream>
#include <string>
#include <array>
class Animation2D
{
	public:
		Animation2D(std::string imagePaths[],long frameDelaySeconds,int numFrames,Vector2 centPos); 
		void render(int repetitions);

	private:
		long frameDelaySeconds; 
		int numFrames; 
		Texture currTexture; 
		Image currImage; 
		Vector2 centPos; 
		std::vector<std::string> imagePaths; 
}; 