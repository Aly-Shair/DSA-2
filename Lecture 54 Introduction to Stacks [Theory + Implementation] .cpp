#include<iostream>
#include<stack>
using namespace std;

class Stack {
		int top;
		int *array;
		int size;
	public:
		Stack(int size) {
			this->size = size;
			array = new int[size];
			top = -1;
		}
		void push(int element) {
			if(size-top > 1) {
				top++;
				array[top] = element;
			} else {
				cout<<"stack overflow"<<endl;
			}
		}
		void pop() {
			if(top >= 0) {
				top--;
			} else {
				cout<<"stack underflow"<<endl;
			}
		}
		int peek() {
			if(top >= 0) {
				return array[top];
			} else {
				cout<<"stack is empty"<<endl;
				return -1;
			}

		}
		int cize() {
			return top+1;
		}
		bool empty() {
			if(top == -1) {
				return true;
			} else {
				return false;
			}
		}
};



int main() {
	/*
	//	Q: stack using STL
		stack<int>s;
	//	push operation
		s.push(1);
		s.push(2);
	//	pop operation
		s.pop();
	//	top operation
		cout<<s.top()<<endl;
	//	size operation
		cout<<s.size()<<endl;
		if(s.empty()){
			cout<<"stack is empty"<<endl;
		}else{
			cout<<"stack is not empty"<<endl;
		}
	*/
	/*
	//	Q: custom implimentation of stack

	//	Stack s = new Stack(5);
		Stack s(5);
		s.push(1);
		s.push(2);
		cout<<s.peek()<<endl;
		s.pop();
		cout<<s.peek()<<endl;
	//	s.pop();
		if(s.empty()){
			cout<<"stack is empty"<<endl;
		}else{
			cout<<"stack is not empty"<<endl;
		}
		cout<<s.cize();
	*/



	return 0;
}
