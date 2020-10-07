/******************************************
* AUTHOR : AdheshR *
* Problem Description: Draw Rectangle in Red colour, and implement the Flood Fill  algorithm to replace the red colour region to green colour when a mouse click is done at a point inside the rectangle *
*TODO : Transalation of mouse/world coordinates to window coordinates and vice-versa seems a bit problematic for other quadrants. Have to check that. *
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
void mouseFcn(GLint button, GLint action, GLint x, GLint y);
void winReshapeFcn (GLint newWidth, GLint newHeight);

// global variables
// coordinates of rectangle
int rect_x1, rect_y1;
int rect_x2, rect_y2;
int rect_x3, rect_y3;
int rect_x4, rect_y4;

// window parameters
GLsizei winWidth = 1000, winHeight = 700;

// define a Color structure
struct Color
{
	GLfloat r;
	GLfloat g;
	GLfloat b;

	// Overload "not equal to" operator
	bool operator!=(const Color& color)
	{
		if(r == color.r && g == color.g && b == color.b)
			return 0;
		return 1;
	}
	// Overload "equal to" operator
	bool operator==(const Color& color)
	{
		if(r == color.r && g == color.g && b == color.b)
			return 1;
		return 0;
	}
};

// define global Colors
Color pColor;
Color nColor;

Color getPixelColor(int x, int y);
void drawRectangle(int x1,int y1, int x2, int y2,int x3, int y3,int x4, int y4);
void drawPoint(int x,int y, Color fillColor);
int validateSeed(int x, int y);
void floodFill(int x, int y, Color prevColor, Color newColor);
float area(int x1, int y1, int x2, int y2, int x3, int y3);

int main(int argc, char **argv)
{
	printf("\n******************** Welcome to Flood Fill Algorithm Visualizer ***********************\n\n");
	printf("Visualize the Flood Fill Algorithm for a Rectangle\n");
	printf("\nPlease Note: All coordinates must be strictly greater than (0,0) - i.e., they must lie in the first quadrant\n");

	// Take Input Values
	printf("\n[DRAW RECTANGLE]\n");
	printf("Enter a coordinates of the rectangle.\n");
	scanf("%d %d",&rect_x1,&rect_y1);
	printf("Enter the second coordinates of the rectangle.\n");
	scanf("%d %d",&rect_x2,&rect_y2);
	printf("Enter the third coordinates of the rectangle.\n");
	scanf("%d %d",&rect_x3,&rect_y3);
	printf("Enter the second coordinates of the rectangle.\n");
	scanf("%d %d",&rect_x4,&rect_y4);
	
	// Initialise GLUT
	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// set window positiion
	glutInitWindowPosition(100,100);
	// Set the window size					
	glutInitWindowSize(winWidth,winHeight);
	// Create display window 						
	glutCreateWindow("Flood Fill");

	// Execute Initialization procedure
	init();
	// call display funtion
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(winReshapeFcn);
	// create Mouse Function
	glutMouseFunc(mouseFcn);

	glutMainLoop();

	return 0;
}

void init()
{
	// set display window white
	glClearColor(1.0,1.0,1.0,0.0);						

	// Set Projection Parameters
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,GLdouble (winWidth),0.0,GLdouble (winHeight));
}

// A void Display Function
void myDisplay()
{
	// define the initial color - red
	pColor.r = 1.0;
	pColor.g = 0.0;
	pColor.b = 0.0;

	// define flood fill color - green
	nColor.r = 0.0;
	nColor.g = 1.0;
	nColor.b = 0.0;
	
	// First lets draw the boundary of the rectangle
	drawRectangle(rect_x1,rect_y1,rect_x2,rect_y2,rect_x3,rect_y3,rect_x4,rect_y4);

	glutSwapBuffers();
}

// Flood Fill Algorithm
void floodFill(int x, int y, Color prevColor, Color newColor)
{
	Color currColor = getPixelColor(x,y);
	if(currColor == pColor)
	{
		drawPoint(x,y,nColor);
		floodFill(x+1,y,pColor,nColor);
		floodFill(x,y+1,pColor,nColor);
		floodFill(x-1,y,pColor,nColor);
		floodFill(x,y-1,pColor,nColor);
		floodFill(x+1,y+1,pColor,nColor);
		floodFill(x+1,y-1,pColor,nColor);
		floodFill(x-1,y-1,pColor,nColor);
		floodFill(x-1,y+1,pColor,nColor);
	}
}

// Rectangle Draw Function
void drawRectangle(int x1,int y1, int x2, int y2,int x3, int y3,int x4, int y4)
{
	// set the boundary colors
	glColor3f(pColor.r,pColor.g,pColor.b);
	// solid fill
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	// Draw Rectangle
	glBegin(GL_POLYGON);
		glVertex2i(x1,y1);
		glVertex2i(x2,y2);
		glVertex2i(x3,y3);
		glVertex2i(x4,y4);
	glEnd();

	glutSwapBuffers();
}

// Plot a point on display - Utility Function
void drawPoint(int x,int y, Color fillColor)
{
	glColor3f(fillColor.r,fillColor.g,fillColor.b);
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();

	glutSwapBuffers();
}

// Mouse Click Function
void mouseFcn(GLint button, GLint action, GLint x, GLint y)
{
	// define and calculate the coordinates from the window-referenced points
	int cx,cy;
	cx = x;
	cy = winHeight - y;

	switch(button)
	{
		case GLUT_LEFT_BUTTON:
			if(action == GLUT_DOWN)
			{
				// give an initial validation to check if the seed point is within the triangle or rectangle
				if(validateSeed(cx,cy) == 1)
					floodFill(cx, cy, pColor, nColor);
				else
					printf("[BOUNDARY FILL] selected seed point is not within the rectangle.\n");
			}
			break;
		default:
			break;
	}
}

// Helper Function to get pixel color
Color getPixelColor(int cx, int cy)
{
	// Find the color associated to the given pixel
	Color color;
	glReadPixels(cx,cy,1,1,GL_RGB, GL_FLOAT, &color);
	return color;
}

// Window reshape - utitlity
void winReshapeFcn (GLint newWidth, GLint newHeight)
{
	/* Reset viewport and projection parameters */
	glViewport (0, 0, newWidth, newHeight);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (0.0, GLdouble (newWidth), 0.0, GLdouble (newHeight));
	/* Reset display-window size parameters. */
	winWidth = newWidth;
	winHeight = newHeight;
}

// Validation function - to check if seed point is within one of the shapes
int validateSeed(int x, int y)
{
	/* Calculate area of rectangle ABCD */
    float A = area(rect_x1, rect_y1, rect_x2, rect_y2, rect_x3, rect_y3) +  
              area(rect_x1, rect_y1, rect_x4, rect_y4, rect_x3, rect_y3); 
  
    /* Calculate area of triangle PAB */
    float A1 = area(x, y, rect_x1, rect_y1, rect_x2, rect_y2); 
  
    /* Calculate area of triangle PBC */
    float A2 = area(x, y, rect_x2, rect_y2, rect_x3, rect_y3); 
  
    /* Calculate area of triangle PCD */
    float A3 = area(x, y, rect_x3, rect_y3, rect_x4, rect_y4); 
  
    /* Calculate area of triangle PAD */
    float A4 = area(x, y, rect_x1, rect_y1, rect_x4, rect_y4); 
  
    /* Check if sum of A1, A2, A3 and A4  
       is same as A */
    return (A == A1 + A2 + A3 + A4); 

	
}

// Helper Function
float area(int x1, int y1, int x2, int y2, int x3, int y3) 
{ 
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
} 