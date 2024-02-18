#include <bits/stdc++.h>
using namespace std;

class ListNode{
public:
	int val;
	ListNode* next;

	ListNode(int data){
		this->val = data;
		next = NULL;
	}

};

//insert at head
void insertAtHead(ListNode* &head, int data){
	if( head == NULL ){
		head = new ListNode(data);
		return;
	}

	ListNode* temp = new ListNode(data);
	temp->next = head;
	head = temp;
	return;
}

void insertAtTail(ListNode* &head, int data){
	if( head == NULL ){
		insertAtHead(head, data);
		return;
	}

	ListNode* prev = head;
	while(prev->next != NULL){
		prev = prev->next;
	}

	ListNode* temp = new ListNode(data);
	prev->next = temp;
	return;
}

ListNode* input(){
	ListNode* head = NULL;
	int data;
	do{
		cin>>data;
		if(data!=-1){
			insertAtTail(head, data);
		}
	} while(data!=-1);
	return head;
}

void print(ListNode* head){
	while(head != NULL){
		cout<<head->val<<"->";
		head = head->next;
	}
	cout<<endl;
	return;
}

int lengthOfList(ListNode* head){
	int ans = 0;
	while(head != NULL){
		ans++;
		head= head->next;
	}
	return ans;
}

ListNode* deleteAtHead(ListNode* head){
	if(head == NULL){
		return head;
	}
	ListNode* temp = head;
	head = temp->next;
	delete temp;
	return head;
}


ListNode* removeNthFromEnd(ListNode* head, int n){
	if(head == NULL){
		return head;
	}
	int len = lengthOfList(head);
	if(n > len ){
		return head;
	}
	if(len == n){
		return deleteAtHead(head);
	}
	ListNode* prev = head;
	int jumps = len-n;
	while(jumps > 1){
		prev = prev->next;
		jumps--;
	}
	ListNode* curr = prev->next;
	prev->next = curr->next;
	delete curr;
	return head;
}

// ListNode* swapPairs(ListNode* &head){
// 	if(head == NULL){
// 		return head;
// 	}
// 	ListNode* P = head;
// 	ListNode* C = head->next;
// 	ListNode* N;
// 	while(C != NULL){
// 		//save the N as next node 
// 		N = C->next;
// 		//save next node as prev node
// 		C->next = P;
// 		//Save p->next as Next 
// 		P->next = N;
// 		//Increase the pointers
// 		P = C;
// 		C = N;
// 	}
// 	head = P;
// 	return head;
// }

ListNode* swapPairs(ListNode* &head){
	if(head == NULL || head->next == NULL){
		return head;
	}

	ListNode* temp = head;
	


}


int main(){

	ListNode* l1 = input();
	print(l1);
	ListNode* head = swapPairs(head);
	print(head);
	return 0;
}


/*
1 2 3 4 5 

*/
