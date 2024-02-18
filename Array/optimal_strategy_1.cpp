#include<bits/stdc++.h>
using namespace std;

void take_number(int start, int end, int arr[], int ans, int temp){
	if(arr[start]>=arr[end]){
		if(temp == -1){
			ans += arr[start];
		}
		start++;
	} else{
		if(temp == -1){
			ans += arr[end];
		}
		end--;
	}
	return;
}


int optimal_strategy(int n, int arr[]){

	int ans = 0;
	int ans1 = 0;
	int start = 0;
	int end = n-1;
	int temp = -1;

	while(start<=end){
		if(temp == -1){
			if(arr[start]>=arr[end]){
				ans+=arr[start];
				start++;
			} else{
				ans+=arr[end];
				end--;
			}
			temp = -2;
		} else{
			if(arr[start]>=arr[end]){
				ans1+=arr[start];
				start++;
			} else{
				ans1+=arr[end];
				end--;
			}
			temp = -1;
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
	cout<<optimal_strategy(n,arr)<<endl;
	return 0;
}


/*

4
1 2 3 4

4

ans = 4
1 2 3

*/