#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
using namespace std;

int absoluteDiff(int a, int b){
	if(a>=b){
		return a-b;
	}
	return b-a;
}

int main(){

	int n;
	cin>>n;

	vector<int> whiteDots;
	vector<int> blackDots;

	for(int i=0;i<n;i++){
		int no;
		cin>>no;
		whiteDots.push_back(no);
	}

	for(int i=0;i<n;i++){
		int no;
		cin>>no;
		blackDots.push_back(no);	
	}
	
	sort(whiteDots.begin(),whiteDots.end());
	sort(blackDots.begin(),blackDots.end());

	int ans = 0;
	for(int i=0;i<n;i++){
		ans += absoluteDiff(whiteDots[i],blackDots[i]);
	}

	cout<<ans<<endl;
	return 0;
}


/*

6
7 9
0 10
4 5
8 9
4 10
5 7

4 5
5 7
7 9
8 9
0 10
4 10


4 5
5 7

*/
