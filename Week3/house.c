#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

void init();
void drawHouse();

int main(int argc, char **argv)
{
	// Initialise GLUT
	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowPosition(100,100);					// set window positiion
	glutInitWindowSize(800,600); 						// Set the window size
	glutCreateWindow("House");							// Create display window

	init();												// Execute Initialization procedure
	glutDisplayFunc(drawHouse);	   						// call display funtion
	glutMainLoop();

	return 0;
}

void init()
{
	glClearColor(1.0,1.0,1.0,0.0);						// set display window white

	// Set Projection Parameters
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,600.0,0.0,600.0);
}

void drawHouse()
{
	glClear(GL_COLOR_BUFFER_BIT);						// Clear the display window

	// define the coordinates of the rectangular base
	float point1[] = {200,100};
	float point2[] = {400,100};
	float point3[] = {400,350};
	float point4[] = {200,350};

	glColor3f(0.235,0.737,0.956);						// set pixel color 
	glBegin(GL_QUADS);
		glVertex2fv(point1);
		glVertex2fv(point2);
		glVertex2fv(point3);
		glVertex2fv(point4);
	glEnd( );

	// define the coordinates of the roof
	float point1R[] ={200,353};
	float point2R[] = {400,353};
	float point3R[] = {300,526.205};					// height of equilateral triangle  = 352 + 200 *sqrt(3)/2

	glColor3f(0.956,0.329,0.36);
	glBegin(GL_TRIANGLES);
		glVertex2fv(point1R);
		glVertex2fv(point2R);
		glVertex2fv(point3R);
	glEnd( );

	// define coordinates for the door
	float point1D[] = {280,102};
	float point2D[] = {320,102};
	float point3D[] = {320,225};
	float point4D[] = {280,225};

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_QUADS);
		glVertex2fv(point1D);
		glVertex2fv(point2D);
		glVertex2fv(point3D);
		glVertex2fv(point4D);
	glEnd( );

	// define coordinates of the windows
	float point1LW[] = {225,225};
	float point2LW[] = {250,225};
	float point3LW[] = {250,190};
	float point4LW[] = {225,190};

	float point1RW[] = {345,225};
	float point2RW[] = {370,225};
	float point3RW[] = {370,190};
	float point4RW[] = {345,190};

	glBegin(GL_QUADS);
		glVertex2fv(point1LW);
		glVertex2fv(point2LW);
		glVertex2fv(point3LW);
		glVertex2fv(point4LW);
		glVertex2fv(point1RW);
		glVertex2fv(point2RW);
		glVertex2fv(point3RW);
		glVertex2fv(point4RW);
	glEnd( );

	// draw border lines
	glLineWidth(2.3);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
		glVertex2fv(point1);
		glVertex2fv(point2);
		glVertex2fv(point3);
		glVertex2fv(point4);
	glEnd( );

	glBegin(GL_LINE_LOOP);
		glVertex2fv(point1LW);
		glVertex2fv(point2LW);
		glVertex2fv(point3LW);
		glVertex2fv(point4LW);
	glEnd( );

	glBegin(GL_LINE_LOOP);
		glVertex2fv(point1RW);
		glVertex2fv(point2RW);
		glVertex2fv(point3RW);
		glVertex2fv(point4RW);
	glEnd( );

	glBegin(GL_LINE_LOOP);
		glVertex2fv(point1D);
		glVertex2fv(point2D);
		glVertex2fv(point3D);
		glVertex2fv(point4D);
	glEnd( );

	glBegin(GL_LINE_LOOP);
		glVertex2fv(point1R);
		glVertex2fv(point2R);
		glVertex2fv(point3R);
	glEnd( );

	glFlush( );
}