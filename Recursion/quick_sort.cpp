#include<bits/stdc++.h>
using namespace std;


int pivot(int *a,int s,int e){

	int i= s-1;
	int j = s;
	int pivot_element = a[e];

	for(;j<=e-1;){
		if(a[j] <= pivot_element){
			i = i+1;
			swap(a[i],a[j]);
		}
		j = j+1;
	}                   
	swap(a[i+1],a[e]);
	return i+1;
}


void quick_sort(int *a, int s, int e){

	//base case
	if(s>=e){
		return;
	}

	int p = pivot(a,s,e);

	quick_sort(a,s,p-1);
	quick_sort(a,p+1,e);

}




int main(){

	int a[] = {5,4,3,2,1,9,2,5,1,5,6,12,4,6,2,121,34,2,546,12,99,999,111,101};
	int n = sizeof(a)/sizeof(a[0]);

	quick_sort(a,0,n-1);

	for (int i = 0; i < n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}