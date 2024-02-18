#include<iostream>
#include <unordered_set>
using namespace std;

//Hashing 04 - Longest Consecutive Subsequence - I With Unordered Map
int findLargestSequence(int a[], int n){

	unordered_set<int> s;

	for(int i=0;i<n;i++){
		s.insert(a[i]); //O(1)
	}

	int max_streak = 0;
	for(int i=0;i<n;i++){
		int head = a[i]-1;
		int cnt = 0;
		if( s.find(head)==s.end() ){
			//a[i]is the starting point of streak
			//traverse the entire range that is contained in that streak
			int next_no = a[i]+1;
			int streak_len = 1;
			while(s.find(next_no)!=s.end()){
				next_no += 1;
				streak_len += 1;
			}
			max_streak = max(max_streak,streak_len);
		}
	}
	return max_streak;
}

int main(){

	int arr[] = {14,5,1,2,6,3,7,8,9,13,15,11,12,13,17,10};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout<<findLargestSequence(arr,n)<<endl;

	return 0;
}

/*

s= 14,5,1,2,6,3,7,8,9,13,15,11,12,13,17




*/