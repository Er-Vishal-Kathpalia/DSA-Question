#include<bits/stdc++.h>
using namespace std;

class DSU{
	int V;
	vector<int> parent;
public:
	DSU(int V){
		this->V = V;
		parent.reserve(V);
		for(int i=0;i<=V;i++){
			parent[i] = -1;
		}
	}

	int find(int i){
		if( parent[i] == -1){
			return i;
		}
		return find(parent[i]);
	}


	void Union( int a, int b ){
		int s1 = find(a);
		int s2 = find(b);
		if( s1 != s2 ){
			parent[a] = b;
		}
		return;
	}

	void print(){
		for(int i=0;i<=V;i++){
			cout<<parent[i]<<" ";
		}
		cout<<endl;
	}

};


int main(){

	DSU d(4);

	d.Union(1,2);
	d.Union(3,4);
	d.Union(1,4);
	d.Union(2,3);

	d.print();

	return 0;
}