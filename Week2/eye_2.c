#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

int main()
{
	int gd = DETECT, gm; 
    initgraph(&gd, &gm,"");

    setbkcolor(WHITE);

    // Circle at (300,200) of radius = 100 units.
    setcolor(GREEN);
    circle(300,200,100);

    /*
    Inner Equilateral Triangle - Vertices are:
    (300 - 100cos30,200 + 100sin30), (300 + 100cos30,200 + 100sin30), (300,100)
    OR (300 - 100cos30,200 - 100sin30), (300 - 100cos30,200 + 100sin30), (300,300)
    */
    setcolor(BLUE);
    line(213.39,250,386.60,250);
    line(213.39,250,300,100);
    line(386.60,250,300,100);

    setcolor(BLACK);
    circle(213.39,250,2);
    circle(386.60,250,2);
    circle(300,100,2);

    // Inner Cirle - at (300,200) of radius = 50 units.
    setcolor(GREEN);
    circle(300,200,49);

    delay(10000);
    closegraph();	

}