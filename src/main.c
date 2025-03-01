#include <stdio.h>
#include <stdlib.h>
#include "include/graphic.h"
#include "include/physics.h"

#define MCP_PARTICLE 15
#define MCP_WINDOW_W 1200
#define MCP_WINDOW_H 400 

SDL_Window* CreateWindow(int width, int height, const char* title);

SDL_Renderer* CreateRenderer(SDL_Window* window);

MCPPosition Pos[MCP_PARTICLE];

int main(int argc, char *argv[]) {
	SDL_Window* Win;
	Win = CreateWindow(MCP_WINDOW_W, MCP_WINDOW_H, "andrej");
	SDL_Renderer* Ren = CreateRenderer(Win);

	SDL_Event event;
	int running = 1;
	int MovIng = 0;

	int DirX = 0;
	int DirY = 0;

	Pos[MCP_PARTICLE-1].X = 200/MCP_PARTICLE;
	Pos[MCP_PARTICLE-1].Y = 200/MCP_PARTICLE;

	Pos[0].X = 2;
	Pos[0].Y = 0;

	MCPColor colorline = {180, 255, 210, 255};
	MCPColor colorPoints = {210, 100, 120, 255};

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
		
		if (MCP_Physics_Move(Pos[0], MCP_WINDOW_W, MCP_WINDOW_H)) {
			printf("a");
			fflush(stdout);
		}

		SDL_GetMouseState(&Pos[0].X, &Pos[0].Y);

		SDL_SetRenderDrawColor(Ren, 0, 0, 0, 255);
		SDL_RenderClear(Ren);
		if (MovIng) {
			MCP_Physics_Points(Ren, Pos, MCP_PARTICLE, colorPoints);
		} else { 
			MCP_Physics_Chain(Ren, Pos, MCP_PARTICLE, 0, colorPoints, colorline);
		}
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


