#include<iostream>
#include<algorithm>
using namespace std;

// void generate_subarrays( int n, int arr[] ){

// 	for(int i=0;i<n;i++){
// 		for(int j=i;j<n;j++){
// 			for(int k=i;k<=j;k++){
// 				cout<<arr[k]<<" ";
// 			}
// 			cout<<endl;
// 		}
// 	}
// }

//O(n^3) complexity Generate maximum sum
// void generate_subarrays_sum1( int n, int arr[] ){
// 	int current_sum;
// 	int maximum_sum = 0;
// 	int left = -1;
// 	int right = -1;
// 	for(int i=0;i<n;i++){
// 		for(int j=i;j<n;j++){
// 			current_sum = 0;
// 			for(int k=i;k<=j;k++){
// 				current_sum += arr[k];
// 			}
// 			cout<<current_sum<<endl;
// 			if( maximum_sum < current_sum ){
// 				maximum_sum = current_sum;
// 				left = i;
// 				right = j;
// 			}
// 		}
// 	}
// 	cout<<"Maximum sum is "<<maximum_sum<<endl;
// 	cout<<"["<<left<<","<<right<<"]"<<endl;
// 	for(int i=left;i<=right;i++){
// 		cout<<arr[i]<<" ";
// 	}
// }


// O(n^2) complexity and O(n) space complexity
// void generate_subarrays_sum2( int n, int arr[], int csum[] ){
// 	int current_sum = 0;
// 	int maximum_sum = 0;
// 	int left = -1;
// 	int right = -1;
// 	for(int i=0;i<n;i++){
// 		for(int j=i;j<n;j++){
// 			current_sum = 0;
// 			current_sum = csum[j] - csum[i-1];
// 			cout<<current_sum<<endl;
// 			if( maximum_sum < current_sum ){
// 				maximum_sum = current_sum;
// 				left = i;
// 				right = j;
// 			}
// 		}
// 	}
// 	cout<<"Maximum sum is "<<maximum_sum<<endl;
// 	cout<<"["<<left<<","<<right<<"]"<<endl;
// 	for(int i=left;i<=right;i++){
// 		cout<<arr[i]<<" ";
// 	}
// }


//O(N) complexity Kadane's algorithm
void generate_subarrays_sum3(int n, int arr[]){
	int cs = 0;
	int ms = 0;
	for(int i=0;i<n;i++){
		cs = cs += arr[i];
		if(cs<0){
			cs = 0;
		}
		ms = max(ms,cs);
	}
	cout<<ms<<endl;
}


int main(){
	
	int n;
	cin>>n;
	int arr[n];

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	// int csum[n];
	// cin>>arr[0];
	// csum[0] = arr[0];
	// for(int i=1;i<n;i++){
	// 	cin>>arr[i];
	// 	csum[i] = csum[i-1]+arr[i];
	// }
	
	// cout<<"csum is"<<endl;
	// for(int i=0;i<n;i++){
	// 	cout<<csum[i]<<" ";
	// }
	// cout<<endl;
	// generate_subarrays( n, arr );
	// generate_subarrays_sum1( n, arr );
	// generate_subarrays_sum2(n, arr, csum);
	generate_subarrays_sum3(n, arr);
	return 0;
}



/*

*/