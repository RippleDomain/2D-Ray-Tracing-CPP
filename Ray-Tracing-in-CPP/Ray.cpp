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
		Ray ray = Ray(circle.getX(), circle.getY(), angle);
        rays.push_back(ray);
    }
}

void Ray::fillRays(SDL_Renderer* renderer, std::vector<Ray>& rays, Circle obstacle) 
{
    float r2 = obstacle.getR() * obstacle.getR();

    for (int i = 0; i < rays.size(); i++)
    {
		Ray ray = rays[i];
        
		bool hitBorder = false;
		bool hitCircle = false;

        float step = 1.0f;
		float xDraw = ray.xStart;
        float yDraw = ray.yStart;

        while (!hitBorder && !hitCircle)
        {
            xDraw += step * cos(ray.angle);
            yDraw += step * sin(ray.angle);
            SDL_RenderPoint(renderer, xDraw, yDraw);

            if (xDraw < 0 || xDraw > 1920 || yDraw < 0 || yDraw > 1080)
            {
                hitBorder = true;
            }
            if ((xDraw - obstacle.getX()) * (xDraw - obstacle.getX()) + (yDraw - obstacle.getY()) * (yDraw - obstacle.getY()) <= r2) 
            {
				hitCircle = true;
            }
        }
	}
}