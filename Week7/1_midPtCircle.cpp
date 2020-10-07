/******************************************
* AUTHOR : AdheshR *
* Problem Description: Given center (a,b) and radius r, display circle (in red color) centered at (a,b) and with radius r using midpoint circle drawing algorithm. *
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
void midPtCircleDraw(int a, int b, int r);
void drawPoint(int x,int y);
void drawCircle(int x, int y);

// global variables
int a,b;							// center
int r;								// radius

int main(int argc, char **argv)
{
	// Take Input Values
	printf("Enter the coordinates of the center of the circle (a,b).\n");
	scanf("%d %d",&a,&b);
	printf("Enter the radius (r) of the circle.\n");
	scanf("%d",&r);

	// Initialise GLUT
	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_SINGLE);
	// set window positiion
	glutInitWindowPosition(100,100);
	// Set the window size					
	glutInitWindowSize(800,600);
	// Create display window 						
	glutCreateWindow("Mid Point Circle Draw");							

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
	midPtCircleDraw(a,b,r);
	glFlush();
}

// Rasterization Function - Midpt Line Drawing Algorithm
void midPtCircleDraw(int a, int b, int r)
{
	//Set color to red
	glColor3f(1.0,0.0,0.0); 

	// points to be plotted
	int x,y;
	x = 0; y = r;
	drawCircle(x,y);

	// Define the initial deccision variable
	int d = 1 - r;
	
	// Drawing Loop
	while(y > x)
	{
		if(d < 0)				// East Condition
			d = d + 2*x + 3;
		else
		{
			// South-East condition
			d = d + 2*x - 2*y + 5;
			y = y - 1;
		}
		x = x + 1;
		drawCircle(x,y);
	}
}

// Plot Circle Function
void drawCircle(int x, int y)
{
	// For each point in 2nd octant, plot equivalent in remaining octants
	drawPoint(x,y);
	drawPoint(y,x);
	drawPoint(x,-1*y);
	drawPoint(-1*y,x);
	drawPoint(-1*x,-1*y);
	drawPoint(-1*y,-1*x);
	drawPoint(-1*x,y);
	drawPoint(y,-1*x);
}

// Plot a point on display - Utility Function
void drawPoint(int x,int y)
{
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
}