#pragma once
#include <vector>
#include "Circle.h"

class Ray
{
	static const int RAY_NUMBER = 100;

    float xStart, yStart;
    float angle;

public:
    Ray(int xStart, int yStart, float angle);

    void generateRays(Circle circle, std::vector<Ray>& rays);
    void fillRays(SDL_Renderer* renderer, std::vector<Ray>& rays, Circle obstacle);
};