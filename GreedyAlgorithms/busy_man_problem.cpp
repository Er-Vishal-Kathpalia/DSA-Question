#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> p1, pair<int, int> p2){
	return p1.second < p2.second;
}

int main(){

	int t,n,s,e;
	cin>>t;

	vector<pair<int, int> > v;

	while(t--){
		cin>>n;

		for(int i=0;i<n;i++){
			cin>>s>>e;
			v.push_back(make_pair(s,e));
		}

		//sort the end time of the jobs
		sort(v.begin(),v.end(),compare);

		//pick the job first and start picking the next jobs in loop.
		int res = 1;
		int end = v[0].second;
		for(int i=1;i<v.size();i++){
			if( v[i].first >= end ){
				end = v[i].second;
				res++;
			}
		}
		cout<<res<<endl;
		v.clear();
	}
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
