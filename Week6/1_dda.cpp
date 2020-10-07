/******************************************
* AUTHOR : AdheshR *
* Problem Description: Implement DDA algorithm for drawing straight line and observe how the lines are drawn when the slope is close to 0, and also when close to infinity *
******************************************/
#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>
#define LL long long
#define MAX 100
#define MOD 1000000007
#define dd double

void init();
void myDisplay();
void lineDDA(float x_1,float y_1, float x_2, float y_2);
void drawPoint(int x,int y);

// global variables
float x_1,y_1;
float x_2,y_2;

int main(int argc, char **argv)
{
	// Take Input Values
	printf("Enter the coordinates of the first point (x,y).\n");
	scanf("%f %f",&x_1,&y_1);
	printf("Enter the coordinates of the second point (x,y).\n");
	scanf("%f %f",&x_2,&y_2);

	// Initialise GLUT
	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_SINGLE);
	// set window positiion
	glutInitWindowPosition(100,100);
	// Set the window size					
	glutInitWindowSize(800,600);
	// Create display window 						
	glutCreateWindow("Line DDA");							

	// Execute Initialization procedure
	init();
	// call display funtion
	glutDisplayFunc(myDisplay);	   		
	glutMainLoop();

	return 0;
}

void init()
{
	// set display window white
	glClearColor(1.0,1.0,1.0,0.0);						

	// Set Projection Parameters
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-600.0,600.0,-600.0,600.0);
}

// A void Display Function
void myDisplay()
{
	// Validation to check if x_1 <= x_2.
	float temp;
	if(x_1 > x_2)
	{
		// Swap the points - helps maintain uniformity of code (points processed from Left to Right)
		swap(x_1,x_2);
		swap(y_1,y_2);
	}

	lineDDA(x_1,y_1,x_2,y_2);
	glFlush();
}

// Rasterization Function - Standard Implementation of DDA Algorithm
void lineDDA(float x_1,float y_1, float x_2, float y_2)
{
	int dy,dx,steps;
	dy = y_2 - y_1;
	dx = x_2 - x_1;

	if(fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);

	float x_incr,y_incr;
	x_incr = float(dx) / float(steps);
	y_incr = float(dy) / float(steps);

	float x,y;
	x = x_1; y = y_1;

	drawPoint(round(x),round(y));
	for(int i=0;i<steps;++i)
	{
		x += x_incr;
		y += y_incr;
		drawPoint(round(x),round(y));
	}
}

// Plot a point on display - Utility Function
void drawPoint(int x,int y)
{
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
}