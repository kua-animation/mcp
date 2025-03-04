#include "include/video.h"

void MCP_Init(int w, int h) {
	glewInit();
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (float)w/ (float)h, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

void MCP_Render(MCPPosition Pos[], MCPRotation Rret[], SDL_Window* Win, int count) {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glLoadIdentity();

	for (int i = 0; i < count; i++) {
		MCP_Draw_Plane(Pos[i], Rret[i], Win);
	}

	SDL_GL_SwapWindow(Win);

}

SDL_Window* MCP_Create_Window(char* title, int w, int h) {
	SDL_Window* Win = SDL_CreateWindow(title, 
				SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED,
				w, h, SDL_WINDOW_OPENGL
	);
	cl_context context = SDL_GL_CreateContext(Win);
	
	return Win;

}

void MCP_Main_Loop(void (*Main_Loop)(MCPPosition[], MCPPosition[], MCPPlayer,  MCPRotation[], SDL_Window*),MCPPosition Pos[], MCPPosition OfSet[], MCPPlayer Player, MCPRotation Rotation[], SDL_Window* Win) {


Main_Loop(Pos, OfSet, Player, Rotation, Win);

}
