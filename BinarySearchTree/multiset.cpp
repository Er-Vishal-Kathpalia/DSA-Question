#include <iostream>
#include <set>
using namespace std;

typedef multiset<int>::iterator It;

int main(){

	int arr[] = {1,2,2,3,4,4,5,5,5,6,6,6,7,7,7,7,8};
	int n = sizeof(arr)/sizeof(arr[0]);

	multiset<int> m(arr,arr+n);

	//insert
	m.insert(100);

	//remove all occurance
	m.erase(2);

	//count occurance
	cout<<m.count(7)<<endl;

	//find
	auto f = m.find(8);
	cout<<"Find "<<*f<<endl;

	//equal range
	pair<It,It> range = m.equal_range(7);

	for(auto it=range.first;it!=range.second;it++){
		cout<<*it<<" - ";
	}
	cout<<endl;

	for(auto it=m.lower_bound(4);it!=m.upper_bound(7);it++){
		cout<<*it<<" -- ";
	}
	cout<<endl;

	for(auto it:m){
		cout<<it<<" ";
	}
	cout<<endl;
	return 0;
}