#include "include/loop.h"

void Loop(MCPPosition Pos[], MCPPosition OfSet[], MCPPlayer Player, MCPRotation Rotation[], SDL_Window* window) {
	int running = 1;
	SDL_Event event;


	while (running) {
		while (SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT) {
				running = 0;
			}
					if (KeyPress(event) ==  SDLK_a) {
						Player.x -= 0.1f;
						for (int i = 0; i < 4; i ++) {
							MCP_Set_Position_By_Player(&Pos[i], OfSet[i], Player);
						}
					}
					if (KeyPress(event) == SDLK_s) {
						Player.x += 0.1f;
						for (int i = 0; i < 4; i ++) {
							MCP_Set_Position_By_Player(&Pos[i], OfSet[i], Player);
						}
					}
					if (KeyPress(event) == SDLK_q) {
						Player.z += 0.1f;
						for (int i = 0; i < 4; i ++) {
							MCP_Set_Position_By_Player(&Pos[i], OfSet[i], Player);
						}
					}
					if (KeyPress(event) == SDLK_w) {
						Player.z -= 0.1f;
						for (int i = 0; i < 4; i ++) {
							MCP_Set_Position_By_Player(&Pos[i], OfSet[i], Player);
						}
					}	
					if (KeyPress(event) == SDLK_y) {
						Player.y += 0.1f;
						for (int i = 0; i < 4; i ++) {
							MCP_Set_Position_By_Player(&Pos[i], OfSet[i], Player);
						}
					}
					if (KeyPress(event) == SDLK_x) {
						Player.y -= 0.1f;
						for (int i = 0; i < 4; i ++) {
							MCP_Set_Position_By_Player(&Pos[i], OfSet[i], Player);
						}
					}
				
			
		}
		MCP_Render(Pos, Rotation, window, 8);
		SDL_Delay(10);
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
}
