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

void bfs(node *root){
	//base case
	if(root== NULL){
		return;
	}
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* d = q.front();
		if(d == NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		} else {
			cout<<d->data<<" ";
			q.pop();
			
			if(d->left!=NULL){
				q.push(d->left);
			}

			if(d->right!=NULL){
				q.push(d->right);
			}
		}
	}
}

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

node* lca(node* root, int a,int b){

	if(root==NULL){
		return NULL;
	}

	if(root->data==a || root->data==b){
		return root;
	}

	node* leftans = lca(root->left,a,b);
	node* rightans = lca(root->right,a,b);

	if(leftans!=NULL && rightans!=NULL){
		return root;
	}

	if(leftans!=NULL){
		return leftans;
	}
	return rightans;
}


int main(){

	node* root = buildTree();
	int a = 1;
	int b = 7;
	cout<<"lca of "<<a<<" and "<<b<<" are "<<lca(root,a,b)->data<<endl;
	a = 13;
	b = 3;
	cout<<"lca of "<<a<<" and "<<b<<" are "<<lca(root,a,b)->data<<endl;

	return 0;
}