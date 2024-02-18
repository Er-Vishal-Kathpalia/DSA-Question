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

int replaceSum(node* root){

	if(root == NULL){
		return 0;
	}

	if(root->left == NULL && root->right == NULL){
		return root->data;
	}

	int leftSum = replaceSum(root->left);
	int rightSum = replaceSum(root->right);

	int temp = root->data;
	root->data = leftSum+rightSum;
	return temp+root->data;
}

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

int main(){

	node* root = buildTree();
	bfs(root);
	cout<<endl;
	replaceSum(root);

	bfs(root);
	cout<<endl;
	return 0;
}