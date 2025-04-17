#include<iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* next;
		Node(int data) {
			this->data = data;
			this->next = NULL;
		}
};

void insertAtTail(Node* &head, int val) {
	Node* n = new Node(val);
	if(head == NULL) {
		head = n;
		return;
	}
	Node* temp = head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = n;
}

void display(Node* head) {
	while(head != NULL) {
		cout<<head->data<<"-->";
		head = head->next;
	}
}

class DQueue {

	public:

		Node* front = NULL;
		Node* end = NULL;
		Node* head = NULL;

		void push_back(int val) {
			Node* n = new Node(val);
			if(head == NULL) {
				front = end = head = n;
				return;
			}
			/*
			Node* temp = head;
			while(temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = n;
			*/
			end->next = n;
			end = n;
		}
		
		void push_front(int val){
			Node* n = new Node(val);
			n->next = head;
			head = n;
			front = n;
		}
		
		void pop_back(){ // use doubly linked list to make it of O(1)
			if(head == NULL){
				cout<<"Queue is empty"<<endl;
				return;
			}
			Node* temp = head;
			if(temp->next == NULL){
				delete temp;
				head = NULL;
				front = NULL;
				end = NULL;
				return;
			}
			while(temp->next->next != NULL){
				temp = temp->next;
			}
			Node* toDel = temp->next;
			temp->next = temp->next->next;
			end = temp;
			delete toDel;
			
		}
		
		void pop_front(){
			if(head == NULL){
				cout<<"Queue is empty"<<endl;
				return;
			}
			Node* toDel = head;
			front = head = head->next;
			delete toDel;
		}
		
		void display() {
			while(head != NULL) {
				cout<<head->data<<"-->";
				head = head->next;
			}
			cout<<"NULL"<<endl;
		}
		bool isEmpty(){
			if(head == NULL)
				return true;
			else
				return false;
		}
		int Front(){
			if(front == NULL){
				cout<<"Queue is empty"<<endl;
				return 0;	
			}
			else
				return front->data;
		}
		int Back(){
			if(end == NULL){
				cout<<"Queue is empty"<<endl;
				return 0;	
			}
			else
				return end->data;
		}
};

int main() {
	DQueue d;
	
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(4);
	d.push_back(5);
	/*
	d.push_front(1);
	d.push_front(2);
	d.push_front(3);
	d.push_front(4);
	d.push_front(5);
	*/
	

//	d.pop_front();
	
	d.display();
	cout<<d.Front()<<endl;
	cout<<d.Back()<<endl;
	return 0;
}
