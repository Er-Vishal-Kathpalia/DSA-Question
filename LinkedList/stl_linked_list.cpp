#include<iostream>
#include<list>
using namespace std;


int main(){


	list<int> l;
	list<string> l2{"apple","guava","mango","banana"};
	l2.push_back("pineapple");

	//sort
	l2.sort();

	//reverse
	l2.reverse();

	//pop_front
	cout<<l2.front()<<endl;
	l2.pop_front();

	//add to front
	l2.push_front("kiwi");
	cout<<l2.back()<<endl;
	l2.pop_back();

	//Iterate through list and print data
	for(auto itr=l2.begin();itr!=l2.end();itr++){
		cout<<(*itr)<<" -> ";
	}
	cout<<endl;
	

	//some more functions in list
	l2.push_back("orange");
	l2.push_back("guava");
	
	for(auto s:l2){
		cout<<s<<"--> ";
	}
	cout<<endl;


	string f;
	cin>>f;

	//remove from the list
	l2.remove(f);

	//erase element at idx
	auto it = l2.begin();
	it++;
	it++;

	l2.erase(it);

	//insert elemenet in middle
	it = l2.begin();
	it++;
	l2.insert(it,"orangeJuice");

	//print
	for(auto s:l2){
		cout<<s<<"--> ";
	}
	cout<<endl;
	return 0;
}