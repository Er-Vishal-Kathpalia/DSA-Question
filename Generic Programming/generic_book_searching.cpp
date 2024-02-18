#include<bits/stdc++.h>
using namespace std;

class Book{
public:
	char *name;
	float price;

	Book(){
	}

	Book(char *name, float price){
		this->name = name;
		this->price = price;
	}
};

class BookToCompare{
public:
	bool operator()(Book A, Book B){
		if(A.name == B.name){
			return true;
		}
		return false;
	}
};

//Templates+Iterators+Comparators
template<class ForwardIterator,class T, class Compare>
ForwardIterator search(ForwardIterator start,ForwardIterator end,T key,Compare cmp){
	while(start!=end){
		if(cmp(*start,key)){
			return start;
		}
		start++;
	}
	return end;

} 

int main(){

	Book b1("C++",100);
	Book b2("Python",120);
	Book b3("Java",150);

	list<Book> l;
	l.push_back(b1);
	l.push_back(b2);
	l.push_back(b3);

	Book bookToFind("C",190);

	BookToCompare cmp;

	auto it = search(l.begin(),l.end(),bookToFind,cmp);

	if(it == l.end()){
		cout<<"Book Not found"<<endl;
	} else{
		cout<<"Book Found"<<endl;
	}
	return 0;
}