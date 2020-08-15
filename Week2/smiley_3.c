#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <X11/Xlib.h>

int main()
{
	XInitThreads();
	int gd = DETECT, gm; 
    initgraph(&gd, &gm,"");
    
    // Circle at (300,200) of radius = 100 units.
    setcolor(YELLOW);
    // setfillstyle(0,RED);  - does not seem to be working in gcc;
    circle(300,200,100);
    
    circle(260,170,20);
    circle(340,170,20);

    rectangle(240,225,360,240);

    delay(5000);
    closegraph();   

}