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
GLint circle_points = 420;
double PI = 3.1415926535898;
glBegin(GL_LINE_LOOP);
for (int i = 0; i < circle_points/2; i++) {
	double angle= 2 * PI * i / circle_points;
	glVertex2f(cos(angle), sin(angle));

}

	glEnd();

    // Roof frame
	glBegin(GL_LINE_LOOP);
	glVertex2f(-1.5, 0);
	glVertex2f(1.5, 0);
	glVertex2f(1.5, -0.5);
	glVertex2f(-1.5, -0.5);
	glEnd();

    // House Frame
	glBegin(GL_LINE_LOOP);
	glVertex2f(1.25, -0.5);
	glVertex2f(-1.25, -0.5);
	glVertex2f(-1.25, -2.5);
	glVertex2f(1.25, -2.5);
    glEnd();

    // Door Frame
	glBegin(GL_LINE_LOOP);
	glVertex2f(-.3, -2.5);
	glVertex2f(-.3, -1.25);
	glVertex2f(.3, -1.25);
	glVertex2f(.3, -2.5);
	glEnd();


    //Door Knob
    float x1,y1,x2,y2;
    float angle;
    double radius=.05;

    x1 = 0.2,y1=-1.9;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1,y1);

    for (angle=1.0f;angle<361.0f;angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex2f(x2,y2);
    }
    glEnd();


    // Window left frame
    glBegin(GL_LINE_LOOP);
	glVertex2f(-1.12, -1.25);
	glVertex2f(-.5, -1.25);
	glVertex2f(-.5, -1.75);
	glVertex2f(-1.12, -1.75);
	glEnd();

    // Window left inner frame (Vertical)
    glBegin(GL_LINE_LOOP);
	glVertex2f(-.8, -1.25);
	glVertex2f(-.8, -1.75);
	glEnd();

    // Window left inner frame (Horizontal)
    glBegin(GL_LINE_LOOP);
	glVertex2f(-1.12, -1.5);
	glVertex2f(-.5, -1.5);
	glEnd();

    // Window Right frame
    glBegin(GL_LINE_LOOP);
	glVertex2f(1.12, -1.25);
	glVertex2f(.5, -1.25);
	glVertex2f(.5, -1.75);
	glVertex2f(1.12, -1.75);
	glEnd();

    // Window right inner frame (Vertical)
    glBegin(GL_LINE_LOOP);
	glVertex2f(.8, -1.25);
	glVertex2f(.8, -1.75);
	glEnd();

    // Window right inner frame (Horizontal)
    glBegin(GL_LINE_LOOP);
	glVertex2f(1.12, -1.5);
	glVertex2f(.5, -1.5);
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