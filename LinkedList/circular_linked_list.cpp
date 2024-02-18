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

//insert at head
void insertAtHead(node*&head, int data){
	
	node* n = new node(data);
	n->next = head;

	node* temp = head;
	if(head != NULL){

		while(temp->next!=head){
			temp = temp->next;
		}
		temp->next = n;

	} else{
		n->next = n;
	}
	head = n;
}

//print
void print(node*head){

	node* temp = head;
	while(temp->next != head){
		cout<<temp->data<<"-> ";
		temp = temp->next;
	}
	cout<<temp->data<<endl;
	return;
}

//search
node* search(node*head, int key){
	
	node* temp = head;
	while(temp->next != head){
		if(temp->data == key){
			return temp;
		}
		temp = temp->next;
	}
	if(temp->data == key){
		return temp;
	}
	return NULL;
}

//Deletion
void deleteAtHead(node*&head, int data){
	
	node* del = search(head,data);
	if(del == NULL){
		return;
	}

	if(head == del){
		head = head->next;
	}

	node* prev = head;
	while(prev->next != del){
		prev = prev->next;
	}

	prev->next = del->next;
	delete del;

}

int main(){

	node* head = NULL;
	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);
	print(head);

	deleteAtHead(head, 50);
	print(head);

	deleteAtHead(head, 10);
	print(head);

	return 0;
}