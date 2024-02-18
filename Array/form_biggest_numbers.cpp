#include <bits/stdc++.h>
using namespace std;


int pow(int x){
	int ans = 1;
	while(x > 0){
		ans = ans*10;
		x--;
	}
	return ans;
}

int len(int a){
	int ans = 0;
	while(a>0){
		ans++;
		a = a/10;
	}
	return ans;
}

bool cmp(int a, int b){
	int lena = len(a);
	int lenb = len(b);
	if( lena == lenb ){
		return a>b;
	}
	if( lena < lenb ){
		int diff = lenb - lena;
		int x = pow(diff);
		int d = lena * x;
		return d > b;
	}
	int diff = lena - lenb;
	int x = pow(diff);
	int d = lenb * x;
	return a > d;
}


int main(){

	int t,n;
	cin>>t;

	while(t--){
		cin>>n;

		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}

		sort(arr, arr+n, cmp);

		for(int i=0;i<n;i++){
			cout<<arr[i];
		}
		cout<<endl;
	}

	return 0;
}