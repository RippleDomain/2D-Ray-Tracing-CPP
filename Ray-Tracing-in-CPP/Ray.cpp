#include "Ray.h"
#include <stdio.h>
#include <math.h>

Ray::Ray(int xStart, int yStart, float angle)
{
    this->xStart = xStart;
    this->yStart = yStart;
    this->angle = angle;
}

//Iterates over the number of rays and generates them from the surface of the given circle, each with their own calculated angle.
void Ray::generateRays(Circle circle, std::vector<Ray>& rays)
{
    rays.clear();

    for (int i = 0; i < RAY_NUMBER; i++)
    {
        double angle = ((float)i / RAY_NUMBER) * 2 * 3.14;

		//Rays originate from the surface, not the center of the circle.
		Ray ray = Ray(circle.getX() + (circle.getR() + 1.0f) * cos(angle), circle.getY() + (circle.getR() + 1.0f) * sin(angle), angle);
        rays.push_back(ray);
    }
}

//Calls the drawRay function for each ray in the vector.
void Ray::fillRays(SDL_Renderer* renderer, std::vector<Ray>& rays, std::vector<Circle*>& obstacles, int maxReflectCount)
{
    for (Ray& ray : rays)
    {
        drawRay(renderer, ray.xStart, ray.yStart, ray.angle, obstacles, maxReflectCount);
    }
}

//Draws a ray based on the given angle and position, taking into account collision with obstacles.
void Ray::drawRay(SDL_Renderer* renderer, float x, float y, float angle, std::vector<Circle*>& obstacles, int maxReflectCount)
{
    //There is a limit on the amount of reflections possible.
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

	//There is a reasonable limit on the distance a ray can travel.
    while (traveled < maxDist)
    {
		//Tracks the current position of the ray until it hits an obstacle or goes out of bounds.
        xCurrent += step * cos(angle);
        yCurrent += step * sin(angle);

        traveled += step;

		//Out of bounds check.
        if (xCurrent < 0 || xCurrent > 1920 || yCurrent < 0 || yCurrent > 1080) 
        {
			break;
        }

		//Collision check with obstacles.
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

		//If a collision is detected, break out of the loop.
        if (hit)
        {
            break;
        }
    }

	//Render the ray calculated so far.
    SDL_RenderLine(renderer, x, y, xCurrent, yCurrent);

	//If a collision is detected and if the obstacle is reflective, calculate the reflection angle and draw the reflected ray.
    if (hit && hit->getType() == Reflective) 
    {
		//Take the normal of the surface at the point of collision, find its length and convert it to a unit vector.
		float xNormal = xCurrent - hit->getX();
        float yNormal = yCurrent - hit->getY();
        float length = sqrt(xNormal * xNormal + yNormal * yNormal);

        xNormal /= length;
        yNormal /= length;

        //Take the unit vector of the incoming ray.
		float xIncrement = cos(angle);
		float yIncrement = sin(angle);

		//Calculate the dot product of the incoming ray and the normal vector.
        float dotProduct = (cos(angle) * xNormal + sin(angle) * yNormal);

		//Calculate the reflected angle using the normal vector and the dot product.
        //Check the README for a reference to an explanation of the formula used.
		float xReflected = xIncrement - xNormal * dotProduct * 2;
        float yReflected = yIncrement - yNormal * dotProduct * 2;
        float reflectedAngle = atan2(yReflected, xReflected);

		//Render the reflected ray.
		drawRay(renderer, xCurrent, yCurrent, reflectedAngle, obstacles, maxReflectCount - 1);
    }
}