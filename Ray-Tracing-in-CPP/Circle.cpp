#include "Circle.h"

Circle::Circle(int x, int y, int r, Type type)
{
    this->x = x;
    this->y = y;
    this->r = r;
	this->type = type;
}

void Circle::fillCircle(SDL_Renderer* renderer, Circle circle)
{
	float r2 = circle.r * circle.r;

    for (float y = -circle.r; y <= circle.r; y++) 
    {
        float xSpan = sqrt(r2 - y * y);
        SDL_RenderLine(renderer, circle.x - xSpan, circle.y + y, circle.x + xSpan, circle.y + y);
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