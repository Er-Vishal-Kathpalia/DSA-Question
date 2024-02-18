#include<bits/stdc++.h>
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

node* insertInBst(node*root, int data){

	//base case
	if(root == NULL){
		return new node(data);
	}

	if(data<=root->data){
		root->left = insertInBst(root->left,data);
	} else{
		root->right = insertInBst(root->right,data);
	}

	return root;
}


node* build(){
	int d;
	cin>>d;

	node* root = NULL;
	while(d!=-1){
		root = insertInBst(root,d);
		cin>>d;
	}
	return root;
}

bool checkBST(node* root, int minV = INT_MIN, int maxV = INT_MAX){

	if(root == NULL){
		return true;
	}

	if( root->data >= minV && root->data<=maxV && checkBST(root->left,minV, root->data) && checkBST(root->right,root->data, maxV)){
		return true;
	}

	return false;
}

int main(){

	node* root = build();

	if( checkBST(root) ){
		cout<<"BST"<<endl;
	}
	else{
		cout<<"Not BST"<<endl;
	}

	return 0;
}