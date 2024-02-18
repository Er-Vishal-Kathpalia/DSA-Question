#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node*next;

	node(int d){
		data = d;
		next = NULL;
	}
};

//Procedural Programming
void insertAtHead(node*&head, int data){

	if(head == NULL){
		head = new node(data);
		return;
	}

	node *temp = new node(data);
	temp->next = head;
	head = temp;
	return;
}


void print(node*head){
	
	while(head!=NULL){
		cout<<head->data<<"-> ";
		head = head->next;
	}
	cout<<endl;
}


//Take input through method
node* input_At_Head(){
	node*head = NULL;
	int d;
	cin>>d;
	while(d != -1){
		insertAtHead(head, d);
		cin>>d;
	}

	return head;
}

//Cout operator overloading
ostream& operator<<(ostream &os,node*head){
	print(head);
	return os;
}

//Cin Operator overloading
istream& operator>>(istream &is, node* &head){
	head = input_At_Head();
	return is;
}


void reverseLinkedList(node*&head){
	node* C = head;
	node* P = NULL;
	node* N;

	while(C != NULL){
		//save the next node
		N = C->next;
		//make the current node point to prev
		C->next = P;

		//Update P and C take them 1 step forword
		P = C;
		C = N;
	}
	head = P;
}

node* recursiveReverse(node*&head){

	//smallest linked list
	if(head->next == NULL || head==NULL){
		return head;
	}

	node* sHead = recursiveReverse(head->next);

	node* temp = sHead;
	while(temp->next != NULL){
		temp = temp->next;
	}
	head->next = NULL;
	temp->next = head;
	return sHead;
}


node* recursiveReverseOptimized(node*&head){

	//smallest linked list
	if(head->next == NULL || head==NULL){
		return head;
	}

	node* sHead = recursiveReverse(head->next);

	node* temp = head->next;
	head->next = NULL;
	temp->next = head;
	return sHead;
}


int main(){

	node* head;
	cin>>head;
	cout<<head<<endl;
	head = recursiveReverseOptimized(head);
	cout<<head<<endl;

	return 0;
}