#include "include/graphic.h"

void MCP_DrawLine(SDL_Renderer* Ren, MCPLine line, MCPColor color) {
	SDL_SetRenderDrawColor(Ren, color.R, color.G, color.B, color.A);
	SDL_RenderDrawLine(Ren, line.X, line.Y, line.X1, line.Y1);
}

void MCP_DrawBlock(SDL_Renderer* Ren, MCPPosition Pos, MCPColor color) {
	SDL_SetRenderDrawColor(Ren, color.R, color.G, color.B, color.A);
	for (int i = 0; i < 10; i ++) {
		for ( int j = 0; j < 10; j ++) {

			SDL_RenderDrawPoint(Ren, Pos.X + i, Pos.Y + j);
		}
	}
}

