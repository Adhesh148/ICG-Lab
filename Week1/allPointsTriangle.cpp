/******************************************
* AUTHOR : AdheshR*
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MAX 100000
#define MOD 1000000007
#define dd double

void getBoundingCoordinates(vector<pair<float,float>> &boundingBox,vector<pair<float,float>> corners);
bool isInside(vector<pair<float,float>> corners, pair<int,int> point);
float Area(pair<float,float> A,pair<float,float> B,pair<float,float> C);
void getAllPoints(vector<pair<float,float>> boundingBox,vector<pair<float,float>> corners);

int main()
{
	printf("Enter the three coordinates of the corners of the triangle in the following format:\n(x1,y1)\n(x2,y2)\n(x3,y3)\n");

	vector<pair<float,float>> corners(3);

	for(int i=0;i<corners.size();++i)
		scanf("\n(%f,%f)",&corners[i].first,&corners[i].second);

	vector<pair<float,float>> boundingBox(4);
	getBoundingCoordinates(boundingBox,corners);

	getAllPoints(boundingBox,corners);

}

void getBoundingCoordinates(vector<pair<float,float>> &boundingBox,vector<pair<float,float>> corners)
{
	float right=corners[0].first,left = corners[0].first;
	float top = corners[0].second,bottom = corners[0].second;

	for(int i = 1;i<3;++i)
	{
		if(corners[i].first > right)
			right = corners[i].first;
		if(corners[i].first < left)
			left = corners[i].first;
		if(corners[i].second > top)
			top = corners[i].second;
		if(corners[i].second < bottom)
			bottom = corners[i].second;
	}

	boundingBox[0] = make_pair(left,bottom);
	boundingBox[1] = make_pair(right,bottom);
	boundingBox[2] = make_pair(right,top);
	boundingBox[3] = make_pair(left,top);
}

void getAllPoints(vector<pair<float,float>> boundingBox,vector<pair<float,float>> corners)
{
	float left = boundingBox[0].first;
	float right = boundingBox[1].first;
	float bottom = boundingBox[0].second;
	float top = boundingBox[2].second;

	cout << "List of all points that lie within the triangle are:\n";
	for(int i=left;i<=right;++i)
		for(int j=bottom;j<=top;++j)
			if(isInside(corners,make_pair(i,j)))
				cout << "("<<i<<","<<j<<")"<<endl;
}

bool isInside(vector<pair<float,float>> corners, pair<int,int> point)
{
	if((Area(corners[0],corners[1],point) + Area(corners[1],corners[2],point) + Area(corners[2],corners[0],point)) == (Area(corners[0],corners[1],corners[2])))
		return true;
	else
		return false;	
}

float Area(pair<float,float> A,pair<float,float> B,pair<float,float> C)
{
	float ar = abs(A.first*(B.second - C.second) + B.first*(C.second - A.second) + C.first*(A.second - B.second));
	ar /= 2.0;
	// cout << ar<<endl;
	return ar;
}