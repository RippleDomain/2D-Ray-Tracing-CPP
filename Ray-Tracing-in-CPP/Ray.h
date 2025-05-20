#pragma once
#include <vector>
#include "Circle.h"

class Ray
{
	static const int RAY_NUMBER = 150;

    float xStart, yStart;
    float angle;

    void drawRay(SDL_Renderer* renderer, float x, float y, float angle, std::vector<Circle*>& obstacles, int maxReflectCount);

public:
    Ray(int xStart, int yStart, float angle);

    void generateRays(Circle circle, std::vector<Ray>& rays);
    void fillRays(SDL_Renderer* renderer, std::vector<Ray>& rays, std::vector<Circle*>& obstacles, int maxReflectCount);
};