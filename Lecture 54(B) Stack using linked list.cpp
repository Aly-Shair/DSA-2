#include<iostream>
using namespace std;

class Node{
	
	public:
	int data;
	Node* next;
	
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};

Node* insertAtTail(Node* &head, int val){
	Node* n = new Node(val);
	if(head == NULL){
		head = n;
		return head;
	}
	Node* temp = head;
	while(temp->next != NULL){
		
		temp = temp->next;
		
	}
	temp->next = n;
	return temp->next;
}
void display(Node* head){
	Node* temp = head;
	while(temp != NULL){
		cout<<temp->data<<"-->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}
class Stack{
	public:
	Node* n;
	Node* head = NULL;
	Node* top = NULL;
	void push(int val){
		top = insertAtTail(head, val);
	}
	int peek(){
		if(top != NULL){
			return top->data;
		}else{
			cout<<"Stack is empty"<<endl;
			return -1;	
		}
	}
	void pop(){
		if(top == NULL){
			cout<<"Stack is empty"<<endl;
			return;
		}
		
		Node* temp = head;
		
		if(temp == top){
			delete temp;
			top = head = NULL;
			return;
		}
		
		while(temp->next != top){
        	temp = temp->next;
    	}
    	
    	Node* toDel = temp->next;
    	temp->next = top->next;
    	top = temp;
    	delete toDel;
	}
	bool empty(){
		if(head == NULL && top == NULL){
			return true;
		}
		return false;
	}
	void display(){
	Node* temp = head;
	while(temp != NULL){
		cout<<temp->data<<"-->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}
	
};
int main(){
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.pop();
	s.pop();
	s.pop();
//	s.pop();
//	s.pop();
	if(s.empty()){
		cout<<"Stack is empty"<<endl;
	}else{
		cout<<"Stack is not empty"<<endl;
	}
//	s.display();
	return 0;
}
