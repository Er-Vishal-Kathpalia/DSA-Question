#include<bits/stdc++.h>
using namespace std;


void print(vector<int> nums){

	for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<" ";
	}
	cout<<endl;

}

int search(vector<int>& nums, int target){

	int rightMost  = nums.size()-1;
	int s = 0;
	int e = nums.size()-1;
	int ans = -1;
	while(s<=e){
		int mid = (s+e)/2;
		if( nums[mid] == target ){
			ans = mid;
			break;
		} else if( nums[0] < nums[mid] ){
			if( nums[0] >= target && target < nums[mid] ){
				e = mid-1;
			} else{
				s = mid+1;
			}
		} else{
			//right
			s = mid+1;
		}
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
 	int target;
 	cin>>target;
 	cout<<search(nums, target)<<endl;
 	// print(nums);

	return 0;
}

/*
4,5,6,7,0,1,2  target = 0;
Binary search

4 5 6 7 0 1 2
mid = (0+6)/2 = 3

4 5 6 7 8 0 1
mid = (0+6)/2 = 3






*/