#include <bits/stdc++.h>
#include <cstring>
using namespace std;
// Problem
// -------
// Find the smallest window in a string containing all characters of another string.
// String -> "hellloeeo world"
// Pattern -> "eelo"

string find_window(string s, string pat){

	int SL = s.length();
	int PL = pat.length();

	//Corner Case
	if(PL > SL){
		return "None";
	}

	//2. Freq Maps
	int FS[256] = {0};
	int FP[256] = {0};

	for(int i=0;i<PL;i++){
		char ch = pat[i];
		FP[ch]++;
	}

	int cnt = 0;
	int start = 0;
	int min_len = INT_MAX;
	int start_idx = -1;
	//3. Sliding Window Expansion & Contraction+ update the Min Length Window
	for(int i=0;i<SL;i++){
		char ch = s[i];
		FS[ch]++;

		//Maintain the count of char match
		if(FP[ch] != 0 and FS[ch] <= FP[ch]){
			cnt++;
		}

		//if all the char match
		if(cnt == PL){
			//start shrinking the window
			char temp = s[start];
			while(FP[temp] == 0 or FS[temp] > FP[temp]){
				FS[temp]--;
				start++;
				temp = s[start];
			}

			//window size
			int window_len = i-start+1;
			if(window_len<min_len){
				min_len = window_len;
				start_idx = start;
			}
		}
	} 

	if(start_idx == -1){
		return "None";
	}
	string ans = s.substr(start_idx,min_len);
	return ans;

}


int main(){

	string s = "hllloeaeo world";
	string p = "eelo";


	cout<<find_window(s,p)<<endl;

	return 0;
}