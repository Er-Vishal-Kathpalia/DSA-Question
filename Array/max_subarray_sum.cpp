#include<bits/stdc++.h>
using namespace std;

int kadane_algo(int arr[], int n){
	int ans = 0;
	int cs = 0;
	for(int i=0;i<n;i++){
		cs = cs + arr[i];
		ans = max(cs,ans);
		if(cs < 0){
			cs = 0;
		}
	}

	return ans;
}

int main(){

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		cout<<kadane_algo(arr, n)<<endl;
	}
	return 0;
}