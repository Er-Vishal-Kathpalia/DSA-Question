#include <iostream>
#include <set>
using namespace std;


int main(){

	int arr[] = {1,2,3,4,5,6,7,7,6,5,4,3,2,1};
	int n = sizeof(arr)/sizeof(arr[0]);

	set<int> s;

	for(int i=0;i<n;i++){
		s.insert(arr[i]);
	}

	s.erase(3);

	set<int>::iterator it = s.find(5);
	s.erase(it);

	for(set<int>::iterator it=s.begin();it!=s.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	return 0;
}