#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;

//Hashing 02 - Length Of Longest Subarray With Sum k
typedef unordered_map<int, int>::iterator it;
int checkLongestSubarraykSum(int arr[], int n, int k){

	unordered_map<int, int> m;

	int pre = 0;
	int ans = 0;

	for(int i=0;i<n;i++){
		pre = pre + arr[i];
		if(pre == k){
			ans = max(ans,i+1);
		}
		else if(m.find(pre-k)!=m.end()){
			ans = max(ans,i-m[pre-k]);
		}
		else{
			m[pre] = i;
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
	int k;
	cin>>k;

	cout<<checkLongestSubarraykSum(arr,n,k)<<endl;

	return 0;
}