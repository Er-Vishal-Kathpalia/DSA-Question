#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int> > arr){

	for(int i=0;i<arr.size();i++){
		vector<int> temp = arr[i];
		for(int j=0;j<temp.size();j++){
			cout<<temp[j]<<" ";
		} 
		cout<<endl;
	}
	cout<<endl;
}

int threeSumClosest(vector<int>& nums, int target){
	int n = nums.size()-1;
	if(n < 2){
		return 0;
	}
	sort(nums.begin(),nums.end());
	int res = nums[0] + nums[1]+nums[2];
	for(int i=0;i<=n-2;i++){
		int l = i+1;
		int r = n;
		while(l<r){
			int csum = nums[i]+nums[l]+nums[r];
			if( abs(res-target) >= abs(csum-target) ){
				res = csum;
			} 
			if( csum <= target ){
				l++;
			} else {
				r--;
			}
		}
	}
	return res;
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

 	int target;
 	cin>>target;
 	cout<<threeSumClosest(nums,target)<<endl;

	return 0;
}