#include <stdio.h>
#include <SDL3/SDL.h>

struct Circle
{
	float x, y, r;
};

void fillCircle(SDL_Renderer* renderer, Circle circle)
{
	float x = circle.r;
	float y = 0.0f;
	float err = 0.0f;

	while (x >= y)
	{
		SDL_RenderLine(renderer, circle.x - x, circle.y + y, circle.x + x, circle.y + y);
		SDL_RenderLine(renderer, circle.x - y, circle.y + x, circle.x + y, circle.y - x);
		SDL_RenderLine(renderer, circle.x - x, circle.y - y, circle.x + x, circle.y - y);
		SDL_RenderLine(renderer, circle.x - y, circle.y - x, circle.x + y, circle.y + x);

		if (err <= 0.0f)
		{
			y += 1.0f;
			err += 2.0f * y + 1.0f;
		}
		if (err > 0.0f)
		{
			x -= 1.0f;
			err -= 2.0f * x + 1.0f;
		}
	}
}

int main() 
{
	static const int WIDTH = 800;
	static const int HEIGHT = 600;

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow("Ray Tracing", WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	Circle circle = {400, 300, 100};
	fillCircle(renderer, circle);

	SDL_RenderPresent(renderer);

	SDL_Delay(5000);

	return 0;
}