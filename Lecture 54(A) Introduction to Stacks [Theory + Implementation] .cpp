#include<iostream>
#include<stack>
using namespace std;

class Stack{
	int top;
	int *array;
	int size;
	public:
	Stack(int size){
		this->size = size;
		array = new int[size];
		top = -1;
	}
	void push(int element){
		
		if(size - top <= 1){
			cout<<"stack overflow"<<endl;
			return;
		}
        
        
    	top++;
    	arr[top] = x;
    
	}
	int pop(){
		if(top == -1){
			cout<<"Stack underflow"<<endl;
			return -1;
		}
        
        
    	int element = arr[top];
    	top--;
    	return element; 
	}
	int peek(){
		
		if(top < 0){
			cout<<"stack is empty"<<endl;
			return -1;
		}
		
		return array[top];
		
	}
	int cize(){
			return top+1;
	}
	
	bool empty(){
		return top == -1;
	}
};

class TwoStacks{
	int size;
	int *arr;
	int top_1;
	int top_2;
	public:
	TwoStacks(){}
	TwoStacks(int size){
		this->size = size;
		arr = new int[size];
		top_1 = -1;
		top_2 = size;
	}
	void push_1(int element){
		if(top_2 - top_1 > 1){
			top_1++;
			arr[top_1] = element;
		}else{
			cout<<"stack 1 is overflow"<<endl;
		}
	}
	void push_2(int element){
		if(top_2 - top_1 > 1){
			top_2--;
			arr[top_2] = element;
		}else{
			cout<<"stack 2 is overflow"<<endl;
		}
	}
	void pop_1(){
		if(top_1 >= 0){
			top_1--;
		}else{
			cout<<"stack 1 is underflow"<<endl;
		}
	}
	void pop_2(){
		if(top_2 < size){
			top_2++;
		}else{
			cout<<"stack 2 underflow"<<endl;
		}
	}
	int peek_1(){
		if(top_1 >= 0)
			return arr[top_1];
		cout<<"stack 1 is empty"<<endl;
		return top_1;
	}
	int peek_2(){
		if(top_2 < size)
			return arr[top_2];
		cout<<"stack 2 is empty"<<endl;
		return -1;
	}
	bool empty_1(){
		if(top_1 < 0)
			return true;
		return false;		
	}
	bool empty_2(){
		if(top_2 >= size)
			return true;
		return false;
		
	}
	
};

int main(){
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

//	Q: insert two stacks in an array

	TwoStacks* s2 = new TwoStacks(5);
	s2->push_1(1);
	s2->push_1(2);
	s2->push_2(5);
	s2->push_2(4);
	s2->pop_2();
	s2->pop_2();
	cout<<s2->empty_2();

	return 0;
}
