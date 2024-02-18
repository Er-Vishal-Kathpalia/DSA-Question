#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};


node* buildTree(){
	int d;
	cin>>d;

	if(d == -1){
		return NULL;
	}

	node* root = new node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

void rightView(node* root, int level, int &maxLevel){
	if(root == NULL){
		return;
	}
	//Set maxlevel from level
	//See if level is greater than maxLevel then print
	if( maxLevel<level){
		cout<<root->data<<" ";
		maxLevel = level;
	}
	rightView(root->right,level+1,maxLevel);
	rightView(root->left,level+1,maxLevel);
	return;
}

int main(){

	node* root = buildTree();
	int level = 0;
	int maxLevel = -1;
	rightView(root,level,maxLevel	);


	return 0;
}