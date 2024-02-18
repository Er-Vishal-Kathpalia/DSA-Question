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
	char name[20];

	Car(){
		cout<<"Inside car Constructor"<<endl; //Constructor
	}

	Car(float p, int m, char *n){
		cout<<"Inside parametrised Constructor"<<endl;  //parametrised constructor
		price = p;
		model_no = m;
		strcpy(name,n);
	}

	Car(float p){
		cout<<"Inside price parametrised Constructor"<<endl; //Constructor overloading
		price = p;
	}

	Car(Car &x){
		cout<<"Copy Constructor is written like this"<<endl;
		price = x.price;
		model_no = x.model_no;
		strcpy(name,x.name);
	}

	void print(){
		cout<<"Name is "<<name<<endl;
		cout<<"Model is "<<model_no<<endl;
		cout<<"Price is "<<price<<endl;
	}

	float get_discounted_price(float x){
		return price*(1.0 - x);
	}

	float applied_discount(float x){
		price = price*(1.0-x);
		return price;
	}

	void set_price(float p){ //setters
		float msp = 1111;
		if(p>msp){
			price = p;
		} else{
			price = msp;
		}
	}

	float get_price(){ //Getters
		return price;
	}

};


int main(){

	Car c,d;
	Car f(10.1,111,"Audi");

	f.print();

	c.model_no = 2017;
	c.name[0] = 'B';
	c.name[1] = 'M';
	c.name[2] = 'W';
	c.name[3] = '\0';

	Car e(d);
	//another way of calling copy constructor
	Car xyz = c;

	e.print();

	//try to print
	// cout<<"Name: "<<c.name<<" Model No: "<<c.model_no<<" Price: "<<c.price<<endl;
	//c.price = 100; -- can't be able to acces the data member bcz of private method.

	cout<<"Enter the discount you want to give";
	float discount;
	cin>>discount;

	cout<<c.get_discounted_price(discount);

	c.set_price(101);
	cout<<c.get_price()<<endl;

	c.print();

	return 0;
}