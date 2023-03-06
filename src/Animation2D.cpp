#include "Animation2D.h"
#include <raylib.h>
#include <vector>
#include <iostream>
#include <string>
#include <array>
using namespace std; 
Animation2D::Animation2D(string imagePaths[], long frameDelaySeconds,int numFrames,Vector2 centPos) {
	this->centPos = centPos; 
	this->frameDelaySeconds = frameDelaySeconds; 
	this->numFrames = numFrames; 
	copy(&imagePaths[0], &imagePaths[numFrames], back_inserter(this->imagePaths)); // copies the animation image paths to a storage vector
}

void Animation2D::render(int repetitions) {
	int timer = 0; 
	for (int i = 0; i < numFrames; i++) {
		currImage = LoadImage(imagePaths.at(i).c_str());
		currTexture = LoadTextureFromImage(currImage); 
		UnloadImage(currImage); 
		DrawTextureV(currTexture, centPos, RAYWHITE); 
		while (timer < frameDelaySeconds) {
			timer += GetFrameTime(); 
		}
	}
}