#include<bits/stdc++.h>
using namespace std;

void print(vector<int> arr){

	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


int removeDuplicates(vector<int>& nums){

	int n = nums.size();
	if( n < 2){
		return nums.size();
	}
	int k = 0;
	for(int i=1;i<n;i++){
		if(nums[i] != nums[i-1]){
			nums[++k] = nums[i];
		}
	}

	for(int i=k+1;i<n;i++){
		nums[i] = -1;
	}

	return k+1;
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

 	cout<<removeDuplicates(nums)<<endl;

 	print(nums);

	return 0;
}