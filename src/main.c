#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <stdlib.h>

void init(int w, int h) {
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (float)w/ (float)h, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

void render(SDL_Window* window) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.6f, 0.3f);
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(0.5f, 0.5f, -3.0f);
	glVertex3f(-0.5f, 0.5f, -3.0f);
	glEnd();

	SDL_GL_SwapWindow(window);

}

int main(int argc, char* argv[]) {
	SDL_Window* window = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);

	SDL_GLContext context = SDL_GL_CreateContext(window);

	glewInit();
	
	init(800, 600);

	int running = 1;
	SDL_Event event;

	while (running) {
		while (SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT) {
				running = 0;
			}
		}

		render(window);
		SDL_Delay(10);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

