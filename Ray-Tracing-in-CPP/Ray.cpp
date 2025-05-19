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

		Ray ray = Ray(circle.getX() + circle.getR() * cos(angle), circle.getY() + circle.getR() * sin(angle), angle);
        rays.push_back(ray);
    }
}

void Ray::fillRays(SDL_Renderer* renderer, std::vector<Ray>& rays, Circle obstacle)
{
    float r2 = obstacle.getR() * obstacle.getR();

    for (Ray& ray : rays)
    {
        float step = 1.0f;

        float xDraw = ray.xStart;
        float yDraw = ray.yStart;

        float xEnd = xDraw;
        float yEnd = yDraw;

        while (true)
        {
            xEnd += step * cos(ray.angle);
            yEnd += step * sin(ray.angle);

            if (xEnd < 0 || xEnd > 1920 || yEnd < 0 || yEnd > 1080) 
            {
                break;
            }

            if ((xEnd - obstacle.getX()) * (xEnd - obstacle.getX()) + (yEnd - obstacle.getY()) * (yEnd - obstacle.getY()) <= r2)
            {
                break;
            }
        }

        SDL_RenderLine(renderer, xDraw, yDraw, xEnd, yEnd);
    }
}