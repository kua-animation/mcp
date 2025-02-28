#include "include/physics.h"

void CalkDistion(MCPPosition Distance, MCPPosition* Pos, MCPPosition PosComper) {
	if (PosComper.X - Pos->X > Distance.X && PosComper.X - Pos->X > -Distance.X-1) {
		Pos->X += abs(PosComper.X - Pos->X)/10;
		Pos->X ++;
	} else if (PosComper.X - Pos->X < Distance.X && PosComper.X - Pos->X < -Distance.X-1) {
		Pos->X -= abs(PosComper.X - Pos->X)/10;
		Pos->X --;
	} if ( PosComper.Y - Pos->Y > Distance.Y && PosComper.Y - Pos->Y > -Distance.Y-1) {
		Pos->Y += abs(PosComper.Y - Pos->Y)/10;
		Pos->Y ++;
	} else if (PosComper.Y - Pos->Y < Distance.Y && PosComper.Y - Pos->Y < -Distance.Y-1) {
		Pos->Y -= abs(PosComper.Y - Pos->Y)/10;
		Pos->Y --;
	}
}

int WasButtonPress(SDL_Event event) {
	if (event.type ==  SDL_MOUSEBUTTONDOWN) {
		return 1;
	} 

	return 0;

}

void MCP_Physics_Line(SDL_Renderer* Ren, MCPPosition Pos[], int Points, MCPColor color) {
	for (int i = 0; i < Points-2; i++) {
		CalkDistion(Pos[Points-1], &Pos[i+1], Pos[i]);
	}

	for (int i = 0; i < Points-2; i++) {
		SDL_SetRenderDrawColor(Ren, 255,255,255,255);
		SDL_RenderDrawLine(Ren, Pos[i].X, Pos[i].Y, Pos[i+1].X, Pos[i+1].Y);
	}


}
