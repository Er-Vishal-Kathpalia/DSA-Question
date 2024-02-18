#include<bits/stdc++.h>
using namespace std;

int rainWaterHarvesting(int arr[], int n){

	int left[n];
	int right[n];

	left[0] = arr[0];
	for(int i=1;i<n;i++){
		left[i] = max(arr[i-1],left[i-1]);
	}
	
	right[n-1] = arr[n-1];
	for(int i=n-2;i>=0;i--){
		right[i] = max(arr[i+1],right[i+1]);
	}
	

	int ans = 0;
	for(int i=0;i<n;i++){
		int temp = min(left[i],right[i]);
		int block = temp-arr[i];
		if(block > 0){
			ans+=block;
		}
	}

	return ans;
}

int main(){

	int n;
	cin>>n;

	int arr[n];

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<rainWaterHarvesting(arr, n)<<endl;
	return 0;
}