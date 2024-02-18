#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;

//Hashing 02 - Length Of Longest Subarray With Sum Zero
typedef unordered_map<int, int>::iterator it;
int checkLongestSubarraySum(int arr[], int n){

	unordered_map<int, int> s;

	int pre = 0;
	int ans = 0;

	for(int i=0;i<n;i++){
		pre = pre + arr[i];
		it temp = s.find(pre);
		if(pre == 0){
			int y = i+1;
			ans = max(ans,y);
		}
		if(temp!=s.end()){
			int y = i;
			int x = y - temp->second;
			ans = max(ans,x);
		}
		s.insert(make_pair(pre, i));
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

	cout<<checkLongestSubarraySum(arr,n)<<endl;

	return 0;
}