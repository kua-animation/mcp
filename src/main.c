#include <stdio.h>
#include <stdlib.h>
#include "include/graphic.h"
#include "include/physics.h"

SDL_Window* CreateWindow(int width, int height, const char* title);

SDL_Renderer* CreateRenderer(SDL_Window* window);

MCPPosition Pos[3];


int main(int argc, char *argv[]) {
	SDL_Window* Win;
	if (argc >= 4) {
		Win = CreateWindow(atoi(argv[1]), atoi(argv[2]), argv[3]);
	} else {
		Win = CreateWindow(300, 300, "andrej");
	}
	SDL_Renderer* Ren = CreateRenderer(Win);

	SDL_Event event;
	SDL_MouseButtonEvent button;
	int running = 1;

	Pos[1].X = 100;
	Pos[1].Y = 100;
	Pos[2].X = 50;
	Pos[2].Y = 50;
	MCPLine line;
	MCPColor colorline = {255, 255, 255, 255};

	while (running)	{
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT ) {
				running = 0;
			} if (event.type == SDL_MOUSEBUTTONDOWN) {
				SDL_GetMouseState(&Pos[0].X, &Pos[0].Y);
			}
		}

		line.X = Pos[0].X;
		line.Y = Pos[0].Y;
		line.X1 = Pos[1].X;
		line.Y1 = Pos[1].Y;



		CalkDistion(Pos[2], &Pos[1], Pos[0]);

		SDL_SetRenderDrawColor(Ren, 0, 0, 0, 255);
		SDL_RenderClear(Ren);

		MCP_DrawBlock(Ren, Pos[0], colorline);

		MCP_DrawBlock(Ren, Pos[1], colorline);
	
		MCP_DrawLine(Ren, line, colorline);

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
				width, height, SDL_WINDOW_SHOWN);

	return window;
}

SDL_Renderer* CreateRenderer(SDL_Window* window) {
	SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);
	
	return render;
}


