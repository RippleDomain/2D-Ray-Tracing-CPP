#include "Ray.h"
#include <stdio.h>
#include <math.h>

Ray::Ray(int xStart, int yStart, float angle)
{
    this->xStart = xStart;
    this->yStart = yStart;
    this->angle = angle;
}

void Ray::generateRays(Circle circle, std::vector<Ray>& rays)
{
    rays.clear();

    for (int i = 0; i < RAY_NUMBER; i++)
    {
        double angle = ((float)i / RAY_NUMBER) * 2 * 3.14;

		Ray ray = Ray(circle.getX() + (circle.getR() + 1.0f) * cos(angle), circle.getY() + (circle.getR() + 1.0f) * sin(angle), angle);
        rays.push_back(ray);
    }
}

void Ray::fillRays(SDL_Renderer* renderer, std::vector<Ray>& rays, std::vector<Circle*>& obstacles, int maxReflectCount)
{
    for (Ray& ray : rays)
    {
        drawRay(renderer, ray.xStart, ray.yStart, ray.angle, obstacles, maxReflectCount);
    }
}

void Ray::drawRay(SDL_Renderer* renderer, float x, float y, float angle, std::vector<Circle*>& obstacles, int maxReflectCount)
{
    if (maxReflectCount <= 0)
    {
		return;
    }

    float step = 1.0f;
    float maxDist = 2000.0f;
    float traveled = 0.0f;
    float xCurrent = x;
    float yCurrent = y;

    Circle* hit = nullptr;

    while (traveled < maxDist)
    {
        xCurrent += step * cos(angle);
        yCurrent += step * sin(angle);

        traveled += step;

        if (xCurrent < 0 || xCurrent > 1920 || yCurrent < 0 || yCurrent > 1080) 
        {
			break;
        }

        for (Circle* circle : obstacles)
        {
            float xDistance = xCurrent - circle->getX();
            float yDistance = yCurrent - circle->getY();

            if (xDistance * xDistance + yDistance * yDistance <= circle->getR() * circle->getR())
            {
                hit = circle;

                break;
            }
        }

        if (hit)
        {
            break;
        }
    }

    SDL_RenderLine(renderer, x, y, xCurrent, yCurrent);

    if (hit && hit->getType() == Reflective) 
    {
		float xNormal = xCurrent - hit->getX();
        float yNormal = yCurrent - hit->getY();
        float length = sqrt(xNormal * xNormal + yNormal * yNormal);

        xNormal /= length;
        yNormal /= length;

		float xIncrement = cos(angle);
		float yIncrement = sin(angle);

        float dotProduct = (cos(angle) * xNormal + sin(angle) * yNormal);
		float xReflected = xIncrement - xNormal * dotProduct * 2;
        float yReflected = yIncrement - yNormal * dotProduct * 2;
        float reflectedAngle = atan2(yReflected, xReflected);

		drawRay(renderer, xCurrent, yCurrent, reflectedAngle, obstacles, maxReflectCount - 1);
    }
}