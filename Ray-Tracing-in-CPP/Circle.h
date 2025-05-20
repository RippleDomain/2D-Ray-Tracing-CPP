#pragma once
#include <SDL3/SDL.h>

//Type of circle object.
enum Type 
{
	Reflective,
	Absorptive
};

class Circle
{
    float x, y, r;
	Type type;

public:
    Circle(int x, int y, int r, Type type);

	//Fills a given circle with the color of the given renderer.
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
    Type getType() const 
    {
        return type; 
	}
};