#include <bits/stdc++.h>
using namespace std;

int main(){

	//2D array
	//Static / Compile Time Array
	int x[10][10];
	cout<<sizeof(x)<<endl; //--400

	//Dynamic 2d Array

	int **arr;

	int r,c;
	cin>>r>>c;

	arr = new int*[r];

	for(int i=0;i<r;i++){
		arr[i] = new int[c];
	}

	int var = 1;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			arr[i][j] = var;
			var++;
		}
	}

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}


	return 0;
}