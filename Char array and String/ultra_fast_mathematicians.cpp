#include<bits/stdc++.h>
using namespace std;

string calculate(string s1, string s2){
	int len1 = s1.length();
	int len2 = s2.length();
	string ans = "";
	if( len1 != len2 ){
		return ans;
	}

	for(int i=0;i<len1;i++){
		if(int(s1[i]) == int(s2[i])){
			ans += "0";
		}
		else{
			ans += "1";
		}
	}

	return ans;
}


int main(){

	int t;
	cin>>t;

	while(t--){
		string s1, s2;
		cin>>s1>>s2;
		cout<<calculate(s1, s2)<<endl;
	}
	return 0;
}