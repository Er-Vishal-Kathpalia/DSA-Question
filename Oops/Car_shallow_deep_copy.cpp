#include<bits/stdc++.h>
using namespace std;

//access specifier -- public and private 
//defining a new data type

/*
- Some Special Functions that C++ Classes give you when you a create a class/object. 
- 4 different special fns that are always present inside a class.

1. Constructor
	- that is responsible for creating an object 
	- gets called automatically and only once.
	- same name as class name
 - parametrised constructor
 - Constructor overloading
2. Copy Constructor
 - make a copy of existing constructor.
 - when you need to define your own copy constructor.
 - Shallow copy
 - You have make your own copy constructor if a deep copy is needed.
3. Copy Assignment Operator 
4. Destructor
*/

class Car{

private:
	float price; //only access within the class

public:
	int model_no;
	char *name;

	Car(){
		cout<<"Inside car Constructor"<<endl; //Constructor
	}

	//shallow copy
	Car(float p, int m, char *n){
		cout<<"Inside parametrised Constructor"<<endl;  //shallow copy
		price = p;
		model_no = m;
		name = new char[strlen(n)+1];
		strcpy(name,n);
	}

	//deep copy
	Car(Car &x){
		price = x.price;
		model_no = x.model_no;
		name = new char[strlen(x.name)+1];
		strcpy(name,x.name);
	}

	void print(){
		cout<<"Name is "<<name<<endl;
		cout<<"Model is "<<model_no<<endl;
		cout<<"Price is "<<price<<endl;
	}

};


int main(){

	Car c(10.1,111,"BMW");

	Car d(c);

	d.name[0] = 'A';

	d.print();
	c.print();

	return 0;
}