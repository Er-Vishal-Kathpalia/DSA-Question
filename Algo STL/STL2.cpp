#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

int main(){
	int arr[] = {1,2,3,4,5,6};
	int n = sizeof(arr)/sizeof(arr[0]);
	int mid = n/2;
	rotate(arr, arr+mid, arr+n); //rotate array
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
    cout<<endl;

	//Vector = Dynamic Array

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
 	//rotate(v.begin(), v.begin(), v.end()); //rotate array
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl<<"Next Permutation "<<endl;
	//next_permutation
	next_permutation(v.begin(), v.end());
	for(int x:v){
		cout<<x<<" ";
	}
	cout<<endl;

	int a = 10;
	int b = 20;
	swap(a, b); //swap
	cout<<a<<" "<<b<<endl;

	cout<<"Max is "<<max(a, b)<<endl; // max
	cout<<"Min is "<<min(a, b)<<endl; // min

	int arr2[] = {10,20,30,40,50};
	reverse(arr2, arr2+4); //reverse the array
	int size = sizeof(arr2)/sizeof(arr2[0]);

	for(int i=0;i<size;i++){
		cout<<arr2[i]<<" ";
	}


	return 0;
}