#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include<X11/Xlib.h>

void drawPoint();
void drawLine();
void drawCircle();
void drawEllipse();
void drawTriangle();
void drawRectangle();

int main()
{
	int gd = DETECT, gm; 
    initgraph(&gd, &gm,"");
    char input;
    while(1)
    {
    	printf("Welcome to Introduction of graphics.h. Choose the graphic primitive to be drawn\na.Point\nb.Line\nc.Circle\nd.Ellipse\ne.Triangle\nf.Rectangle\n");
	    scanf("%c",&input);
	    switch(input)
	    {
	    	case 'a': drawPoint();
	    				break;
	    	case 'b': drawLine();
	    				break;
	    	case 'c': drawCircle();
	    				break;
	    	case 'd': drawEllipse();
	    				break;
	    	case 'e': drawTriangle();
	    				break;
	    	case 'f': drawRectangle();
	    				break;
	    	case 'g': goto End;
	    				break;
	    	default: printf("Enter valid input.\n");
	    				break;
	    }
    }

    End: 
    		delay(10000);
			closegraph();

    return 0;
}

void drawPoint()
{	
	double x,y;
	printf("Enter the (x,y) coordinates of the point.\n");
	scanf("%f %f",&x,&y);
	
	putpixel(x,y,WHITE);
}

void drawLine()
{

}

void drawCircle()
{
	circle(300,300,50);
}

void drawEllipse()
{

}

void drawTriangle()
{

}

void drawRectangle()
{

}