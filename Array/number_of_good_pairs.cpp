#include<iostream>
using namespace std;

int numIdenticalPairs(vector<int>& nums) {
	int ans = 0;
	int len = nums.size();
	int m = -1;

	for(int i=0;i<len;i++){
		m = max(nums[i],m);
	}

	int temp[m+1];
	for(int i=0;i<=m;i++){
		temp[i] = 0;
	}

	for(int i=0;i<len;i++){
		int no = nums[i];
		ans = ans+temp[no];
		temp[no]++;
	}

	return ans;
}

int main(){

	vector<int> arr;

	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		int no;
		cin>>no;
		arr.push_back(no);
	}

	cout<<numIdenticalPairs(arr)<<endl;

	// int arr[] = {0,1,1,1,2,2,2,2,3,3,0,4,1};
	// int n = sizeof(arr)/sizeof(arr[0]);

	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i] == arr[j]){
				ans++;
			}
		}
	}

	cout<<ans<<endl;
	return 0;
}