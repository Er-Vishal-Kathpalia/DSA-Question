#include<bits/stdc++.h>
using namespace std;

void print(vector<int> arr){

	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void swapp(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
	return;
}


vector<int> reverseArray(vector<int> &nums){
	int l=0;
	int r = nums.size()-1;

	while(l<=r){
		swapp(nums[l],nums[r]);
		l++;
		r--;
	}

	return nums;
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

	reverseArray(nums);
	print(nums);

	return 0;
}
