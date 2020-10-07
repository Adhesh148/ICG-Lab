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
void drawEllipse(float a, float b, int step_size);
void drawPoint(int x,int y);

// global variables
float a,b;
int step_size;

int main(int argc, char **argv)
{
	// Take Input Values
	printf("Enter the parameters of the ellipse (a,b).\n");
	scanf("%f %f",&a,&b);

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
	glutCreateWindow("Ellipse");							

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
	drawEllipse(a,b,step_size);
	glFlush();
}

// Rasterization Function
void drawEllipse(float a, float b, int step_size)
{
	int x,y;
	double pi = 2 * acos(0.0);			// get good approx value of pi
	float theta;
	drawPoint(0,0);						// plot origin
	for(int i=0;i<=360;i=i+step_size)
	{
		theta = i * pi/180;
		x = round(a * cos(theta));
		y = round(b * sin(theta));
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