/******************************************
* AUTHOR : AdheshR*
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MAX 100000
#define MOD 1000000007
#define dd double

/**
Consider Triangle ABC with point p.

					A
					/\
				   /  \
				  /    \
				 /  p   \
				/        \
			  B	---------- C 

LOGIC-1: Find the area of the three triangles formed by the corners with point P.			
		If Ar(PAB) + Ar(PBC) + Ar(PAC) == Ar(ABC), then point p lies within triangle ABC.	

LOGIC-2: 
**/

bool isInside(vector<pair<float,float>> corners, pair<int,int> point);
float Area(pair<float,float> A,pair<float,float> B,pair<float,float> C);

int main()
{
	printf("Enter the three coordinates of the corners of the triangle in the following format:\n(x1,y1)\n(x2,y2)\n(x3,y3)\n");

	vector<pair<float,float>> corners(3);

	for(int i=0;i<corners.size();++i)
		scanf("\n(%f,%f)",&corners[i].first,&corners[i].second);

	printf("Enter the coordinates of the point.\n"); 
	pair<int,int> point;
	scanf("\n(%d,%d)",&point.first,&point.second);

	cout <<isInside(corners,point)<<endl;
}

bool isInside(vector<pair<float,float>> corners, pair<int,int> point)
{
	// Logic-I
	if((Area(corners[0],corners[1],point) + Area(corners[1],corners[2],point) + Area(corners[2],corners[0],point)) == (Area(corners[0],corners[1],corners[2])))
		return true;
	else
		return false;

	// LOGIC-II
	
}

float Area(pair<float,float> A,pair<float,float> B,pair<float,float> C)
{
	float ar = abs(A.first*(B.second - C.second) + B.first*(C.second - A.second) + C.first*(A.second - B.second));
	ar /= 2.0;
	// cout << ar<<endl;
	return ar;
}