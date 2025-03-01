#include "include/physics.h"

void CalkDistion(MCPPosition Distance, MCPPosition* Pos, MCPPosition PosComper, int strength) {
	if (PosComper.X - Pos->X > Distance.X && PosComper.X - Pos->X > -Distance.X-1) {
		Pos->X += abs(PosComper.X - Pos->X)/Distance.X;
		Pos->X ++;
	 } else if (PosComper.X - Pos->X < Distance.X && PosComper.X - Pos->X < -Distance.X-1) { 
		Pos->X -= abs(PosComper.X - Pos->X)/Distance.X;
		Pos->X --;
	} if ( PosComper.Y - Pos->Y > Distance.Y && PosComper.Y - Pos->Y > -Distance.Y-1) {
		Pos->Y += abs(PosComper.Y - Pos->Y)/Distance.Y;
		Pos->Y ++;
	} else if (PosComper.Y - Pos->Y < Distance.Y && PosComper.Y - Pos->Y < -Distance.Y-1) {
		Pos->Y -= abs(PosComper.Y - Pos->Y)/Distance.Y;
		Pos->Y --;
	}
}

int WasButtonPress(SDL_Event event) {
	if (event.type ==  SDL_MOUSEBUTTONDOWN) {
		return 1;
	} 

	return 0;

}


void MCP_Physics_Chain(SDL_Renderer* Ren, MCPPosition Pos[], int Points, int DrawPoints, MCPColor ColorBlock, MCPColor ColorLine) {
	SDL_Rect Rect;

	for (int i = 0; i < Points-2; i++) {
		CalkDistion(Pos[Points-1], &Pos[i+1], Pos[i], Pos[Points-1].X);
		Rect.x = Pos[i].X; Rect.y = Pos[i].Y;
		Rect.w = Pos[Points-1].X; 
		Rect.h = Pos[Points-1].Y;

		SDL_SetRenderDrawColor(Ren, ColorLine.R, ColorLine.G, ColorLine.B, ColorLine.A);
		SDL_RenderDrawLine(Ren, Pos[i].X, Pos[i].Y, Pos[i+1].X, Pos[i+1].Y);
		if (DrawPoints) {	
			SDL_SetRenderDrawColor(Ren, ColorBlock.R,ColorBlock.G,ColorBlock.B,ColorBlock.A);
			SDL_RenderFillRect(Ren, &Rect);
		}
	}
} 

void MCP_Physics_Points(SDL_Renderer* Ren, MCPPosition Pos[], int Points, MCPColor color) {
	for (int i = 0; i < Points-2; i++) {
		CalkDistion(Pos[Points-1], &Pos[i+1], Pos[i], Pos[Points-1].X);
		MCP_DrawBlock(Ren, Pos[i], color); 
	}
}

int MCP_Physics_Move(MCPPosition Pos, int windowW, int windowH) {
	if (Pos.X < 0) {
		return 1;
	} if (Pos.X > windowW) {
		return 2;
	} if (Pos.Y < 0) {
		return 3;
	} if (Pos.Y > windowH) {
		return 4;
	}
	return 0;
}

