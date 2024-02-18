#include <bits/stdc++.h>
using namespace std;


void resizing(vector<int> &arr, int diff){

	int n = arr.size();

	vector<int> temp;

	for(int i=0;i<diff;i++){
		temp.push_back(0);
	}

	for(int i=0;i<n;i++){
		temp.push_back(arr[i]);
	}

	arr.resize(0);

	for(int i=0;i<temp.size();i++){
		arr.push_back(temp[i]);
	}

	return;
}


void print(vector<int> arr){
	
	for(int i=arr.size()-1;i>=0;i--){
		cout<<arr[i]<<", ";
	}
	cout<<"END"<<endl;
	return;
}


void sum_of_arrays(vector<int> a, vector<int> b){
	vector<int> ans;
	int n = a.size();
	bool carry = false;
	for(int i=n-1;i>=0;i--){
		int s = a[i]+b[i];
		if(carry){
			ans.push_back((s%10) + 1);
		} else{
			ans.push_back(s%10);
		}
		if(s > 9){
			carry = true;
		} else {
			carry = false;
		}
	}

	if(carry){
		ans.push_back(1);
	}

	print(ans);

}

int main(){

	int n,m;
	cin>>n;
	vector<int> a;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		a.push_back(temp);
	}

	cin>>m;
	vector<int> b;
	for(int i=0;i<m;i++){
		int temp;
		cin>>temp;
		b.push_back(temp);
	}
	
	if(n < m){
		resizing(a,m-n);
	} else if(n > m){
		resizing(b,n-m);
	}


	sum_of_arrays(a, b);

}