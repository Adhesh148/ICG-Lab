# ICG-Lab
A code repository pertaining to Lab of Interactive Computer Graphics.

The lab begins with simple geometric algorithms and moves to exploring C/C++ libraries related to graphics such as graphics.h (only for a lab) and mostly OpenGL.

## Table of Contents

* [Week-1](Week1/)
> It contains simple algorithmic problems related to lines and primitives.

* [Week-2](Week2/)
> Introduces graphics.h library in C. graphics.h is not supported in gcc, should be downloaded separately (even so setfillstyle() does not work). Contains code for primitive shapes and simple drawings using primitives.

* [Week-3](Week3/)
> Introduces OpenGL library in C. Contains codes to draw a house and a car using combination of primitives. Circle algo should be tuned.

* [Week-4](Week4/)
> Simulation of Printing with and without Error Diffusion. Implemented **Flyod Steinberg Error Diffusion Algorithm**. <br />
> TODO: Understand local average absolute error. (Not sure of the formula)

* [Week-5](Week5/)
> To learn rasterization(scan conversion or sampling) using OpenGL. Implemented **brute force line drawing** and **brute force ellipse drawing** algorithms.

* [Week-6](Week6/)
> To understand the faster rasterization by avoiding floating point operation. Implemented **DDA** and **Midpoint Line Drawing Algorithm**.

* [Week-7](Week7/)
> To understand the faster rasterization  of closed curves such as circle and ellipse, by avoiding floating point operation. Implemented **Mid-pt Circle** and **Mid-point Ellipse** drawing algorithms.

* [Week-8](Week8/)
> To Learn Interactive Computer Graphics. Implemented **Boundary Fill with 4 neighbors**, **Boundary Fill with 8 neighbors** and **Flood Fill Algorithm** with interactive seed point obtained on mouse click. There is a small problem with conversion of mouse coordinates to window coordinates for quadrants other than the first.  <br />
> TODO : Fix the Coordinate Issue (Mouse vs Window). <br />
> Found a leak with 8 neighbors (happened when shape within shape). Also have to handle shape within shape and intersecting shapes a bit more properly - Validate seed has to be refined.

* [Week-9](Week9/)
> TODO: PolyFill.


## Prerequisite
* OpenGL
* grpahics.h (Only for one lab - I would recommend not to install, it's pretty tedious and outdated)
* Python + OpenCv (cv2) (Again used only in Week 4 exercise - was lazy to do it in C/C++)

## Running the codes

To run OpenGL codes <br />
```g++ -o out filename.cpp -lGL -lGLU -lglut -lm```  <br />
OR <br />
```gcc -o out filename.c -lGL -lGLU -lglut -lm```


