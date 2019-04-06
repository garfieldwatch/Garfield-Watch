#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "main.h"

using namespace std;

int hight = 300;
int width = 200;

void WindowDraw() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL could not init!");
		SDL_GetError();
	}
	else {
		SDL_Window *window;
		SDL_Renderer *renderer;
		SDL_Surface *image = SDL_LoadBMP("garfield.bmp");
		SDL_Texture *texture;

		SDL_Init(SDL_INIT_VIDEO);
		IMG_Init(IMG_INIT_PNG);

		//WINDOW
		window = SDL_CreateWindow(
			"Garfield is always watching you.",
			5, 5,
			hight, width, SDL_WINDOW_BORDERLESS | SDL_WINDOW_ALWAYS_ON_TOP
		);

		if (!window) {
			printf("Failed to create Window ;(");
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		texture = SDL_CreateTextureFromSurface(renderer, image);

		int right = 0;
		int down = 0;

		//MAIN LOOP
		while (1) {
			SDL_Event e;
			while (SDL_PollEvent(&e)) {
				if (e.type == SDL_KEYDOWN) {
					switch (e.key.keysym.sym) {
					case SDLK_RIGHT:
						right = right + 10;

						SDL_SetWindowPosition(window, right, down);
						break;
					case SDLK_DOWN:
						down = down + 10;

						SDL_SetWindowPosition(window, right, down);
						break;
					case SDLK_LEFT:
						right = right - 10;

						SDL_SetWindowPosition(window, right, down);
						break;
					case SDLK_UP:
						down = down - 10;

						SDL_SetWindowPosition(window, right, down);
						break;
					case SDLK_0:
						SDL_ShowWindow(window);
						break;
					case SDLK_1:
						SDL_HideWindow(window);
						break;
					case SDL_QUIT:
						SDL_Delay(100);
						SDL_DestroyTexture(texture);
						SDL_FreeSurface(image);
						SDL_DestroyRenderer(renderer);
						SDL_DestroyWindow(window);
						IMG_Quit();
						SDL_Quit();
						break;
					case SDLK_ESCAPE:
						SDL_Delay(100);
						SDL_DestroyTexture(texture);
						SDL_FreeSurface(image);
						SDL_DestroyRenderer(renderer);
						SDL_DestroyWindow(window);
						IMG_Quit();
						SDL_Quit();
						break;
					default:
						break;
					}
				}

			}

			SDL_RenderCopy(renderer, texture, NULL, NULL);
			SDL_RenderPresent(renderer);
		}

		//END
		SDL_Delay(1000);
		SDL_DestroyTexture(texture);
		SDL_FreeSurface(image);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		IMG_Quit();
		SDL_Quit();
	}
}
