#include "Circle.h"

Circle::Circle(int x, int y, int r, Type type)
{
    this->x = x;
    this->y = y;
    this->r = r;
	this->type = type;
}

//Fills a given circle with the color of the given renderer.
//Precomputes r^2 and uses that value in order to make the function only use one loop, and use the given y value to calculate the x span of the circle.
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