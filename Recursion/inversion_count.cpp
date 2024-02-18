#include<bits/stdc++.h>
using namespace std;

int merge(int *a, int s, int e){

	int mid = (s+e)/2;
	int i = s;
	int j = mid+1;
	int k = s;

	int cnt = 0;

	int temp[1000000];
	while(i<=mid && j<=e){
		if(a[i]<a[j]){
			temp[k++] = a[i++];
		} else{
			temp[k++] = a[j++];
			cnt += mid-i+1;
		}
	}

	while(i<=mid){
		temp[k++] = a[i++];
	}
	while(j<=e){
		temp[k++] = a[j++];
	}

	for(int i=s;i<=e;i++){
		a[i] = temp[i];
	}

	return cnt;

}

int inversion_count(int *a, int s, int e){

	if(s>=e){
		return 0;
	}
	int mid = (s+e)/2;

	int x = inversion_count(a, 0, mid);
	int y = inversion_count(a, mid+1, e);

	int z = merge(a, s, e);

	return x+y+z;
}


int main(){

	int arr[] = {5,4,3,2,1};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout<<"Inversion Count is "<<inversion_count(arr, 0, n-1)<<endl;

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}