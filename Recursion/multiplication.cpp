#include <bits/stdc++.h>
using namespace std;

int mul(int a, int b){
	//base case
	if(a == 1){
		return b;
	}
	
	return b + mul(a-1,b);
}


int main(){

	int a,b;
	cin>>a>>b;

	cout<<mul(a, b)<<endl;
}

/*
4 5 = 20
5 + 5 + 5 + 5 = 20

[4,5]

5 + [3,5]

5 + 5 + [2,5]

5 + 5 + 5 + [1, 5]

5 + 5 + 5 + 5 =20

*/

