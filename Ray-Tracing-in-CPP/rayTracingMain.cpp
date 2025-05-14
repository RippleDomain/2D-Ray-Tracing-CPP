#include <stdio.h>
#include <SDL3/SDL.h>

int main() 
{
	static const int WIDTH = 800;
	static const int HEIGHT = 600;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("Ray Tracing", SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT);

	return 0;
}