// https://www.geeksforgeeks.org/problems/queue-reversal/1
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverse(queue<int> &q) {
	if(q.empty()){
		return;
	}
	int curr = q.front();
	q.pop();
	reverse(q);
	q.push(curr);
}

queue<int> Reverse(queue<int> q){
	stack<int> s;
	while(!q.empty()){
		int element = q.front();
		q.pop();
		s.push(element);
	}
	while(!s.empty()){
		int element = s.top();
		q.push(element);
		s.pop();
	}
	return q;
}

void display(queue<int> q) {
	while(!q.empty()) {
		cout<<q.front()<<" ";
		if(!q.empty()){
			q.pop();		
		}
	
	}cout<<endl;
}

int main() {
	/*
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	display(q);
	reverse(q);
	display(q);
	*/
	
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	display(q);
	queue<int> q2 = Reverse(q);
	display(q2);
	
	return 0;
}
