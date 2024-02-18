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

vector<vector<int>> fourSum(vector<int>& nums, int target){

	vector<vector<int>> ans;
	int n = nums.size()-1;
	sort(nums.begin(), nums.end());
	set<vector<int>> s;
	for(int i=0;i<=n-3;i++){
		for(int j=i+1;j<=n-2;j++){
			int l = j+1;
			int r = n;
			while(l<r){
				long long int sum = (long long)nums[i]+(long long)nums[j]+(long long )nums[l]+(long long)nums[r];
				if(sum == target){
					s.insert({nums[i],nums[j],nums[l],nums[r]});
					l++;
					r--;
				} else if( sum < target ){
					l++;
				} else{
					r--;
				}
			}
		}
	}

	for(auto itr: s){
		ans.push_back(itr);
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
 	vector<vector<int>> ans = fourSum(nums,target);
 	print(ans);

	return 0;
}