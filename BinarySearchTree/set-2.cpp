#include <iostream>
#include <set>
using namespace std;


int main(){

	set<pair<int,int> > s;

	s.insert(make_pair(10,1));	
	s.insert(make_pair(10,5));
	s.insert(make_pair(20,15));
	s.insert(make_pair(20,20));
	s.insert(make_pair(20,30));
	s.insert(make_pair(20,31));
	s.insert(make_pair(30,35));
	s.insert(make_pair(30,40));

	s.erase(make_pair(20,20));

	auto it = s.lower_bound(make_pair(20,30));
	cout<<it->first<<" "<<it->second<<endl<<endl;

	it = s.upper_bound(make_pair(20,30));
	cout<<it->first<<" "<<it->second<<endl<<endl;

	for(auto it:s){
		cout<<it.first<<" "<<it.second<<endl;
	}
	return 0;
}