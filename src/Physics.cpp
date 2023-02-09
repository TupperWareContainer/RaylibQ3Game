#include <raylib.h>
#include "Physics.h"

double gravity = 9.81; 

double Physics::getGlobalGravity(){
    return gravity; 
}
void Physics::setGlobalGravity(double newGravity){
    gravity = newGravity; 
}