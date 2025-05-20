#pragma once
#include <vector>
#include "Circle.h"

class Ray
{
	static const int RAY_NUMBER = 150;

    float xStart, yStart;
    float angle;

	//Draws a ray based on the given angle and position, taking into account collision with obstacles.
    void drawRay(SDL_Renderer* renderer, float x, float y, float angle, std::vector<Circle*>& obstacles, int maxReflectCount);

public:
    Ray(int xStart, int yStart, float angle);

    //Generates a vector of rays from the circle that will be drawn later.
    void generateRays(Circle circle, std::vector<Ray>& rays);
	//Publicly accessible method to draw rays.
    void fillRays(SDL_Renderer* renderer, std::vector<Ray>& rays, std::vector<Circle*>& obstacles, int maxReflectCount);
};