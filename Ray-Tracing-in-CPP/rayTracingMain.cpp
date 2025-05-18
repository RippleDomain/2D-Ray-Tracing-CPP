#include <stdio.h>
#include <SDL3/SDL.h>
#include "Circle.cpp"

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

	Circle* circle = new Circle(400, 300, 100);
	circle->fillCircle(renderer, *circle);

	SDL_RenderPresent(renderer);

	SDL_Delay(5000);

	delete circle;

	return 0;
}