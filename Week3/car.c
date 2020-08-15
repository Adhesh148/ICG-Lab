#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

void init();
void drawCar();

int main(int argc, char **argv)
{
	// Initialise GLUT
	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowPosition(100,100);					// set window positiion
	glutInitWindowSize(800,600); 						// Set the window size
	glutCreateWindow("Car");							// Create display window

	init();												// Execute Initialization procedure
	glutDisplayFunc(drawCar);	   						// call display funtion
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

void drawCar()
{
	glClear(GL_COLOR_BUFFER_BIT);						// Clear the display window

	// define the points for the rectangular base
	float point1R[] = {200,100};
	float point2R[] = {450,100};
	float point3R[] = {450,180};
	float point4R[] = {200,180};

	glColor3f(0.0,0.0,0.0);								// set pixel color - black
	glLineWidth(2.2);

	glBegin(GL_LINE_LOOP);
		glVertex2fv(point1R);
		glVertex2fv(point2R);
		glVertex2fv(point3R);
		glVertex2fv(point4R);
	glEnd( );

	// draw polygon of body - top
	float point1B[] = {260,180};
	float point2B[] = {316,260};
	float point3B[] = {420.88,260};
	float point4B[] = {450,180};

	glBegin(GL_LINE_LOOP);
		glVertex2fv(point1B);
		glVertex2fv(point2B);
		glVertex2fv(point3B);
		glVertex2fv(point4B);
	glEnd( );

	// draw windows - left and right
	// Reference coordinates for the windows;
	float point1[] = {268,184};
	float point2[] = {316,255.5714};
	float point3[] = {418,255.5714};
	float point4[] = {445,184};

	float point1LW[] = {268,184};
	float point2LW[] = {316,255.5714};
	float point3LW[] = {352,255.5714};
	float point4LW[] = {352,184};

	float point1RW[] = {358,184};
	float point2RW[] = {358,255.5714};
	float point3RW[] = {418,255.5714};
	float point4RW[] = {445,184};

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

	// Draw the tires
	float theta;
	float pointT1[] = {264,100};
	float radius = 34;

	glColor3f(0.7686,0.7686,0.7686);
	glBegin(GL_POLYGON);
	for(int i=0;i<360;++i)
	{
		theta = (i*3.1415926)/180;
		glVertex2f(pointT1[0] + radius*cos(theta),pointT1[1]+ radius*sin(theta));
	}
	glEnd( );

	float pointT2[] = {pointT1[0] + 135,pointT1[1]};

	glBegin(GL_POLYGON);
	for(int i=0;i<360;++i)
	{
		theta = (i*3.1415926)/180;
		glVertex2f(pointT2[0] + radius*cos(theta),pointT2[1]+ radius*sin(theta));
	}
	glEnd( );

	// Draw borders for the tires.

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<360;++i)
	{
		theta = (i*3.1415926)/180;
		glVertex2f(pointT1[0] + radius*cos(theta),pointT1[1]+ radius*sin(theta));
	}
	glEnd( );

	glBegin(GL_LINE_LOOP);
	for(int i=0;i<360;++i)
	{
		theta = (i*3.1415926)/180;
		glVertex2f(pointT2[0] + radius*cos(theta),pointT2[1]+ radius*sin(theta));
	}
	glEnd( );

	glFlush( );
}