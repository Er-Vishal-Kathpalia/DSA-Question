#include<bits/stdc++.h>
using namespace std;

int main(){

	int arr[9000];
	int n,i,val,diff;

	while(1){
		//Take input current test case
		int max_load = 0, load = 0;
		cin>>n;

		//Stop taking input if n=-1
		if(n == -1){
			break;
		}

		for(int i=0;i<n;i++){
			cin>>arr[i];
			load += arr[i];
		}

		if(load%n!=0){
			cout<<-1<<endl;
			continue;
		}

		//Find the load that can be divided equally

		load = load/n;

		//greedy step
		diff = 0;
		for(int i=0;i<n;i++){
			diff += (arr[i] - load);
			int ans = max(diff,-diff);
			max_load = max(ans,max_load);
		}
		cout<<max_load<<endl;
	}

	return 0;
}



/*
3
0 99 3

34 34 34

99+3/3 = 102/3 = 34 

*/