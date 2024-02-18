#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int no, temp;
	cin>>no;

	for(int i=1;i<n;i++){
		cin>>temp;
		no =no^temp;
	}

	cout<<no<<endl;
	return 0;
}