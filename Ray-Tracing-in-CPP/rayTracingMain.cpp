#include <stdio.h>
#include <SDL3/SDL.h>
#include <vector>
#include "Circle.h"
#include "Ray.h"

int main()
{
	//Initialize the window and renderer.
    static const int WIDTH = 1920;
    static const int HEIGHT = 1080;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Ray Tracing", WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);

	//Initialize the circles and adds them into a vector.
    Circle circle = Circle(960, 540, 100, Absorptive);
    Circle shadowCircle = Circle(1600, 540, 140, Absorptive);
    Circle reflectCircle = Circle(320, 540, 140, Reflective);

    std::vector<Circle*> obstacles;
    obstacles.push_back(&circle);
    obstacles.push_back(&shadowCircle);
    obstacles.push_back(&reflectCircle);

	//Initialize the rays.
    std::vector<Ray> rays;
    Ray ray(0, 0, 0);
    ray.generateRays(circle, rays);

    bool isSimRunning = true;
    SDL_Event event;

    while (isSimRunning == true)
    {
        while (SDL_PollEvent(&event))
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

        //Clear the screen.
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

		//Renders the rays and circles.
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        ray.fillRays(renderer, rays, obstacles, 3);

        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        circle.fillCircle(renderer, circle);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        reflectCircle.fillCircle(renderer, reflectCircle);

        SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
        reflectCircle.fillCircle(renderer, shadowCircle);

        SDL_RenderPresent(renderer);
    }

    return 0;
}