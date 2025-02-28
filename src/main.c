#include <stdio.h>
#include <stdlib.h>
#include "include/graphic.h"
#include "include/physics.h"

#define Points 100

SDL_Window* CreateWindow(int width, int height, const char* title);

SDL_Renderer* CreateRenderer(SDL_Window* window);

MCPPosition Pos[Points];


int main(int argc, char *argv[]) {
	SDL_Window* Win;
	Win = CreateWindow(1200, 1200, "andrej");
	SDL_Renderer* Ren = CreateRenderer(Win);

	SDL_Event event;
	int running = 1;
	int MovIng = 0;

	Pos[Points-1].X = 200/Points;
	Pos[Points-1].Y = 200/Points;

	MCPColor colorline = {255, 255, 255, 255};

	while (running)	{
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT ) {
				running = 0;				
			}
			if (WasButtonPress(event)) {
				if (MovIng) {
					MovIng = 0;
				} else {
					MovIng = 1;
				}
			}
		}
			
		if (MovIng) {
			SDL_GetMouseState(&Pos[0].X, &Pos[0].Y);
		}
		
		
		SDL_SetRenderDrawColor(Ren, 0, 0, 0, 255);
		SDL_RenderClear(Ren);

		MCP_Physics_Line(Ren, Pos, Points, colorline);

		SDL_RenderPresent(Ren);

		SDL_Delay(10);
	}

	SDL_DestroyWindow(Win);
	SDL_DestroyRenderer(Ren);
	SDL_Quit();

	return 0; }


SDL_Window* CreateWindow(int width, int height, const char* title) {
	SDL_Window* window = SDL_CreateWindow(title, 
				SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	return window;
}

SDL_Renderer* CreateRenderer(SDL_Window* window) {
	SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);
	
	return render;
}


