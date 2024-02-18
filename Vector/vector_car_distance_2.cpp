#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Car{
public:
	string car_name;
	int x,y;

	Car(){
	}

	Car(string name, int x, int y){
		car_name = name;
		this->x = x;
		this->y = y;
	}

	int dist(){
		return (x*x)+(y*y);
	}
};

bool compare(Car A,Car B){
	int da = A.dist();
	int db = B.dist();
	if( da == db ){
		return A.car_name.length() < B.car_name.length();
	}
	return da<db;

}


int main(){

	int n;
	cin>>n;
	vector<Car> cars;
	for(int i=0;i<n;i++){
		string name;
		int x,y;
		cin>>name>>x>>y;
		Car temp(name,x,y);
		cars.push_back(temp);
	}

	sort(cars.begin(),cars.end(),compare);

	for(auto itr: cars){
		cout<<"Car "<<itr.car_name<<" Distance: "<<itr.dist()<<" Location: "<<itr.x<<", "<<itr.y<<endl;
	}
	

	return 0;
}