#include <iostream>
using namespace std;

void wave_print(int m, int n, int arr[][1000] ){

	for(int col=0;col<=n-1;col++){
		if( col%2 == 0){
			for(int row=0;row<=m-1;row++){
				cout<<arr[row][col]<<" ";
			}
		} else {
			for(int row=m-1;row>=0;row--){
				cout<<arr[row][col]<<" ";
			}
		}
	}

}


int main(){

	int m,n;
	cin>>m>>n;
	int arr[1000][1000];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	wave_print(m, n, arr);
	return 0;
}


/*
4
1 2 3 4

P = 4
1 2 3
v = 3
1 2
P = 6


4 4 
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

1 5 9 13 14 10 6 2 3 7 11 15 16 12 8 4
*/