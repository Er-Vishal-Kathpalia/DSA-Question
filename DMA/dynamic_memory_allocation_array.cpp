#include <bits/stdc++.h>
using namespace std;

int main(){

	//Static / Compile Time Array
	int x[10];
	cout<<sizeof(x)<<endl; //--40

	//Dynamic Array
	int n;
	cin>>n;
	int *a = new int[n];
	cout<<sizeof(a)<<endl; //--8bytes

	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}

	//Memory leaks

	//Delete the dynamic memory
	delete [] a;
	return 0;
}