#include<bits/stdc++.h>
using namespace std;


void print(vector<int> nums){

	for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<" ";
	}
	cout<<endl;

}
/*
1,3,5,6
2 = 1
5 = 2

0 1 3 5 6 7 9


*/
int searchInsert(vector<int>& nums, int target){
	int s = 0;
	int e = nums.size()-1;
	int ans = e+1;
	while(s<=e){
		int mid = (s+e)/2;
		if(nums[mid] >= target){
			ans = mid;
			e = mid-1;
		} else if( nums[mid] < target ){
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

	cout<<searchInsert(nums, target)<<endl;

	return 0;
}

/*
1,3,5,6
2 = 1
5 = 2

0 1 3 5 6 7 9


*/