#include "Animation2D.h" 
#include <raylib.h>
#include <vector>
#include <iostream>
#include <string>
#include <array>
#include <thread>
#include <chrono>
using namespace std; 
Animation2D::Animation2D(string imagePath, long frameDelaySeconds,int numFrames,Vector2 centPos, Vector2 dimensions) {
	this->frameDelaySeconds = frameDelaySeconds; 
	this->numFrames = numFrames; 
	//copy(&imagePaths[0], &imagePaths[numFrames], back_inserter(this->imagePaths)); // copies the animation image paths to a storage vector
	this->imagePath = imagePath; 
	this->centPos = centPos; 
	currSprite = { 0,0,dimensions.x,dimensions.y }; 
	this->imagePath = imagePath; 
}

void Animation2D::render(int repetitions) {
	/*int timer = 0; 
	for (int i = 0; i < numFrames; i++) {
		currImage = LoadImage(imagePaths.at(i).c_str());
		currTexture = LoadTextureFromImage(currImage); 
		UnloadImage(currImage); 
		DrawTextureV(currTexture, centPos, RAYWHITE); 
		while (timer < frameDelaySeconds) {
			timer += GetFrameTime(); 
		}
	}*/
	///https://www.raylib.com/examples.html <- look at sprite anim example
	int frameCounter = 0; 
	int reps = 0; 
	int timer = 0; 
	float initX = currSprite.x; 
	int currentFrame = 0; 
	spriteSheetTexture = LoadTexture(imagePath.c_str()); 
	while (reps < repetitions) {
		frameCounter++; 
		if (frameCounter >= frameDelaySeconds * 60) {
			currentFrame++; 
			if (currentFrame > numFrames) {
				reps++; 
				currentFrame = 0;
				currSprite.x = (float)currentFrame * (float)spriteSheetTexture.width / numFrames;
			}
		}
		DrawRectangleV({ currSprite.x,currSprite.y }, { currSprite.width,currSprite.height }, RED);
		DrawTextureRec(spriteSheetTexture, currSprite, centPos, WHITE); 
	}
	
}