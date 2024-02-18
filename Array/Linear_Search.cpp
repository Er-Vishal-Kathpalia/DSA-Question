#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int key;
	cin>>key;
	int arr[n];

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int i;
	for(i=0;i<n;i++){
		if(key == arr[i]){
			cout<<"Element found at index"<<i<<endl;
			break;
		}
	}
	if(i == n){
		cout<<"Element not found"<<endl;
	}
	return 0;

}