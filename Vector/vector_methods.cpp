#include<bits/stdc++.h>
using namespace std;


int main(){

	vector<int> d{1,2,3,4,5};
	//push back O(1)
	d.push_back(10);

	//pop back O(1)
	d.pop_back();

	//insert some element in the middle
	d.insert(d.begin()+3,5,100);

	//erase some element in the middle
	d.erase(d.begin()+0);
	//remove 1 and 2
	d.erase(d.begin()+1,d.begin()+3);

	//size and capacity O(N);
	cout<<d.size()<<endl;
	cout<<d.capacity()<<endl;

	//we usually avaoid the shrink
	cout<<"After Resizing "<<endl;
	d.resize(8); //if the size is increasing more will be the memory allocated
	cout<<d.size()<<endl;
	cout<<d.capacity()<<endl;

	//clear the vector
	d.clear();

	//check empty
	if(d.empty()){
		cout<<"Vector is empty"<<endl;
	}

	d.push_back(10);
	d.push_back(20);
	d.push_back(30);

	// //front and back element
	cout<<d.front()<<endl;
	cout<<d.back()<<endl;

	for(auto x:d){
		cout<<x<<" ";
	}
	cout<<endl;

	int n;
	cin>>n;
	vector<int> arr;
	//To avoid the doubling of vector we use reserve
	arr.reserve(1000);

	for(int i=0;i<n;i++){
		int no;
		cin>>no;
		arr.push_back(no);
		cout<<"capacity increasing "<<arr.capacity()<<endl;
	}

	cout<<"capacity "<<arr.capacity()<<endl;
	for(auto x:arr){
		cout<<x<<" ";
	}

	return 0;
}