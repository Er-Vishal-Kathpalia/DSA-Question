#include<bits/stdc++.h>
using namespace std;

int fast_pow(int a, int b){

	if(b==0){
		return 1;
	}
	int small_pow = fast_pow(a,b/2);
	small_pow *= small_pow;
	if(b&1){
		return small_pow*a;
	}
	return small_pow;
}

int main(){

	int a,b;
	cin>>a>>b;
	cout<<fast_pow(a,b)<<endl;

	return 0;
}

/*
4,5
4*4*4*4*4


*/