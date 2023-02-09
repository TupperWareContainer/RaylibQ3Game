#include <raylib.h>

class Player{
    private:
    Vector2 pos; 

    public: 
    void setPosition(float,float); 
    Vector2 getPosition(); 
    void renderPlayer(); 

}; 