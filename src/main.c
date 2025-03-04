#include "include/include.h"
#include "include/graphics.h"
#include "include/video.h"

#define WINDOW_SIZE_H 600
#define WINDOW_SIZE_W 800

MCPPosition Pos[6];
MCPRotation Rret[6];
MCPPosition Ofset[6]; 
	
MCPPlayer Player = {0.5f, 0.0f, 0.0f};
void Loop(MCPPosition Pos[], MCPPosition OfSet[], MCPPlayer Player, MCPRotation Rotation[], SDL_Window* window);

int main(int argc, char* argv[]) {


	SDL_Window* window  = MCP_Create_Window("OpenGL_&_SDL", WINDOW_SIZE_W, WINDOW_SIZE_H);

	MCP_Init(WINDOW_SIZE_W, WINDOW_SIZE_H);

	
	MCP_Set_Position(&Ofset[0], 0.0f, 0.0f, -6.0f);
	MCP_Set_Position(&Ofset[1], 1.0f, 0.0f, -6.0f);
	MCP_Set_Position(&Ofset[2], 0.5f, 0.0f, -5.5f);
	
	for (int i = 0; i < 3; i ++) {
		MCP_Set_Position_By_Player(&Pos[i], Ofset[i], Player);
	}

	MCP_Set_Rotation(&Rret[0], 90.0f, 0.0f, 1.0f, 0.0f);
	MCP_Set_Rotation(&Rret[1], 90.0f, 0.0f, 1.0f, 0.0f);

	MCP_Main_Loop(Loop, Pos, Ofset, Player, Rret, window);

	return 0;
}

void Loop(MCPPosition Pos[], MCPPosition OfSet[], MCPPlayer Player, MCPRotation Rotation[], SDL_Window* window) {
	int running = 1;
	SDL_Event event;


	while (running) {
		while (SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT) {
				running = 0;
			} if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {
					case SDLK_a:
						Player.x -= 0.1f;
						for (int i = 0; i < 3; i ++) {
							MCP_Set_Position_By_Player(&Pos[i], Ofset[i], Player);
						}
					break;
					case SDLK_d:
						Player.x += 0.1f;
						for (int i = 0; i < 3; i ++) {
							MCP_Set_Position_By_Player(&Pos[i], Ofset[i], Player);
						}
					break;
					case SDLK_w:
						Player.z += 0.1f;
						for (int i = 0; i < 3; i ++) {
							MCP_Set_Position_By_Player(&Pos[i], Ofset[i], Player);
						}
					break;
					case SDLK_s:
						Player.z -= 0.1f;
						for (int i = 0; i < 3; i ++) {
							MCP_Set_Position_By_Player(&Pos[i], Ofset[i], Player);
						}
					break;
				}
			}
		}
		MCP_Render(Pos, Rret, window, 3);
		SDL_Delay(10);
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	
}
