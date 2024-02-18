#include <bits/stdc++.h>
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

class Pair{
public:
	int height;
	int diameter;
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

int height(node* root){
	if(root == NULL){
		return 0;
	}

	int l = height(root->left);
	int r = height(root->right);
	return max(l,r)+1;
}

int diameterOfTree(node* root){
	
	if(root==NULL){
		return 0;
	}

	int h1 = height(root->left);
	int h2 = height(root->right);
	int op1 = h1+h2;
	int op2 = diameterOfTree(root->left);
	int op3 = diameterOfTree(root->right);

	return max(op1,max(op2,op3));
}

Pair fastDiameter(node* root){
	Pair pair;
	if(root==NULL){
		pair.height = pair.diameter = 0;
		return pair;
	}

	Pair left = fastDiameter(root->left);
	Pair right = fastDiameter(root->right);
	pair.height = max(left.height,right.height)+1;
	pair.diameter = max( left.height+right.height , max(left.diameter,right.diameter) );
	return pair;
}

int main(){

	node* root = buildTree();
	cout<<diameterOfTree(root)<<endl;

	Pair pair = fastDiameter(root);
	cout<<"Height is "<<pair.height<<" and diameter is "<<pair.diameter<<endl;
	return 0;
}