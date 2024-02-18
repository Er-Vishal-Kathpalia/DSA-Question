#include<iostream>
#include <cstring>
#include <unordered_map>
using namespace std;


class node{
public:
	int data;
	node*left;
	node*right;

	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

void verticleOrderPrint(node* root, int d, unordered_map<int, vector<int> > &m){

	if(root==NULL){
		return;
	}

	m[d].push_back(root->data);
	verticleOrderPrint(root->left,d-1,m);
	verticleOrderPrint(root->right,d+1,m);
	return;
}

int main(){

	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);

	root->left->left->left = new node(8);
	root->left->right->right = new node(9);
	root->right->right->left = new node(10);


	unordered_map<int, vector<int> > m;
	int d = 0;
	verticleOrderPrint(root, d, m);

	for(auto it:m){
		// cout<<"Position "<<it.first<<endl;
		for(int x:it.second){
			cout<<x<<", ";
		}
		cout<<endl;
	}

	return 0;
}