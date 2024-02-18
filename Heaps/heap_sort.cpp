#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b){
	return a < b;
}

void heapify(vector<int> &heap, int idx, int size){
		int left = 2*idx;
		int right = left +1;

		int min_idx = idx;
		int last = size-1;
		if(left <= last && compare(heap[left], heap[idx])){
			min_idx = left;
		}
		if(right <= last && compare(heap[right], heap[idx])){
			min_idx = right;
		}

		if(min_idx!=idx){
			swap(heap[idx], heap[min_idx]);
			heapify(heap,min_idx,size);
		}
	}


//O(N)
void buildHeapInOptimised(vector<int> &v){
	for(int i=(v.size()-1)/2;i>=1;i--){
		heapify(v,i,v.size());
	}
}


void heapSort(vector<int> &arr){

	buildHeapInOptimised(arr);
	int n = arr.size();

	while(n>1){
		swap(arr[1],arr[n-1]);
		n--;
		heapify(arr,1,n);
	}


}

int main(){	

	vector<int> v;
	int n;
	cin>>n;
	v.push_back(-1);
	for(int i=1;i<n;i++){
		int no;
		cin>>no;
		v.push_back(no);
	}
	heapSort(v);
	
	for(int i=1;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}