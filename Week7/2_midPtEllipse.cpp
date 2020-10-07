/******************************************
* AUTHOR : AdheshR *
* Problem Description: Given center (a,b) and radius r, display ellipse (in red color) centered at (h,k) and with major axis half length a and minor axis half length b.
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
void midPtEllipseDraw(int h, int k, int a, int b);
void drawPoint(int x,int y);
void drawEllipse(int x, int y);

// global variables
int h,k;							// center
int a,b;							// half length of major axis, half length of minor axis

int main(int argc, char **argv)
{
	// Take Input Values
	printf("Enter the coordinates of the center of the ellipse (h,k).\n");
	scanf("%d %d",&h,&k);
	printf("Enter the half length of the major axis (a).\n");
	scanf("%d",&a);
	printf("Enter the half length of the minor axis (b).\n");
	scanf("%d",&b);

	// Initialise GLUT
	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_SINGLE);
	// set window positiion
	glutInitWindowPosition(100,100);
	// Set the window size					
	glutInitWindowSize(800,600);
	// Create display window 						
	glutCreateWindow("Mid Point Ellipse Draw");							

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
	midPtEllipseDraw(h,k,a,b);
	glFlush();
}

// Rasterization Function - Midpt Line Drawing Algorithm
void midPtEllipseDraw(int h, int k, int a, int b)
{
	//Set color to yellow
	glColor3f(1.0,1.0,0.0); 

	// points to be plotted
	int x,y;
	x = 0; y = b;
	drawEllipse(x,y);

	int sa = pow(a,2);
	int sb = pow(b,2);

	// Define decision variables
	int d1,d2;
	d1 = sb - sa * b + 0.25*sa;

	// Region - 1: II Octant
	while(sa * (y-0.5) > sb * (x+1))
	{	
		// East Condition
		if(d1 < 0)
			d1 = d1 + sb * ((x << 1) + 3);
		else
		{
			// South-East Condition
			d1 = d1 + sb* ((x << 1) + 3) + sa * ((-1) * (y << 1) + 2);
			y = y-1;
		}
		x = x +1;

		drawEllipse(x,y);
	}	

	d2 = sb * pow((x+0.5),2) + sa * pow((y-1),2) - sa*sb;

	// Region - 2: I Octant
	while(y>0)
	{
		if(d2 < 0)
		{
			// South-East Choice
			d2 = d2 + sb*((x << 1) + 2) + sa*((-1)*(y<<1) + 3);
			x = x + 1;
		}
		else
		{
			// Select South
			d2 = d2 + sa * ((-1)*(y<<1) + 3);
		}
		y = y-1;

		drawEllipse(x,y);
	}
}

// Plot Ellipse Function
void drawEllipse(int x, int y)
{
	// Draw for the point in all four quadrants given for the first quadrant
	drawPoint(x,y);					// I Quadrant
	drawPoint(-1*x,y);				// II Quadrant
	drawPoint(-1*x,-1*y);			// III Quadrant
	drawPoint(x,-1*y);				// IV Quadrant
}

// Plot a point on display - Utility Function
void drawPoint(int x,int y)
{
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
}