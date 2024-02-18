#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int> > arr){
	for(int i=0;i<arr.size();i++){
		for(int j=0;j<arr[i].size();j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

void test(vector<vector<int> > &nums){

}

int main(){

	int m,n; //m = rows, n = cols
	cin>>m>>n;

	vector<vector<int> > nums;

	for(int i=0;i<m;i++){
		vector<int> vec;
		for(int j=0;j<n;j++){
			int temp;
			cin>>temp;
			vec.push_back(temp);
		}
		nums.push_back(vec);
	}


	test(nums);
	return 0;
}

/*


*/