#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> arr){

	for(int i=0;i<arr.size();i++){
		vector<int> temp = arr[i];
		for(int j=0;j<temp.size();j++){
			cout<<temp[j]<<" ";
		} 
		cout<<endl;
	}
	cout<<endl;
}

vector<vector<int>> threeSum(vector<int>& nums){
	vector<vector<int>> ans;
	int n = nums.size()-1;
	if(n < 2){
		return ans;
	}
	sort(nums.begin(),nums.end());
	set<vector<int> > s;
	for(int i=0;i<=n-2;i++){
		int l = i+1;
		int r = n;
		while(l<r){
			int csum = nums[i]+nums[l]+nums[r];
			if(csum == 0){
				s.insert({nums[i],nums[l],nums[r]});
				l++;
				r--;
			} else if( csum < 0 ){
				l++;
			} else {
				r--;
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

 	vector<vector<int>> ans = threeSum(nums);
 	print(ans);

	return 0;
}