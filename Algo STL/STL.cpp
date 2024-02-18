#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

bool compare(int a,int b){
	return a>b;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for( int i=0;i<n;i++ ){
		cin>>arr[i];
	}
	int key;
	cin>>key;
	auto index = find(arr, arr+n, key); //Linear Search
	if ( index - arr == n ){
		cout<<"Not found "<<endl;
	} else {
		cout<<"Element found at "<<(index-arr)<<endl;
	}

	sort(arr,arr+n); // Sorting

	cout<<"Sorting"<<endl;
	for(auto it:arr){
		cout<<it<<" ";
	}
	cout<<endl;

	bool ans = binary_search(arr, arr+n, key ); //Binary Search

	if(ans){
		cout<<"Key "<<key<<" is present."<<endl;
	} else{
		cout<<"Key "<<key<<" not present"<<endl;
	}

	auto lb = lower_bound( arr, arr+n, key ); // Lower bound of element
	cout<<"lower bound is "<<(lb-arr)<<endl;

	auto ub = upper_bound( arr, arr+n, key ); // upper bound of element
	cout<<"upper bound is "<<(ub-arr)-1<<endl;


	cout<<"Total Occ of element is "<<(ub-lb)<<endl; // total occurance

	sort(arr, arr+n, compare); //Sort with compare

	cout<<"Sorting in decreasing order"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}