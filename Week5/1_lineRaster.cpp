/******************************************
* AUTHOR : AdheshR *
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
void rasterLine(float x_1,float y_1, float x_2, float y_2,int step_size);
void drawPoint(int x,int y);

// global variables
float x_1,y_1;
float x_2,y_2;
int step_size;

int main(int argc, char **argv)
{
	// Take Input Values
	printf("Enter the coordinates of the first point (x,y).\n");
	scanf("%f %f",&x_1,&y_1);
	printf("Enter the coordinates of the second point (x,y).\n");
	scanf("%f %f",&x_2,&y_2);

	printf("Enter the step size.\n");
	scanf("%d",&step_size);

	// Initialise GLUT
	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_SINGLE);
	// set window positiion
	glutInitWindowPosition(100,100);
	// Set the window size					
	glutInitWindowSize(800,600);
	// Create display window 						
	glutCreateWindow("Line");							

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
	gluOrtho2D(0.0,600.0,0.0,600.0);
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

	rasterLine(x_1,y_1,x_2,y_2,step_size);
	glFlush();
}

// Rasterization Function
void rasterLine(float x_1,float y_1, float x_2, float y_2,int step_size)
{	
	int x,y;

	// First let us find the slope
	float dy = y_2 - y_1;
	float dx = x_2 - x_1;

	// Case - Vertical Line
	if(dx == 0)
	{
		if(y_1 > y_2)
			swap(y_1,y_2);

		x = round(x_1);
		y = round(y_1);
		while(y <= y_2)
		{
			drawPoint(x,y);
			y = y + step_size;
		}
	}
	else
	{
		float m = dy/dx;					// Find the slope
		float b = y_1 - m * x_1;			// Find the y intercept
		while(x_1 <= x_2)
		{
			x = round(x_1);
			y = round(m*x_1 + b);
			drawPoint(x,y);
			x_1 = x_1 + step_size;
		}	
	}	
}

// Plot a point on display - Utility Function
void drawPoint(int x,int y)
{
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
}