#include<bits/stdc++.h>
using namespace std;


int main(){

	vector<int> a;
	vector<int> b(5,10); // 5 int with 10 value
	vector<int> c(b.begin(),b.end());
	vector<int> d{1,2,3,4,5};


	//iterators
	for(int i=0;i<c.size();i++){
		cout<<c[i]<<" ";
	}
	cout<<endl;

	for(vector<int>::iterator it=b.begin();it!=b.end();it++){
		cout<<*(it)<<" ";
	}
	cout<<endl;


	//adding element to the vector -- Push back size
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);
	a.push_back(40);
	a.push_back(50);

	cout<<"b size "<<b.size()<<endl;
	cout<<"b capacity "<<b.capacity()<<endl;
	cout<<"b max size "<<b.max_size()<<endl;


	cout<<"a size "<<a.size()<<endl;
	cout<<"a capacity "<<a.capacity()<<endl;
	cout<<"a max size "<<a.max_size()<<endl;

	for(auto it:a){
		cout<<it<<" ";
	}
	cout<<endl;


	vector<int> v;
	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		int no;
		cin>>no;
		v.push_back(no);
	}

	for(int i=0;i<n;i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}