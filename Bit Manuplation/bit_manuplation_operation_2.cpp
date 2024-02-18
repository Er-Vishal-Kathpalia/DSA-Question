#include<bits/stdc++.h>
using namespace std;

int clearBitsInRangeFromLast(int n, int i){
	int ones = ~(0);
	int mask = ones<<i;
	int ans = n&mask;
	return ans;
}

int clearBitsInRangeFromItoJ(int n, int i, int j){
	int ones = ~(0);
	int a = ones<<j;
	int b = ~(ones<<i);
	int mask =a|b;
	int ans = n&mask;
	return ans;
}


int main(){
	int n,i,j;
	cin>>n>>i>>j;

	cout<<clearBitsInRangeFromLast(n,i)<<endl;
	cout<<clearBitsInRangeFromItoJ(n,i,j)<<endl;
	return 0;''
}


/*



*/