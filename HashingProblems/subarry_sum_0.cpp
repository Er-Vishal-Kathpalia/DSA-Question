#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;

//Array contains a subarray whose sum is 0 or not.

bool checkSum(int arr[], int n){

	unordered_set<int> s;

	int pre = 0;

	for(int i=0;i<n;i++){
		pre = pre + arr[i];
		if(pre == 0 || s.find(pre)!=s.end()){
			return true;
		}
		s.insert(pre);
	}
	return false;

}

int main(){

	int n;
	cin>>n;

	int arr[n];

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	if(checkSum(arr,n)){
		cout<<"Yes"<<endl;
	} else{
		cout<<"No"<<endl;
	}

	return 0;
}