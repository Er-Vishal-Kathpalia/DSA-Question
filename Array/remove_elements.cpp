#include<bits/stdc++.h>
using namespace std;

void print(vector<int> arr){

	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


int removeElement(vector<int>& nums, int val) {

	int n = nums.size();
	int k = -1;
	for(int i=0;i<n;i++){
		if(nums[i] != val){
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

 	int val;
 	cin>>val;
 	cout<<removeElement(nums,val)<<endl;

 	print(nums);

	return 0;
}