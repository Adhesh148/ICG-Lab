/******************************************
* AUTHOR : AdheshR *
* Problem Description: Implement Midpoint line drawing algorithm and display one line segment in each of the eight octants *
* TODO : For all 8 octants. Done for the first *
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
void midPtLineDraw(int x_1,int y_1, int x_2, int y_2);
void drawPoint(int x,int y);
int adjustCoordinates(int &x_1,int &y_1, int &x_2, int &y_2);

// global variables
int x_1,y_1;
int x_2,y_2;

int main(int argc, char **argv)
{
	// Take Input Values
	printf("Enter the coordinates of the first point (x,y).\n");
	scanf("%d %d",&x_1,&y_1);
	printf("Enter the coordinates of the second point (x,y).\n");
	scanf("%d %d",&x_2,&y_2);

	// Initialise GLUT
	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_SINGLE);
	// set window positiion
	glutInitWindowPosition(100,100);
	// Set the window size					
	glutInitWindowSize(800,600);
	// Create display window 						
	glutCreateWindow("Mid Point Line Draw");							

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
	int temp;
	if(x_1 > x_2)
	{
		// Swap the points - helps maintain uniformity of code (points processed from Left to Right)
		swap(x_1,x_2);
		swap(y_1,y_2);
	}

	// Find the octant - TODO
	// int octant = adjustCoordinates(x_1,y_1,x_2,y_2);

	// Done for 1st octant - Do for remaining octants
	midPtLineDraw(x_1,y_1,x_2,y_2);
	glFlush();
}

// Rasterization Function - Midpt Line Drawing Algorithm
void midPtLineDraw(int x_1,int y_1, int x_2, int y_2)
{
	// Define point to be plotted.
	int x,y;
	x = x_1; y = y_1;
	drawPoint(x,y);

	// Find dy and dx.
	int dy,dx;
	dy = y_2 - y_1;
	dx = x_2 - x_1;

	// Define the decision variables
	int d = 2*dy - dx;
	int d_E = 2*dy;
	int d_NE = 2*(dy-dx);

	// Loop
	while(x < x_2)
	{
		// East Condition
		if(d <= 0)
			d = d + d_E;
		else
		{
			// North-East Condition
			d = d + d_NE;
			y = y + 1;
		}
		x = x + 1;
		drawPoint(x,y);
	}	
}

// Plot a point on display - Utility Function
void drawPoint(int x,int y)
{
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
}

// Utility Function to translate coordinates to first Octant and returns the octant number of the original line
int adjustCoordinates(int &x_1,int &y_1, int &x_2, int &y_2)
{
	float dy = y_2 - y_1;
	float dx = x_2 - x_1;

	printf("%f %f\n",dy,dx);

	// Find theta
	float theta = atan(dy/dx);
	double pi = 2 * acos(0.0);
	theta = theta * 180.0/pi;
	if(theta < 0)
		theta = 180.0 + theta;

	if(y_1 < 0)
		theta = theta + 180;

	printf("%f\n",theta);

	return 0;
}