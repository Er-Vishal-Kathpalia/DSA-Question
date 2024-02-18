#include <iostream>
#include <cstring>
#include "hashTable.h"
using namespace std;



int main(){
	HashTable<int> price_menu;

	price_menu.insert("Burger", 50);
	price_menu.insert("Pepsi", 100);
	price_menu.insert("Noodles", 150);
	price_menu.insert("Juice", 161);
	price_menu.insert("Coke", 91);
	price_menu.insert("BurgerPizza", 200);

	price_menu.print();

	string key;
	cin>>key;

	auto val = price_menu.search(key);
	if(val==NULL){
		cout<<key<<" not found!!"<<endl;
	} else{
		cout<<key<<" has value "<<*val<<endl;
	}

	price_menu.erase("Pepsi");

	price_menu.print();


	price_menu["Dosa"] = 60;
	price_menu["Dosa"] += 10;

	cout<<"Price of Dosa is "<<price_menu["Dosa"]<<endl;
	return 0;
}