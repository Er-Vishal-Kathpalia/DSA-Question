#include<bits/stdc++.h>
using namespace std;

void print(vector<int> arr){

	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int maxProfit(vector<int>& prices){
	int len = prices.size()-1;

	int maximumProfit[len+1];
	maximumProfit[len] = prices[len];
	for(int i=len-1;i>=0;i--){
		maximumProfit[i] = max(prices[i], maximumProfit[i+1]);
	}

	int ans = 0;
	for(int i=0;i<len;i++){
		int diff = maximumProfit[i] - prices[i];
		if(diff < 0){
			diff = 0;
		}
		ans = max(diff, ans);
	}

	return ans;
}


int main(){

	int n;
	cin>>n;

	vector<int> nums;

	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		nums.push_back(temp);
	}

	cout<<maxProfit(nums)<<endl;

	return 0;
}

/*
*/


