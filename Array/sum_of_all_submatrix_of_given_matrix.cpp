#include<bits/stdc++.h>
using namespace std;


// TC - O(N^6) and SC - O(1)
int sum_of_all_submatrix(int arr[][1000], int m, int n){

	int sum=0;
	for(int li=0;li<m;li++){
		for(int lj=0;lj<n;lj++){
			for(int bi=li+1;bi<m;bi++){
				for(int bj=lj+1;bj<n;bj++){
					for(int i=li;i<=bi;i++){
						for(int j=bi;j<=bj;j++){
							sum+=arr[i][j];
						}
					}
				}
			}
		}
	}
	return sum;
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

	 cout<<sum_of_all_submatrix(arr, m, n);
	return 0;
}