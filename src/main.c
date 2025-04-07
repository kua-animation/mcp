#include "include/include.h"
#include "include/graphics.h"
#include "include/video.h"
#include "include/controls.h"
#include "include/loop.h"

#define WINDOW_SIZE_H 600
#define WINDOW_SIZE_W 800

MCPPosition Pos[8];
MCPRotation Rret[8];
MCPPosition Ofset[8]; 
MCPPosition CPos[2];

MCPPlayer Player = {0.0f, 0.0f, 0.0f};

int main(int argc, char* argv[]) {
	MCP_Set_Position(&CPos[0], 0.0f, 0.0f, -4.0f);
	MCP_Set_Position(&CPos[1], 1.0f, 1.9f, -10.0f);	

	SDL_Window* window  = MCP_Create_Window("OpenGL_&_SDL", WINDOW_SIZE_W, WINDOW_SIZE_H);

	MCP_Init(WINDOW_SIZE_W, WINDOW_SIZE_H);

	MCP_Draw_Cube(Ofset, Pos, Rret, CPos[0], Player, 0);
	MCP_Draw_Cube(Ofset, Pos, Rret, CPos[1], Player, 4);
	
	MCP_Main_Loop(Loop, Pos, Ofset, Player, Rret, window);

	return 0;
}
