#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include<cstdlib>
#include <iostream>
// Clears the current window and draws a triangle.
using namespace std;
void display() {
	// Set every pixel in the frame buffer to the current clear color.

glClearColor(255, 255, 255, 255);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1, 0, 0);
glOrtho(-3.0, 3.0, -3.0, 3.0, -1.0, 1.0);

// Drawing is done by specifying a sequence of vertices. The way these
	// vertices are connected (or not connected) depends on the argument to
	// glBegin. GL_POLYGON constructs a filled polygon.
GLint circle_points = 100;
double PI = 3.1415926535898;
glBegin(GL_LINE_LOOP);
for (int i = 0; i < circle_points/2; i++) {
	double angle= 2 * PI * i / circle_points;
	glVertex2f(cos(angle), sin(angle));
	
}

	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(-1.5, 0);
	glVertex2f(1.5, 0);
	glVertex2f(1.5, -0.5);
	glVertex2f(-1.5, -0.5);
	
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(1.0, -0.5);
	glVertex2f(-1.0, -0.5);
	glVertex2f(-1.0, -2.5);
	glVertex2f(1.0, -2.5);

	glEnd();
	// Flush drawing command buffer to make drawing happen as soon as possible.
	glFlush();
}
// Initializes GLUT, the display mode, and main window; registers callbacks;
// enters the main event loop.
int main(int argc, char** argv) {
	// Use a single buffered window in RGB mode (as opposed to a double-buffered
	// window or color-index mode).
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// Position window at (80,80)-(480,380) and give it a title.
	glutInitWindowPosition(80, 80);
	glutInitWindowSize(400, 400);
	glutCreateWindow("A Simple Triangle");
	// Tell GLUT that whenever the main window needs to be repainted that it
	// should call the function display().
	glutDisplayFunc(display);
	// Tell GLUT to start reading and processing events. This function
	// never returns; the program only exits when the user closes the main
	// window or kills the process.
	glutMainLoop();
}