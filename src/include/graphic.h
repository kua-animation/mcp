#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

typedef struct MCPLine {
	int X;
	int Y;
	int X1;
	int Y1;

} MCPLine;

typedef struct MCPPosition {
	int X;
	int Y;
} MCPPosition;

typedef struct MCPColor {
	int R;
	int B;
	int G;
	int A;
} MCPColor;

void MCP_DrawLine(SDL_Renderer* Ren, MCPLine line, MCPColor color);

void MCP_DrawBlock(SDL_Renderer* Ren, MCPPosition Pos, MCPColor color);

#endif
