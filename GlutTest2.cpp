#ifdef WIN32
#include <windows.h>
#endif
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include<cstdlib>
#include <iostream>
// Clears the current window and draws a triangle.
using namespace std;

void init()
{
	glClearColor(255, 255, 255, 255);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluPerspective(45,640.0/480.0,1.0,500.0);
	glMatrixMode(GL_MODELVIEW);
	//glEnable(GL_DEPTH_TEST);



}


// A fish bitmap, size is 27x11, but all rows must have a multiple of 8 bits,
// so we define it like it is 32x11.
GLubyte fish[] = {
  0x00, 0x60, 0x01, 0x00,
  0x00, 0x90, 0x01, 0x00,
  0x03, 0xf8, 0x02, 0x80,
  0x1c, 0x37, 0xe4, 0x40,
  0x20, 0x40, 0x90, 0x40,
  0xc0, 0x40, 0x78, 0x80,
  0x41, 0x37, 0x84, 0x80,
  0x1c, 0x1a, 0x04, 0x80,
  0x03, 0xe2, 0x02, 0x40,
  0x00, 0x11, 0x01, 0x40,
  0x00, 0x0f, 0x00, 0xe0,
};


// Return a random float in the range 0.0 to 1.0.
GLfloat randomFloat() {
	return (GLfloat)rand() / RAND_MAX;
}

// On reshape, uses an orthographic projection with world coordinates ranging
// from 0 to 1 in the x and y directions, and -1 to 1 in z.
void reshape(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(1, 1, 1, 1);
}

void display() {
	// Set every pixel in the frame buffer to the current clear color.
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(10, 0, 0);
	glOrtho(-3.0, 3.0, -3.0, 3.0, -1.0, 1.0);


	// glColor3f(1, 0, 0);




	// Plots 20 fish bitmaps in random colors at random positions
	for (int i = 0; i < 20; i++) {
		glColor3f(randomFloat(), randomFloat(), randomFloat());
		// glRasterPos3f(randomFloat(), randomFloat(), 0.0);
		glRasterPos3f(randomFloat(), randomFloat() - 3.9, 0.0);
		glBitmap(27, 11, 0, 0, 0, 0, fish);
	}


	// Drawing is done by specifying a sequence of vertices. The way these
	// vertices are connected (or not connected) depends on the argument to
	// glBegin. GL_POLYGON constructs a filled polygon.
	GLint circle_points = 420;
	double PI = 3.1415926535898;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < circle_points / 2; i++) {
		double angle = 2 * PI * i / circle_points;
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

	// //River
	// glBegin(GL_QUADS);
	// glColor4f(0.0, 0.0, 1.0, 1.0);
	// glVertex2f(4.0, -4.0);
	// glVertex2f(-4, -4.0);
	// glVertex2f(-4, -3.0);
	// glVertex2f(4, -3.0);
	// glEnd();


	// //River 2
	// glBegin(GL_QUADS);
	// glColor4f(1.0, 0.0, 0.0, 0.5);
	// glVertex2f(2.0, -4.0);
	// glVertex2f(-3.5, -4.0);
	// glVertex2f(-3, -3.0);
	// glVertex2f(2, -3.0);
	// glEnd();

	glBegin(GL_QUADS);
	// draw transparent objects from far to near!
	// first draw transparent objects then nontransparent objects


	glColor4f(0, 0, 1, .3);
	glVertex3f(4.5, -4, 1);
	glVertex3f(-4.5, -4, 1);
	glVertex3f(-4.5, -2.6, 1);
	glVertex3f(4.5, -2.6, 1);
	glEnd();

	// 		glBegin(GL_POLYGON);
	//     glColor3f(1, 0, 0);
	// 	glVertex3f(-0.6, -0.75, 0.5);
	//     glColor3f(0, 1, 0);
	// 	glVertex3f(0.6, -0.75, 0);
	//     glColor3f(0, 0, 1);
	// 	glVertex3f(0, 0.75, 0);
	//   glEnd();

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
	float x1, y1, x2, y2;
	float angle;
	double radius = .05;

	x1 = 0.2, y1 = -1.9;

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1, y1);

	for (angle = 1.0f; angle < 361.0f; angle += 0.2)
	{
		x2 = x1 + sin(angle) * radius;
		y2 = y1 + cos(angle) * radius;
		glVertex2f(x2, y2);
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


	//MOON
	//Circle 1 -> Black
	//glTranslatef is used to position the circle
	glTranslatef(2.0, 2.0, 0);
	//glScalef - size of the circle
	glScalef(0.3, 0.3, 0);


	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(249, 215, 28);
	for (int i = 0; i <= 500; i++) {
		double angle = 2 * PI * i / 500;
		double x = cos(angle);
		double y = sin(angle);
		glVertex2d(x, y);
	}
	glEnd();

	//Circle 2 -> white
	glTranslatef(0.5, 0.5, 0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);

	for (int i = 0; i <= 500; i++) {
		double angle = 2 * PI * i / 500;
		double x = cos(angle);
		double y = sin(angle);
		glVertex2d(x, y);
	}

	glEnd();




	// Flush drawing command buffer to make drawing happen as soon as possible.
	glutSwapBuffers();
}


// Initializes GLUT, the display mode, and main window; registers callbacks;
// enters the main event loop.
int main(int argc, char** argv) {





	// Use a single buffered window in RGB mode (as opposed to a double-buffered
	// window or color-index mode).
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	// Position window at (80,80)-(480,380) and give it a title.
	glutInitWindowPosition(100, 80);

	glutCreateWindow("A HOUSE ");

	glutInitWindowSize(1000, 1000);

	// Tell GLUT that whenever the main window needs to be repainted that it
	// should call the function display().






	glutDisplayFunc(display);
	// Tell GLUT to start reading and processing events. This function
	// never returns; the program only exits when the user closes the main
	// window or kills the process.

	init();


	glutReshapeFunc(reshape);



	glutMainLoop();
}
