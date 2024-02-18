#include <bits/stdc++.h>
using namespace std;

int pow(int a, int b){
	//base case
	if(b==1){
		return a;
	}
	return a*pow(a,b-1);

}


int main(){

	int a,b;
	cin>>a>>b;

	cout<<pow(a, b)<<endl;
}

/*
2,5
2 * 2* 2* 2* 2 = 32

[2, 5]
2 * [2, 4]
2 * 2 * [2, 3]
2 * 2 * 2 * [2,2]
2 * 2 * 2 * 2 * [2,1]
2 * 2 * 2 * 2 * 2 = 32 Ans
*/

