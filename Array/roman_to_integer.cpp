#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

void print(vector<int> arr){

	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
 

int romanToInt(string s){
	
	unordered_map<char,int> hash = {
		{'I',1},
		{'V',5},
		{'X',10},
		{'L',50},
		{'C',100},
		{'D',500},
		{'M',1000}
	};
	int len = s.length()-1;
	int num = hash[s[len]];
	for(int i=len-1;i>=0;i--){
		if(hash[s[i]] < hash[s[i+1]]){
			num -= hash[s[i]];
		} else{
			num += hash[s[i]];
		}
	}

	return num;
}


int main(){

	
	string s;
	cin>>s;

	cout<<romanToInt(s)<<endl;

	return 0;
}

/*
III = 3
I = 1
V = 5
X = 10
L = 50
C = 100
D = 500
M = 1000

I II III IV V VI VII VIII IX X XI XII XIII XIV XV XVI XVII XVIII XIX XX
6 Instances
1. I can be placed before V and X
2. X can be placed before L and C
3. C can be placed before D and M


990 + 500 =  1490
DMX = 1490

*/