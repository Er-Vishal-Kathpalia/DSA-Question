#include <bits/stdc++.h>
#include <queue>
using namespace std;

/*
Problem Statement: Find the running median while adding an element.
*/

typedef pair<int,pair<int,int> > node;

vector<int> mergeKSortedArrays(vector<vector<int> > arr){

	vector<int> result;

	//min priority queue
	priority_queue<node, vector<node>, greater<node> > pq;

	//insert the first element
	for(int i=0;i<arr.size();i++){
		pq.push({arr[i][0],{i,0}});
	}

	while(!pq.empty()){
		node current = pq.top();
		pq.pop();
		int element = current.first;
		int x = current.second.first;
		int y = current.second.second;

		result.push_back(element);
		if(y+1<arr[x].size()){
			pq.push({arr[x][y+1],{x,y+1}});
		}
	}

	return result;

}

int main(){

	vector<vector<int> > arr;

	int k,n;
	cin>>k>>n;

	for(int i=0;i<k;i++){
		vector<int> temp;
		for(int j=0;j<n;j++){
			int no;
			cin>>no;
			temp.push_back(no);
		}
		arr.push_back(temp);
	}

	vector<int> ans = mergeKSortedArrays(arr);

	for(auto x:ans){
		cout<<x<<" ";
	}
	cout<<endl;
	return 0;
}