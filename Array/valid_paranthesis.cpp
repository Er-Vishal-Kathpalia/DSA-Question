#include <bits/stdc++.h>
using namespace std;



bool isValid(string s){
	stack<char> temp;
	for(int i=0;i<s.length();i++){
		if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
			temp.push(s[i]);
		}
		if(s[i] == ')'){
			
		} 
	}
}

int main(){

	string s;
	cin>>s;

	cout<<isValid(s)<<endl;

	return 0;
}