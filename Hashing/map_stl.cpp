#include<iostream>
#include <map>
using namespace std;


int main(){

	map<string,int> m;

	//1. Insert
	m.insert(make_pair("Mango",100));

	pair<string,int> p;
	p.first = "Pineapple";
	p.second = 50;

	m.insert(p);

	m["Banana"] = 80;


	//2. Search
	string fruit;
	cin>>fruit;
	//update the price
	m["Banana"] += 22;

	cout<<"Price of "<<fruit<<" is "<<m[fruit]<<endl;

	//find for searching
	auto it = m.find(fruit);
	if(it!=m.end()){
		cout<<"Price of "<<fruit<<" is "<<m[fruit]<<endl;
	} else{
		cout<<"Not found"<<endl;
	}

	//Erase
	m.erase(fruit);

	if(m.count(fruit)){
		cout<<"Price is "<<m[fruit]<<endl;
	} else{
		cout<<"Couldn't found"<<endl;
	}

	m["Litchi"] = 300;
	m["Kiwi"] = 1000;

	cout<<"Fruits are"<<endl;

	for(map<string, int>::iterator it=m.begin();it!=m.end();it++){
		cout<<it->first<<" : "<<it->second<<endl;
	}

	cout<<"Fruits are"<<endl;

	for(auto it: m){
		cout<<it.first<<" "<<it.second<<endl;
	}


	return 0;
}