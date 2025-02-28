#ifndef PHYSICS_H
#define PHYSICS_H

#include "graphic.h"
#include <stdio.h>
#include <stdlib.h>

void CalkDistion(MCPPosition Distance, MCPPosition* Pos, MCPPosition PosComper);

int WasButtonPress(SDL_Event event);

void MCP_Physics_Line(SDL_Renderer* Ren,  MCPPosition Pos[], int Points, MCPColor color);

#endif
