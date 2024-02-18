#include <iostream>
#include"Vector.h"
using namespace std;


int main(){

	Vector<int> v;
	v.push_back(10);
	v.push_back(21);
	v.push_back(24);
	v.push_back(26);

	cout<<"capacity "<<v.capacity()<<endl;

	v.pop_back();

	v.push_back(100);
	v.push_back(109);
	v.push_back(210);

	cout<<"capacity "<<v.capacity()<<endl;

	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;

	cout<<v.front()<<endl;
	cout<<v.back()<<endl;
	
	cout<<v[5]<<endl;
	cout<<v.at(5)<<endl;
	
	return 0;
}