#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* next;
	node(int data){
		this->data = data;
		next=NULL;
	}
};


void print(node* head){

	while(head!=NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;
}

void insertAtHead(node* &head, int key){
	if(head == NULL){
		head = new node(key);
		return;
	}
	node* temp = new node(key);
	temp->next = head;
	head = temp;
	return;
}

void insertAtTail(node* head, int key){
	if(head == NULL){
		insertAtHead(head,key);
	}
	node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = new node(key);
	return;
}

void reverse(node* &head, node* cur){
	if(cur==NULL || cur->next==NULL){
		return;
	}
	node* curr = cur;
	node* nxt = cur->next;
	node* nxtToNext = cur->next->next;

	cur->next->next = head;
	cur->next = nxtToNext;
	head = nxt;
	reverse(head,cur);
}


int main(){

	node* head=NULL;
	insertAtHead(head,10);
	insertAtHead(head,20);
	insertAtHead(head,30);
	insertAtTail(head,50);
	insertAtTail(head,100);
	print(head);
	cout<<"Calling reverse"<<endl;
	reverse(head,head);
	print(head);
	return 0;
}