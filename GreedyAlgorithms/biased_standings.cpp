#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
using namespace std;

int absoluteDiff(int a, int b){
	if(a>=b){
		return a-b;
	}
	return b-a;
}


int main(){

	int arr[100000] = {0};
	int t;
	cin>>t;

	while(t--){

		memset(arr,0,sizeof arr);
		
		string name;
		int n,score;
		cin>>n;

		for(int i=0;i<n;i++){
			cin>>name>>score;
			arr[score]++;
		}

		int current_rank =1;
		int sum = 0;
		for(int i=1;i<=n;i++){
			while(arr[i]){
				sum += absoluteDiff(current_rank,i);
				arr[i]--;
				current_rank++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}


/*


*/
