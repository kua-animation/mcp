#include "include/include.h"
#include "include/graphics.h"

#define WINDOW_SIZE_H 600
#define WINDOW_SIZE_W 800

int main(int argc, char* argv[]) {
	SDL_Window* window = SDL_CreateWindow("OpenGL_&_SDL", 
						SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
						WINDOW_SIZE_W, WINDOW_SIZE_H, 
						SDL_WINDOW_OPENGL
	);

	SDL_GLContext context = SDL_GL_CreateContext(window);

	glewInit();
	
	MCP_Init(WINDOW_SIZE_W, WINDOW_SIZE_H);

	int running = 1;
	SDL_Event event;

	MCPPosition Pos[6];
	MCPRotation Rret[6];
	
	float z = 0.5f;
		
	MCP_Set_Position(&Pos[0], z, 0.0f, -6.0f);
	MCP_Set_Position(&Pos[1], z+1.0f, 0.0f, -6.0f);
	MCP_Set_Position(&Pos[2], z+0.5f, 0.0f, -5.5f);
	
	MCP_Set_Rotation(&Rret[0], 90.0f, 0.0f, 1.0f, 0.0f);
	MCP_Set_Rotation(&Rret[1], 90.0f, 0.0f, 1.0f, 0.0f);

	while (running) {
		while (SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT) {
				running = 0;
			}
		}
		MCP_Render(Pos, Rret, window, 3);
		SDL_Delay(10);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

