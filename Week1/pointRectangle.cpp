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
Equation of Line: ax + by + c = 0

LOGIC-1: Find the sign of the point relative to parallel lines, if they are the same or 2, and if true for both non-parallel set of lines then point lies with rectangle.
**/

enum Position
{
	INSIDE,				// BELOW
	OUTSIDE, 	   		// ABOVE
	ON			  		// ON THE LINE
};

bool isInside(vector<pair<float,float>> corners, pair<int,int> point);
void getLine(vector<vector<float>> &line, vector<pair<float,float>> corners);
Position getPosition(vector<float> line,pair<int,int> point);

int main()
{
	printf("Enter the four coordinates of the corners of the rectangle in the following format: (x1,y1) (x2,y2) (x3,y3) (x4,y4)\n");

	vector<pair<float,float>> corners(4);

	for(int i=0;i<corners.size();++i)
		scanf("\n(%f,%f)",&corners[i].first,&corners[i].second);

	printf("Enter the coordinates of the point.\n"); 
	pair<int,int> point;
	scanf("\n(%d,%d)",&point.first,&point.second);

	cout <<isInside(corners,point)<<endl;

}

bool isInside(vector<pair<float,float>> corners, pair<int,int> point)
{
	// Initialise the line vector which contains all three parameters of the four lines.
	// Here order is [a,b,c]
	vector<vector<float>> line(4,vector<float>(3,0));
	getLine(line,corners);

	Position pos[corners.size()];
	for(int i=0;i<corners.size();++i)
		pos[i] = getPosition(line[i],point);

	if((pos[0] == pos[2] || pos[0] == 2 || pos[2] == 2) && (pos[1] == pos[3] || pos[1] == 2 || pos[3] == 2))
		return true;

	return false;
}

void getLine(vector<vector<float>> &line, vector<pair<float,float>> corners)
{
	float x1,x2,y1,y2;
	for(int i=0;i<line.size();++i)
	{
		x1 = corners[i].first;
		y1 = corners[i].second;
		x2 = corners[(i+1)%4].first;
		y2 = corners[(i+1)%4].second;

		line[i][0] = y2 - y1;
		line[i][1] = x1 - x2;
		line[i][2] = (y1-y2) * x1 + (x2 - x1) * y1;
	}
}

Position getPosition(vector<float> line,pair<int,int> point)
{
	int val = line[0] * point.first + line[1]*point.second + line[2];
	// cout << val<<endl;
	if(val == 0)
		return ON;
	else if(val > 0)
		return OUTSIDE;
	return INSIDE;
}