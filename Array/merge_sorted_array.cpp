#include<bits/stdc++.h>
using namespace std;

void print(vector<int> arr){

	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){

	int i=0;
	int j=0;

	vector<int> ans;

	while(i<m && j<n){
		if(nums1[i] <= nums2[j]){
			ans.push_back(nums1[i]);
			i++;
		} else{
			ans.push_back(nums2[j]);
			j++;
		}
	}

	while(i<m){
		ans.push_back(nums1[i]);
		i++;
	}

	while(j<n){
		ans.push_back(nums2[j]);
		j++;
	}

	nums1.resize(ans.size());

	for(int k=0;k<ans.size();k++){
		nums1[k] = ans[k];
	}

}


int main(){

	int m,n;
	cin>>m>>n;

	vector<int> nums1;
	vector<int> nums2;

 	for(int i=0;i<m;i++){
 		int temp;
 		cin>>temp;
 		nums1.push_back(temp);
 	}

 	for(int i=0;i<n;i++){
 		int temp;
 		cin>>temp;
 		nums2.push_back(temp);
 	}

 	merge(nums1,m,nums2,n);

 	print(nums1);
 	// print(nums2);
	return 0;
}