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

class Pair{
public:
	int maxSum;
	int branchSum;

	Pair(){
		maxSum = 0;
		branchSum = 0;
	}
};

Pair maxSumPath(node* root){
	Pair p;
	
	if(root == NULL){
		return p;
	}

	Pair left = maxSumPath(root->left);
	Pair right = maxSumPath(root->right);

	//construct two values
	int op1 = root->data;
	int op2 = left.branchSum + root->data;
	int op3 = right.branchSum + root->data;
	int op4 = left.branchSum + right.branchSum + root->data;

	int current_ans_through_root = max(op1, max(op2, max(op3, op4)));

	//branch sum of current root
	p.branchSum = max(left.branchSum, max(right.branchSum,0))+root->data;
	p.maxSum = max(left.maxSum, max(right.maxSum, current_ans_through_root));
	return p;

}

//8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 -14 -13 -1 -1 -1


int main(){

	node* root = buildTree();
	Pair ans = maxSumPath(root);
	cout<<ans.maxSum<<endl;

	return 0;
}