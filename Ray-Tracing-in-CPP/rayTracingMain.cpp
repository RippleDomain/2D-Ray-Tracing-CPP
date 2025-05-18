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

	Circle circle = Circle(400, 300, 100);

	bool isSimRunning = true;
	SDL_Event event;

	while (isSimRunning)
	{
		while(SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_QUIT)
			{
				isSimRunning = false;
			}

			//Updates the circle's position based on mouse motion events.
			if (event.type == SDL_EVENT_MOUSE_MOTION && event.motion.state != 0)
			{
				circle.setX(event.motion.x); 
				circle.setY(event.motion.y);
			}
		}

		//Clears the screen after each iteration so the previous circle doesn't remain on the screen.
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		//Redraws the circle in its new position.
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		circle.fillCircle(renderer, circle);

		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}

	return 0;
}