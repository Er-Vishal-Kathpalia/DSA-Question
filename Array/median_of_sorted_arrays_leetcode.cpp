#include<bits/stdc++.h>
using namespace std;

void print(vector<int> arr){

	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" "; 
	}
	cout<<endl;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
	int i = 0;
	int j = 0;
	int len1 = nums1.size()-1;
	int len2 = nums2.size()-1;
	vector<int> temp;
	while(i<=len1 && j<=len2){
		if(nums1[i] <= nums2[j]){
			temp.push_back(nums1[i]);
			i++;
		} else{
			temp.push_back(nums2[j]);
			j++;
		}
	}

	while(i<=len1){
		temp.push_back(nums1[i]);
		i++;
	}

	while(j<=len2){
		temp.push_back(nums2[j]);
		j++;
	}

	int p1 = 0;
	int p2 = temp.size()-1;
	int A,B;

	while(p1<=p2){
		if(p2>=p1){
			A = temp[p1];
			B = temp[p2];
		}
		p1++;
		p2--;
	}
	double mid = (double)(A+B)*1.0/2;
	return mid;
}


int main(){

	int m,n;
	cin>>m;

 	vector<int> arr;
 	vector<int> arr2;


 	for(int i=0;i<m;i++){
 		int temp;
 		cin>>temp;
 		arr.push_back(temp);
 	}

 	cin>>n;
 	for(int i=0;i<n;i++){
 		int temp;
 		cin>>temp;
 		arr2.push_back(temp);
 	}
 	cout<<findMedianSortedArrays(arr, arr2)<<endl;

	return 0;
}