#include<bits/stdc++.h>
using namespace std;

// bool str_contains( string temp, char ch ){
// 	for(int i=0;i<temp.length();i++){
// 		if(temp[i] == ch){
// 			return true;
// 		} 
// 	}
// 	return false;
// }


// int lengthOfLongestSubstring(string s) {
// 	int len = s.length();
// 	if(len<=1){
// 		return len;
// 	}
// 	int ans = 0;
// 	string temp = "";
// 	for(int i=0;i<s.length();i++){
// 		if(!str_contains(temp, s[i])){
// 			temp += s[i];
// 		} else {
// 			int temp_length = temp.length();
// 			if( ans<=temp_length ){
// 				ans = temp_length;
// 			}
// 			temp = "";
// 			i--;
// 		}
// 	}
// 	return ans;
// }

bool strContains(string temp, char target){

	for(int i=0;i<temp.length();i++){
		if(temp[i] == target){
			return true;
		}
	}
	return false;
}


int lengthOfLongestSubstring(string s){

	int size = s.length();
	if( size <= 1 ){
		return size;
	}

	int maxAns = 0;
	int ans = 0;
	string temp = "";
	for(int i=0;i<size;i++){
		char ch = s[i];
		if(strContains(temp, ch)){
			temp = "";
			ans = 0;
		}
		ans++;
		maxAns = max(ans, maxAns);
		temp += s[i];
	}
	return maxAns;

}



int main(){
	string s;
	cin>>s;
	cout<<lengthOfLongestSubstring(s)<<endl;
	return 0;
}


/*
50000
sliding window

" "

len = 1
temp = " "
ans = 0


len = 6
temp = ""
pw
ans = 2







temp = "abc"
ans = 3
temp = 


temp=abc
len = 3
temp=abc
len = 3
temp=b
len = 1
temp=b
len = 1



pwwkew

temp = pw
len=2
temp = wke
len=3
temp = w
len = 1









*/