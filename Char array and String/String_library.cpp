#include<bits/stdc++.h>
using namespace std;

int main(){

	string s0;
	string s1("Hello");

	string s2 = s1;

	char a[] = {'h','e','l','l','o','\0'};
	string s3(a);

	cout<<s0<<endl;
	cout<<s1<<endl;
	cout<<s2<<endl;
	cout<<s3<<endl;
	
	if(s0.empty()){
		cout<<"empty string"<<endl;
	}

	//Append
	s3.append("I Love c++");
	cout<<s3<<endl;

	s0 += "I love python";

	cout<<s0<<endl;

	//length
	cout<<s0.length()<<endl;
	//Clear
	s0.clear();
	cout<<s0.length()<<endl;

	//compare lexographical comparison
	s1 = "Apple";
	s2 = "Mango";

	cout<<s1.compare(s2)<<endl;

	//Overloaded operators can be use
	if(s1 > s0){
		cout<<"S1 is lexographically greater"<<endl;
	}

	//Access string element
	cout<<s2[0]<<endl;

	//Find substring
	s0 = "I will buy an apple juice or apple shake";
	int idx = s0.find("apple");
	cout<<idx<<endl;

	//remove 
	string word = "apple";
	s0.erase(idx, word.length()+1);
	cout<<s0<<endl;

	//Iteration
	for(int i=0;i<s0.length();i++){
		cout<<s0[i]<<", ";
	}

	cout<<endl<<"Iterator start"<<endl;

	for(auto it=s0.begin();it!=s0.end();it++){
		cout<<(*it)<<", ";
	}

	cout<<endl<<"for each"<<endl;

	for(char c:s0){
		cout<<c<<", ";
	}

	cout<<endl<<"Using scope resolution operator"<<endl;

	for(string::iterator it=s0.begin();it!=s0.end();it++){
		cout<<(*it)<<", ";
	}






	return 0;
}