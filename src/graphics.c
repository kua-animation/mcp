#include "include/graphics.h"

void MCP_Draw_Plane(MCPPosition Pos, MCPRotation Rotation, SDL_Window* Win) {
	glPushMatrix();
	
	glTranslatef(Pos.x, Pos.y, Pos.z);
	glRotatef(Rotation.a, Rotation.x, Rotation.y, Rotation.z);
	
	glBegin(GL_QUADS);
	glColor3f(1.0f-Pos.z/-10, 1.0f-Pos.z/-10, 1.0f-Pos.z/-10);
	glVertex3f(0.5f, 0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f(-0.5f, 0.5f, 0.0f);

	glEnd();
	glPopMatrix();
}

void MCP_Set_Position(MCPPosition *Pos, float x, float y, float z) {
	Pos->x = x;
	Pos->y = y;
	Pos->z = z;
}

void MCP_Set_Rotation(MCPRotation *Rotation, float a, float x, float y, float z) {
	Rotation->a = a;
	Rotation->x = x;
	Rotation->y = y;
	Rotation->z = z;
}

void MCP_Init(int w, int h) {
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0f, (float)w/ (float)h, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

void MCP_Render(MCPPosition Pos[], MCPRotation Rret[], SDL_Window* Win, int count) {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glLoadIdentity();

	for (int i = 0; i < count; i++) {
		MCP_Draw_Plane(Pos[i], Rret[i], Win);
	}

	SDL_GL_SwapWindow(Win);

}
