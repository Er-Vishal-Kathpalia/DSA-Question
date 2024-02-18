#include <bits/stdc++.h>
using namespace std;


long stringToLong(string s){

	if(s.empty()){
		return 0;
	}
	long i,j=0;
	i = 0;
	while(s[j] >= '0' && s[j] <= '9'){
		i =  i*10 +(s[j] - '0');
		j++;
	}
	return i;
}


bool isCbNumber(string s){
	long no = stringToLong(s);
	if(no == 0 || no == 1){
		return false;
	}
	int cbNo[10] = {2,3,5,7,11,13,17,19,23,29};

	for(int i=0;i<10;i++){
		if(cbNo[i] == no || !cbNo[i]%no == 0 ){
			return true;
		}
	}
	return false;
}


string checkIfCbNo(string s){
	long no = stringToLong(s);
	vector<string> isValid;
	for(int i=0;i<isValid.size();i++){
		if( isValid[i].contains() )
	}
}


int main(){

	string s;
	cin>>s;

	for(int i=0;i<s.length();i++){
		for(int j=i;j<s.length();j++){
			string temp;
			for(int k=i;k<=j;k++){
				temp += s[k];
			}
			cout<<checkIfCbNo(temp)<<endl;
		}
	}

	return 0;
}