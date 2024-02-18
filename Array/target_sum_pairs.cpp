#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}


	int target;
	cin>>target;

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]+arr[j] == target){
				int minAns = min(arr[i],arr[j]);
				int maxAns = max(arr[i],arr[j]);
				cout<<minAns<<" and "<<maxAns<<endl;
			}
		}
	}

	return 0;
}