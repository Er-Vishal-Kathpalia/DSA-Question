#include<bits/stdc++.h>
using namespace std;

void print(vector<int> arr){

	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void print2dArr(vector<vector<int> > arr){

	for(int i=0;i<arr.size();i++){
		for(int j=0;j<arr[i].size();j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}


vector<vector<int> > generate(int numRows){
	vector<vector<int> > ans;
	if(numRows <= 0){
		return ans;
	}

	for(int i=1;i<=2;i++){
		int j=i;
		vector<int> temp;
		while(j > 0){
			temp.push_back(1);
			j--;
		}
		ans.push_back(temp);
		if( numRows == i ){
			return ans;
		}
		temp.resize(0);
	}

	for(int i=3;i<=numRows;i++){
		vector<int> temp;
		temp.push_back(1);
		//Push pairs of last one arr
		for(int j=0;j<ans[i-2].size()-1;j++){
			temp.push_back(ans[i-2][j] + ans[i-2][j+1]);
		}
		temp.push_back(1);
		ans.push_back(temp);
		temp.resize(0);
	}

	return ans;

}

int main(){

	int numRows;
	cin>>numRows;

	vector<vector<int> > ans = generate(numRows);
	print2dArr(ans);

	return 0;
}

/*
Pascal's triangle

       1
      1 1
     1 2 1
    1 3 3 1
   1 4 6 4 1




*/