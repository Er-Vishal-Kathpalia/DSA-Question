#include <bits/stdc++.h>
#include <cstring>
using namespace std;

/*
Problem -  Right Angle Traingles
Given N points in a 2D Cartesian Plane, How many right angled triangles are there 
such at perpendicular or base is parallel to X or Y axis?
*/

int right_angle_triangles(vector<pair<int,int> > axis, int n){

	unordered_map<int,int> xm; // xaxis,count
	unordered_map<int,int> ym; // yaxis,count

	for(int i=0;i<n;i++){
		int x = axis[i].first;
		int y = axis[i].second;
		xm[x]++;
		ym[y]++;
	}

	int ans = 0;
	for(int i=0;i<n;i++){
		int x = axis[i].first;
		int y = axis[i].second;
		if(xm[x] >= 1 && ym[y] >= 1){
			ans += (xm[x]-1)*(ym[y]-1);
		}
	}
	return ans;

}

int main(){

	vector<pair<int,int> > axis;
	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		axis.push_back(make_pair(x,y));
	}

	cout<<right_angle_triangles(axis,n)<<endl;

	return 0;
}