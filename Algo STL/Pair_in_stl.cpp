#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

int main(){
	pair<int,char> p;
	p.first = 10;
	p.second = 'B';

	pair<int,char> p2(p);

	cout<<p.first<<" "<<p.second<<endl;
	cout<<p2.first<<" "<<p2.second<<endl;

	pair<int,char> p3 = make_pair(20,'C');
	cout<<p3.first<<" "<<p3.second<<endl;

	int no1,no2;
	cin>>no1>>no2;
	pair<int, int> p4 = make_pair(no1,no2);
	cout<<p4.first<<" "<<p4.second<<endl;

	pair<pair<int,int>,string> car;
	car.first.first = 100;
	car.first.second = 200;
	car.second = "Audi";

	cout<<car.first.second<<endl;
	cout<<car.second<<endl;

	return 0;
}