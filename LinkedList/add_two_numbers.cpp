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

	while(head!=NULL){
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

/*
9,9,9,9,9,9,9
9,9,9,9





*/
ListNode* traverse(ListNode* l1, ListNode* l2){
	ListNode* head = NULL;
	if(l1 == NULL){
		return l2;
	}
	if(l2 == NULL){
		return l1;
	}
	int carry = 0;
	while(l2 != NULL){
		int sum = l1->val + l2->val + carry;
		if(sum > 9){
			int digit = sum%10;
			insertAtTail(head, digit);
			carry = 1;
		} else{
			int digit = sum%10;
			insertAtTail(head, digit);
			carry = 0;
		}
		l2 = l2->next;
		l1 = l1->next;
	}

	while(l1 != NULL){
		int sum = l1->val + carry;
		if(sum > 9){
			int digit = sum%10;
			insertAtTail(head, digit);
			carry = 1;
		} else{
			int digit = sum%10;
			insertAtTail(head, digit);
			carry = 0;
		}
		l1 = l1->next;
	}
	if( carry > 0 ){
		insertAtTail(head, carry);
	}
	return head;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
	int len1 = lengthOfList(l1);
	int len2 = lengthOfList(l2);
	if( len1 >= len2 ){
		return traverse(l1, l2);
	}
	return traverse(l2, l1);;
}

int main(){

	ListNode* l1 = input();
	ListNode* l2 = input();
	print(l1);
	print(l2);
	ListNode* head = addTwoNumbers(l1, l2);
	print(head);
	return 0;
}