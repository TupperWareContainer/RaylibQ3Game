#include <raylib.h>
#include "Player.h"
 

void Player::setPosition(float posX,float posY){
    pos = {posX,posY}; 
}
void Player::renderPlayer(){
    Vector2 size = {10,10}; 
    
    DrawRectangleV(pos,size,RED);  
}
Vector2 Player::getPosition(){
   
    return pos; 
}