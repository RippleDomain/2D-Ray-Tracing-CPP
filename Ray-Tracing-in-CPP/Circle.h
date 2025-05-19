#pragma once
#include <SDL3/SDL.h>

class Circle
{
    float x, y, r;

public:
    Circle(int x, int y, int r);

    void fillCircle(SDL_Renderer* renderer, Circle circle);

    void setX(int x);
    void setY(int y);

    float getX() const 
    { 
        return x; 
    }
    float getY() const 
    {
        return y; 
    }
    float getR() const 
    {
        return r; 
    }
};