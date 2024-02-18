#include <bits/stdc++.h>
using namespace std;


string mergeAlternately(string word1, string word2){
	string ans;
	int lenWord1 = word1.length();
	int lenWord2 = word2.length();

	int i=0;
	int j=0;
	while( i<lenWord1 && j<lenWord2 ){
		ans = ans + word1[i];
		ans = ans + word2[j];
		i++;
		j++;
	}

	while(i<lenWord1){
		ans = ans+word1[i];
		i++;
	}

	while(j<lenWord2){
		ans = ans+word2[j];
		j++;
	}

	return ans;
}

int main(){

	string s1 = "";
	string s2 = "b";

	cout<<mergeAlternately(s1,s2)<<endl;
	return 0;
}