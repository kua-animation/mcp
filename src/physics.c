#include "include/physics.h"

void CalkDistion(MCPPosition Distance, MCPPosition* Pos, MCPPosition PosComper) {
	if (PosComper.X - Pos->X > Distance.X && PosComper.X - Pos->X > -Distance.X-1) {
		Pos->X += abs(PosComper.X - Pos->X)/20;
	} else if (PosComper.X - Pos->X < Distance.X && PosComper.X - Pos->X < -Distance.X-1) {
		Pos->X -= abs(PosComper.X - Pos->X)/20;
	} if ( PosComper.Y - Pos->Y > Distance.Y && PosComper.Y - Pos->Y > -Distance.Y-1) {
		Pos->Y += abs(PosComper.Y - Pos->Y)/20;
	} else if (PosComper.Y - Pos->Y < Distance.Y && PosComper.Y - Pos->Y < -Distance.Y-1) {
		Pos->Y -= abs(PosComper.Y - Pos->Y)/20;
	} 
}
