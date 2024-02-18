#include<bits/stdc++.h>
using namespace std;


long long int max_biotonic_subarray(long long int n, vector<long long int> arr){

	vector<long long int> inc;
	inc.reserve(n);
	vector<long long int> dec;
	dec.reserve(n);

	inc[0] = 1;
	dec[n-1] = 1;
	for(int i=1;i<n;i++){
		if(arr[i] >= arr[i-1]){
			inc[i] = inc[i-1] + 1;
		} else{
			inc[i] = 1;
		}
	}

	for(int i=n-2;i>=0;i--){
		if(arr[i] >= arr[i+1]){
			dec[i] = dec[i+1] + 1;
		} else{
			dec[i] = 1;
		}
	}
	int ans = inc[0] + dec[0] - 1;
	for(int i=1;i<n;i++){
		int max = inc[i]+dec[i]-1;
		if( ans < max ){
			ans = max;
		}
	}
	return ans;
}


int main(){

	long long int t; 
	cin>>t;
	
	while(t--){
		long long int n;
		cin>>n;

		vector<long long int> arr;
		for(long long int i=0;i<n;i++){
			int temp;
			cin>>temp;
			arr.push_back(temp);
		}
		cout<<max_biotonic_subarray(n, arr)<<endl;
	}
	return 0;
}



/*

2
6
12 4 78 90 45 23
4
40 30 20 10

Increasing and then decreasing
6 
arr = 12 4 78 90 45 23
inc = 1  1 2  3  1  1
dec = 2  1 1  3  2  1

[inc + dec - 1] = max length
ans = 2  1 2  5  2  1

ans = 5


Strickly Increasing
arr =  1 2 3 4
inc =  1 2 3 4
dec =  1 1 1 1

ans =  1 2 3 4

Strickly decreasing
arr =  4 3 2 1
inc =  1 1 1 1
dec =  4 3 2 1

ans =  4 3 2 1

ans =  1 2 3 4





*/