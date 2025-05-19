#include "Circle.h"

Circle::Circle(int x, int y, int r)
{
    this->x = x;
    this->y = y;
    this->r = r;
}

void Circle::fillCircle(SDL_Renderer* renderer, Circle circle)
{
    double r2 = circle.r * circle.r;

    for (double x = circle.x - circle.r; x <= circle.x + circle.r; x++)
    {
        for (double y = circle.y - circle.r; y < circle.y + circle.r; y++)
        {
            if ((x - circle.x) * (x - circle.x) + (y - circle.y) * (y - circle.y) <= r2)
            {
                SDL_RenderPoint(renderer, x, y);
            }
        }
    }
}

void Circle::setX(int x) 
{ 
    this->x = x; 
}
void Circle::setY(int y) 
{ 
    this->y = y; 
}