#include<bits/stdc++.h>
using namespace std;

string diff(string s){

	string ans;
	int len = s.length();
	cout<<s[0];
	for(int i=0;i<len;i++){
		if( i+1 < len ){
			int d = int(s[i+1]) - int(s[i]);
			cout<<d;
			cout<<s[i+1]; 
		}
	}

	return ans;
}


int main(){

	string s;
	cin>>s;

	cout<<diff(s)<<endl;
	return 0;
}