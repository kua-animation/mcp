#ifndef VIDEO_H
#define VIDEO_H

#include "include.h"
#include "graphics.h"

void MCP_Init(int w, int h);

void MCP_Render(MCPPosition Pos[], MCPRotation Rret[], SDL_Window* Win, int count);

SDL_Window* MCP_Create_Window(char* title, int w, int h);

void MCP_Main_Loop(void (*Main_Loop)(MCPPosition[], MCPPosition[], MCPPlayer,  MCPRotation[], SDL_Window*),MCPPosition Pos[], MCPPosition OfSet[], MCPPlayer Player, MCPRotation Rotation[], SDL_Window* Win); 

#endif
