#include "include/graphics.h"

void MCP_Draw_Plane(MCPPosition Pos, MCPRotation Rotation, SDL_Window* Win) {
	float Max = 0.87f;
	int OfSet = 45;
	float Color = 1.0f-(Pos.z/-OfSet);
	glPushMatrix();
	
	glTranslatef(Pos.x, Pos.y, Pos.z);
	glRotatef(Rotation.a, Rotation.x, Rotation.y, Rotation.z);
	
	glBegin(GL_QUADS);
	if (1.0f-((Pos.z)/-OfSet)-0.1f > 0.2f) {
		glColor3f(Color-0.1f, Color, Color);
	} else {
		glColor3f(0.2f, 0.3f, 0.3f);
	}
	glVertex3f(0.5f, 0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f(-0.5f, 0.5f, 0.0f);

	glEnd();
	glPopMatrix();
}

 void MCP_Draw_Cube(MCPPosition *Ofset, MCPPosition *Pos, MCPRotation *Rota, MCPPosition Position, MCPPlayer Player, int start) {
	if (Position.z >= 0) {
		MCP_Set_Position(&Ofset[start], Position.x - 0.5f, Position.y, Position.z+0.5f);
		MCP_Set_Position(&Ofset[start+1], Position.x + 0.5f, Position.y, Position.z+0.5f);
		MCP_Set_Position(&Ofset[start+2], Position.x, Position.y, Position.z);
	} else {
		MCP_Set_Position(&Ofset[start], Position.x + 0.5f, Position.y, Position.z-0.5f);
		MCP_Set_Position(&Ofset[start+1], Position.x - 0.5f, Position.y, Position.z-0.5f);
		MCP_Set_Position(&Ofset[start+2], Position.x, Position.y, Position.z);
	}

	for (int i = 0; i < 3; i ++) { 
		MCP_Set_Position_By_Player(&Pos[i+start], Ofset[i+start], Player);
	}

	MCP_Set_Rotation(&Rota[start], 90.0f, 0.0f, 1.0f, 0.0f);
	MCP_Set_Rotation(&Rota[start+1], 90.0f, 0.0f, 1.0f, 0.0f);

}

void MCP_Set_Position(MCPPosition *Pos, float x, float y, float z) {
	Pos->x = x;
	Pos->y = y;
	Pos->z = z;
}

void MCP_Set_Position_By_Ofset(MCPPosition *Pos, MCPPosition Ofset) {
	Pos->x = Ofset.x;
	Pos->y = Ofset.y;
	Pos->z = Ofset.z;
}

void MCP_Set_Position_By_Player(MCPPosition *Pos, MCPPosition Ofset, MCPPlayer Player) {
	Pos->x = Player.x + Ofset.x;
	Pos->y = Player.y + Ofset.y;
	Pos->z = Player.z + Ofset.z;
}

void MCP_Set_Rotation(MCPRotation *Rotation, float a, float x, float y, float z) {
	Rotation->a = a;
	Rotation->x = x;
	Rotation->y = y;
	Rotation->z = z;
}

