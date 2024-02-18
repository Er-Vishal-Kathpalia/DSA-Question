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

node* buildTree(node* &root){
	int d;
	cin>>d;

	if(d == -1){
		return NULL;
	}

	root = new node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}


int main(){

	node* head;
	cin>>head;

	cout<<root;

	return 0;
}