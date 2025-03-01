#ifndef PHYSICS_H
#define PHYSICS_H

#include "graphic.h"
#include <stdio.h>
#include <stdlib.h>

void CalkDistion(MCPPosition Distance, MCPPosition* Pos, MCPPosition PosComper, int strength);

int WasButtonPress(SDL_Event event);

void MCP_Physics_Points(SDL_Renderer* Ren, MCPPosition Pos[], int Points, MCPColor color );

void MCP_Physics_Chain(SDL_Renderer* Ren, MCPPosition Pos[], int Points, int DrawPoint, MCPColor ColorBlock, MCPColor ColorLine); 

int MCP_Physics_Move(MCPPosition Pos, int windowW, int windowH); 

#endif
