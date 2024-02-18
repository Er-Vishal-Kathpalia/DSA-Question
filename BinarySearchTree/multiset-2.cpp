#include <iostream>
#include <set>
using namespace std;


//make a compare class and then sort it with operator overloading to sort on the basis
//of second element.
class set_compare{
public:

	bool operator()(pair<string, int> p1,pair<string, int> p2){
		return p1.second < p2.second;
	}
};



int main(){

	pair<string, int> p1 = make_pair("C",100);
	pair<string, int> p2 = make_pair("F",10);
	pair<string, int> p3 = make_pair("B",20);
	pair<string, int> p4 = make_pair("K",50);
	pair<string, int> p5 = make_pair("A",90);
	pair<string, int> p6 = make_pair("X",35);

	multiset<pair<string, int>, set_compare > m;

	m.insert(p1);
	m.insert(p2);
	m.insert(p3);
	m.insert(p4);
	m.insert(p5);
	m.insert(p6);

	//By default multiset will be sorted on the basis of first element.
	for(auto it:m){
		cout<<it.first<<" - "<<it.second<<endl;
	}

	return 0;
}