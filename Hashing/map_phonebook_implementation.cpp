#include<iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

int main(){

	unordered_map<string,vector<string> > phoneBook;


	phoneBook["Vishal"].push_back("91191");
	phoneBook["Vishal"].push_back("92391");
	phoneBook["Vishal"].push_back("92191");
	phoneBook["Vishal"].push_back("95191");

	phoneBook["Puneet"].push_back("83191");
	phoneBook["Puneet"].push_back("82191");
	phoneBook["Puneet"].push_back("89191");

	for(auto name:phoneBook){
		cout<<name.first<<"'s phone no are ";
		for(string x:name.second){
			cout<<x<<", ";
		}
		cout<<endl;
	}

	string name;
	cin>>name;

	if(phoneBook.count(name) == 0){
		cout<<"Absent"<<endl;
	} else{
		for(auto x:phoneBook[name]){
			cout<<x<<", ";
		}
		cout<<endl;
	}

	return 0;
}