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

//Linked Class (Object Oriented)
/*class LinkedList{
	node*head;
	node*tail;
	public:
		LinkedList(){
			//
		}

		void insert(){
			//...
		}
		//...
};
*/

//Procedural Programming
void insertAtHead(node*&head, int data){

	//Insert First element
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

int length(node*head){
	int len = 0;
	while(head!=NULL){
		len++;
		head = head->next;
	}
	return len;
}

void insertAtTail(node*&head,int data){
	if(head == NULL){
		insertAtHead(head,data);
		return;
	}

	node*tail = head;
	while(tail->next != NULL){
		tail = tail->next;
	}

	tail->next = new node(data);
	return;
}


void insertAtMiddle(node*&head, int data, int p){

	if(head == NULL || p == 0){
		insertAtHead(head,data);
		return;
	} else if( p > length(head) ){
		insertAtTail(head,data);
	} else{
		int jump = 1;
		node*temp = head;
		while(jump <= p-1){
			temp = temp->next;
			jump++;
		}

		node *n = new node(data);
		n -> next = temp->next;
		temp->next = n;
	}
	return;
}


void deleteAtHead(node*&head){
	if(head == NULL){
		return;
	}

	node*prev = head->next;
	delete head;
	head = prev;
}


void deleteAtTail(node*&head){
	if(head == NULL || head->next == NULL){
		deleteAtHead(head);
		return;
	}
	node*prev = head->next;
	while(prev->next->next!=NULL){
		prev = prev->next;
	}
	node*current = prev->next->next;
	delete current;
	prev->next = NULL;
}

// void insertAtMiddle(Node* &head, int data, int idx){
// 	int len = lengthOfList(head);
// 	if( head == NULL || idx == 0 ){
// 		insertAtHead(head, data);
// 	} else if( len < idx ){
// 		insertAtTail(head, data);
// 	} else{
// 		Node* prev = head;
// 		int i=1;
// 		while(i < idx-1){
// 			prev = prev->next;
// 			i++;
// 		}
// 		Node* temp = new Node(data);
// 		temp->next = prev->next;
// 		prev->next = temp;
// 	}
// 	return;
// }

bool searchInLinkedList(node*head, int key){
	while(head!=NULL){
		if(head->data == key){
			return true;
		}
		head = head->next;
	}
	return false;
}


bool searchRecursively(node*head, int key){
	//base case
	if(head == NULL){
		return false;
	}

	if(head->data == key){
		return true;
	} else{
		return searchRecursively(head->next, key);
	}
}



node* input(){

	node*head = NULL;
	int d;
	cin>>d;
	while(d != -1){
		insertAtHead(head, d);
		cin>>d;
	}

	return head;
}


int main(){

	node* head = input();
	// node* head = NULL;
	// insertAtHead(head,60);
	// insertAtHead(head,50);
	// insertAtHead(head,30);
	// insertAtHead(head,20);
	// insertAtHead(head,10);

	// insertAtMiddle(head,40,3);


	// insertAtTail(head,100);
	cout<<"Print LL "<<endl;
	print(head);

	deleteAtMiddle(head, 4);

	cout<<"Print LL2 "<<head<<endl;
	print(head);
	int key;
	cin>>key;

	if(searchRecursively(head,key)){
		cout<<"Found element in LL"<<endl;
	}

	return 0;
}