#include<bits/stdc++.h>
using namespace std;


void print(vector<int> nums){

	for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<" ";
	}
	cout<<endl;

}

void reverse(vector<int>& nums, int i, int j){

	while(i<=j){
		swap(nums[i++], nums[j--]);
	}

	return;
}


void nextPermutation(vector<int>& nums){
	int n = nums.size() - 1;
	int p = n - 1;
	while(p >= 0){
		if(nums[p] < nums[p+1]){
			break;
		}
		p--;
	}

	if( p == -1 ){
		//Edge case
		reverse(nums, 0, n);
		return;
	}

	int p2 = -1;
	for(int i=n;i>=0;i--){
		if(nums[i] > nums[p]){
			p2 = i;
			break;
		}
	}

	swap(nums[p], nums[p2]);
	reverse(nums, p+1, n);
	return;
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
 	nextPermutation(nums);

 	print(nums);

	return 0;
}

/*
Next Permutation - All Combinations
3! = 6

Dictionary order
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

Intutions, Observations

1 4 7 9 8 1 0 0
1 4 7 9 8 1 0 0
1 4 7 9 8 1 0 0 
1 4 8 0 0 1 7 9


1 4 8 9 7 1 0 0

1 4 9 6 8 1 0 1

1 4 9 6 8 1 0 1

 1 4 9 6 8 0 1 1 
 1 4 9 6 8 1 1 0

2 1 3


*/