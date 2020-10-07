/******************************************
* AUTHOR : AdheshR *
* Problem Description: Implement Boundary Fill algorithm(with 8 neighbours) to display boundary of  one rectangle and one triangle, given vertices, in red colour and then fill the rectangle
 						with blue and triangle with yellow when the mouse click is  done inside the regions. *
*TODO : Transalation of mouse/world coordinates to window coordinates and vice-versa seems a bit problematic for other quadrants. Have to check that. + Check for leaks *
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
// coordinates of the triangle
int tr_x1, tr_y1;
int tr_x2, tr_y2;
int tr_x3, tr_y3;

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
};

// define global bndColor
Color bColor;
Color fColor;

Color getPixelColor(int x, int y);

void drawRectBoundary(int x1,int y1, int x2, int y2);
void drawTriangleBoundary(int x1, int y1, int x2, int y2, int x3, int y3);

void boundaryFill_8N(int x, int y, Color fillColor, Color bColor);
void drawPoint(int x,int y, Color fillColor);

int validateSeed(int x, int y);
float area(int x1, int y1, int x2, int y2, int x3, int y3);

int main(int argc, char **argv)
{
	printf("\n******************** Welcome to Boundary Fill Algorithm Visualizer ***********************\n\n");
	printf("Visualize the Boundary Fill Algorithm for a Rectangle and a Triangle.\n");
	printf("\nPlease Note: All coordinates must be strictly greater than (0,0) - i.e., they must lie in the first quadrant\n");

	// Take Input Values
	printf("\n[DRAW RECTANGLE]\n");
	printf("Enter a coordinates of the rectangle.\n");
	scanf("%d %d",&rect_x1,&rect_y1);
	printf("Enter the diagonally opposite coordinates of the rectangle.\n");
	scanf("%d %d",&rect_x2,&rect_y2);

	// Input coordinates of the triangle
	printf("\n[DRAW TRAINGLE]\n");
	printf("Enter the first coordinates of the triangle.\n");
	scanf("%d %d",&tr_x1,&tr_y1);
	printf("Enter the second coordinates of the triangle.\n");
	scanf("%d %d",&tr_x2,&tr_y2);
	printf("Enter the third coordinates of the triangle.\n");
	scanf("%d %d",&tr_x3,&tr_y3);
	
	// Initialise GLUT
	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// set window positiion
	glutInitWindowPosition(100,100);
	// Set the window size					
	glutInitWindowSize(winWidth,winHeight);
	// Create display window 						
	glutCreateWindow("Boundary Fill");

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
	// define the colors for the boundary - red (in this question)
	bColor.r = 1.0;
	bColor.g = 0.0;
	bColor.b = 0.0;

	// define fill colors
	fColor.r = 1.0;
	fColor.g = 1.0;
	fColor.b = 0.0;
	
	// First lets draw the boundary of the rectangle
	drawRectBoundary(rect_x1,rect_y1,rect_x2,rect_y2);

	// Now lets draw the boundary of the triangle
	drawTriangleBoundary(tr_x1,tr_y1,tr_x2,tr_y2,tr_x3,tr_y3);

	glutSwapBuffers();
}

// Boundary Fill Algorithm with 8 neighbors - check for leaks
void boundaryFill_8N(int x, int y, Color fillColor, Color boundaryColor)
{
	Color currColor = getPixelColor(x,y);
	if(currColor != boundaryColor && currColor != fillColor)
	{
		drawPoint(x,y,fillColor);
		boundaryFill_8N(x+1,y,fillColor,boundaryColor);
		boundaryFill_8N(x,y+1,fillColor,boundaryColor);
		boundaryFill_8N(x-1,y,fillColor,boundaryColor);
		boundaryFill_8N(x,y-1,fillColor,boundaryColor);
		boundaryFill_8N(x+1,y+1,fillColor,boundaryColor);
		boundaryFill_8N(x+1,y-1,fillColor,boundaryColor);
		boundaryFill_8N(x-1,y-1,fillColor,boundaryColor);
		boundaryFill_8N(x-1,y+1,fillColor,boundaryColor);
	}
}

// Rectangle Draw Function
void drawRectBoundary(int x1,int y1, int x2, int y2)
{
	// set the boundary colors
	glColor3f(bColor.r,bColor.g,bColor.b);
	// set fill style - color only boundaries
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	// Draw Rectangle
	glBegin(GL_POLYGON);
		glVertex2i(x1,y1);
		glVertex2i(x2,y1);
		glVertex2i(x2,y2);
		glVertex2i(x1,y2);
	glEnd();

	glutSwapBuffers();
}

// Triangle Draw Function
void drawTriangleBoundary(int x1, int y1, int x2, int y2, int x3, int y3)
{
	// set the boundary colors
	glColor3f(bColor.r,bColor.g,bColor.b);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	// Draw the triangle
	glBegin(GL_POLYGON);
		glVertex2i(x1,y1);
		glVertex2i(x2,y2);
		glVertex2i(x3,y3);
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
					boundaryFill_8N(cx,cy,fColor,bColor);
				else
					printf("[BOUNDARY FILL] selected seed point is not within any shape.\n");
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

// Window reshape - utility function
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
	/* check if seed is within rectangle
	 Fix the bottom-left and top-right points */
	int bl_x,bl_y, rl_x, rl_y;
	bl_x = rect_x1,	bl_y = rect_y1, rl_x = rect_x2,rl_y = rect_y2;
	if(rect_x2 < rect_x1)
	{	
		rl_x = rect_x1; rl_y = rect_y1;
		bl_y = rect_x2; bl_y = rect_y2;
	}

	if (x > bl_x && x < rl_x && y > bl_y && y < rl_y) 
        return 1;
 

	// check if seed is within triangle
	float area_full = area(tr_x1,tr_y1,tr_x2,tr_y2,tr_x3,tr_y3);
	float area_1 = area(x,y,tr_x2,tr_y2,tr_x3,tr_y3);
	float area_2 = area(tr_x1,tr_y1,x,y,tr_x3,tr_y3);
	float area_3 = area(tr_x1,tr_y1,tr_x2,tr_y2,x,y);

	if(area_full == area_1 + area_2 + area_3)
		return 1;

	return 0;
}

// Helper function
float area(int x1, int y1, int x2, int y2, int x3, int y3) 
{ 
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
} 