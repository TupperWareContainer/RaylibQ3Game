#include "Animation2D.h" 
#include <raylib.h>
#include <vector>
#include <iostream>
#include <string>
#include <array>
using namespace std; 
Animation2D::Animation2D(string imagePath, long frameDelaySeconds,int numFrames,Vector2 centPos, Vector2 dimensions) {
	this->frameDelaySeconds = frameDelaySeconds; 
	this->numFrames = numFrames; 
	//copy(&imagePaths[0], &imagePaths[numFrames], back_inserter(this->imagePaths)); // copies the animation image paths to a storage vector
	this->imagePath = imagePath; 
	spriteSheetTexture = LoadTexture(imagePath.c_str());
	currSprite.x = centPos.x; 
	currSprite.y = centPos.y; 
	currSprite.width = dimensions.x; 
	currSprite.height = dimensions.y; 
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
	int frameCounter = 0; 
	int timer = 0; 
	float initX = currSprite.x; 
	for (int i = 0; i < repetitions; i++) {
		for (int frame = 0; frame < frameCounter; frame++) {
			while (timer < frameDelaySeconds) {
				DrawTextureRec(spriteSheetTexture, currSprite, { currSprite.x,currSprite.y }, WHITE);
				timer += GetFrameTime();
			}
			currSprite.x += currSprite.width; 
		}
		currSprite.x = initX; 
	}
}