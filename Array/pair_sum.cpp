#include<iostream>
#include<algorithm>
using namespace std;

void pair_sum(int n, int arr[], int sum){
	int i = 0;
	int j = n-1;

	int current_sum = 0;
	while(i<=j){
		current_sum = arr[i]+arr[j];
		if(current_sum==sum){
			cout<<arr[i]<<", "<<arr[j]<<endl;
			i++;
			j--;
		}

		if (current_sum < sum){
			i++;
		}
		else {
			j--;
		}
	}
}

int main(){

	int n;
	cin>>n;
	int arr[n];
	int sum;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>sum;
	pair_sum(n, arr, sum);
	return 0;
}