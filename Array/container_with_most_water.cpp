#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height){

	int i = 0;
	int j = height.size()-1;

	int ans = 0;

	while(i<=j){
		int h = min(height[i], height[j]);
		ans = max(ans,(j-i)*h);
		if(height[j] > height[i]){
			i++;
		} else{
			j--;
		}
	}

	return ans;
}


int main(){

	int n;
	cin>>n;

 	vector<int> arr;


 	for(int i=0;i<n;i++){
 		int temp;
 		cin>>temp;
 		arr.push_back(temp);
 	}

 	cout<<maxArea(arr)<<endl;

	return 0;
}