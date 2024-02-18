#include<bits/stdc++.h>
using namespace std;

pair<int, int> kadanesAlgo(int arr[], int n, int s = 0, int csum = 0, int msum = 0){
	for(int i=s;i<n;i++){
		csum = csum + arr[i];
		if ( csum < 0){
			csum = 0;
		}
		msum = max(msum, csum);
	}
	return make_pair(csum, msum);
}

int main(){

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		int maxi = 0;

		for(int i=0;i<n;i++){
			int temp;
			cin>>temp;
			if( arr[maxi] <= temp ){
				maxi = i;
			}
			arr[i] = temp;
		}
		int csumTillNow = kadanesAlgo(arr, n, maxi).first;
		int msumTillNow = kadanesAlgo(arr, n, maxi).second;
		cout<<kadanesAlgo(arr, maxi - 1, 0, csumTillNow, msumTillNow).second<<endl;

	}
	return 0;
}