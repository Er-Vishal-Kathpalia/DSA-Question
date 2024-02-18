#include<bits/stdc++.h>
using namespace std;

int main(){

	int n,k;
	cin>>n;

	int ans = INT_MIN;

	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		ans = max(ans,temp);
	}

	cout<<ans<<endl;
	return 0;
}