#include <stdio.h>
#include <SDL3/SDL.h>
#include "Circle.h"
#include "Ray.h"

int main() 
{
	static const int WIDTH = 1920;
	static const int HEIGHT = 1080;

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow("Ray Tracing", WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	Circle circle = Circle(400, 540, 100);
	Circle shadowCircle = Circle(960, 540, 140);
	Ray ray = Ray(0, 0, 0);
	std::vector<Ray> rays;

	ray.generateRays(circle, rays);

	bool isSimRunning = true;
	SDL_Event event;

	while (isSimRunning == true)
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

				ray.generateRays(circle, rays);
			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
		circle.fillCircle(renderer, circle);
		ray.fillRays(renderer, rays, shadowCircle);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		circle.fillCircle(renderer, shadowCircle);

		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}

	return 0;
}