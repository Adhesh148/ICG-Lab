/******************************************
* AUTHOR : AdheshR*
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MAX 100000
#define MOD 1000000007
#define dd double

enum Position
{
	INSIDE,				// BELOW - 0
	OUTSIDE, 	   		// ABOVE - 1
	ON			  		// ON THE LINE - 2
};

void getLine(vector<vector<float>> &line, vector<pair<float,float>> corners);
Position getPosition(vector<float> line,pair<int,int> point);

int main()
{
	printf("Enter the two coordinates of the corners of the line in the following format:\n(x1,y1)\n(x2,y2)\n");

	vector<pair<float,float>> corners(2);

	for(int i=0;i<corners.size();++i)
		scanf("\n(%f,%f)",&corners[i].first,&corners[i].second);

	printf("Enter the coordinates of the point.\n"); 
	pair<int,int> point;
	scanf("\n(%d,%d)",&point.first,&point.second);

	vector<vector<float>> line(1,vector<float>(3,0));
	getLine(line,corners);
	// cout << line[0][0]<<" "<<line[0][1]<<" "<<line[0][2]<<endl;
	cout <<getPosition(line[0],point)<<endl;
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
	float val = line[0] * point.first + line[1]*point.second + line[2];
	// cout << val<<endl;
	if(val == 0.0)
		return ON;
	else if(val > 0.0)
		return OUTSIDE;
	else
		return INSIDE;
}