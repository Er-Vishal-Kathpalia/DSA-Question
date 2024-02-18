#include<bits/stdc++.h>
using namespace std;

bool getOdd(int n){
	return n&1;
}

int getBits(int n, int i){
	int mask = (1 << i);
	int bit = (n&mask) > 0 ? 1 : 0;	
	return bit;
}


int setBit( int n, int i ){
	int mask = (1 << i);
	int ans = n|mask;
	return ans;
}

void clearBit(int &n ,int i){
	int mask = ~(1 << i);
	n = n & mask;
}

void updateBit(int &n, int i, int v){
	int mask = ~(1 << i);
	int cleared_n = n&mask;
	n = cleared_n | (v << i);
}

int clearBitInRangefromLast(int &n, int i ){
	int mask = (-1<<i);
	int ans = n&mask;
	return ans;
}

int clearBitInRangeFromItoJ(int &n, int i, int j){
	int ones = ~0;
	int a = ones<<(j+1);
	int b = (1<<i)-1;
	int mask = a|b;
	int ans = n&mask;
	return ans;
}


int main(){
	int n;
	cin>>n;

	// cout<<clearBitInRangefromLast(n, 3)<<endl;

	cout<<clearBitInRangeFromItoJ(n, 2 ,3)<<endl;


	// cout<<getOdd(n)<<endl;

	// cout<<getBits(n,1)<<endl;

	// setBit(n, 3);
	// cout<<n<<endl;

	// clearBit(n, 2);
	// cout<<n<<endl;



	return 0;
}


/*
n=31
1 1 1 1 1
1 1 0 0 0

1 0 0 1 1


*/