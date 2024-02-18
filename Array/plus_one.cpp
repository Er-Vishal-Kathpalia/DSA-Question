#include<bits/stdc++.h>
using namespace std;

void print(vector<int> arr){

	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


vector<int> plusOne(vector<int>& digits) {
	int sum = 1;
	// cin>>sum;
	int len = digits.size()-1;
	int carry = 0;

	for(int i=len;i>=0;i--){
		digits[i] = digits[i]+sum+carry;
		sum = 0;
		carry = 0;
		if( digits[i] > 9 ){
			int ld = digits[i]%10;
			digits[i] = ld;
			carry = 1;
		} else{
			break;
		}
	}

	if( carry > 0 ){
		vector<int> ans;
		ans.push_back(carry);
		for(int i=0;i<len+1;i++){
			ans.push_back(digits[i]);
		}
		return ans;
	}

	return digits;
}


int main(){

	int n;
	cin>>n;

	vector<int> nums;

 	for(int i=0;i<n;i++){
 		int temp;
 		cin>>temp;
 		nums.push_back(temp);
 	}

 	vector<int> ans = plusOne(nums);
 	print(ans);

	return 0;
}

/*
1 2 3 + 1
1 2 4

9 + 1
1 0


*/