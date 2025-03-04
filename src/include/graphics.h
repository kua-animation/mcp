#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "include.h"

typedef struct MCPPosition {
	float x;
	float y;
	float z;
} MCPPosition;

typedef struct MCPRotation {
	float a;
	float x;
	float y;
	float z;
} MCPRotation;

typedef struct MCPPlayer {
	float x;
	float y;
	float z;
} MCPPlayer;


void MCP_Draw_Plane(MCPPosition Pos, MCPRotation Rotation, SDL_Window* Win);

void MCP_Set_Position(MCPPosition *Pos, float x, float y, float z);

void MCP_Set_Rotation(MCPRotation *Rotation, float a, float x, float y, float z); 

void MCP_Init(int w, int h);

void MCP_Render(MCPPosition Pos[], MCPRotation Rret[], SDL_Window* Win, int count);

void MCP_Set_Position_By_Ofset(MCPPosition *Pos, MCPPosition Ofset);

void MCP_Set_Position_By_Player(MCPPosition *Pos, MCPPosition Ofset, MCPPlayer Player);

#endif
