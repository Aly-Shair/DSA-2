#include<iostream>
#include<queue>
using namespace std;
/*

Questions Links:
	Queue Implementation:https://bit.ly/3uL7QDG
	Circular Queue :https://bit.ly/34xocVZ
	Doubly Ended Queue Implementation:https://bit.ly/3JoEvmF

*/

/*
	Normal queue
	Circular queue
	Input restricted queue
	Output restricted queue
	Doubly ended queue
*/

/*
#include <bits/stdc++.h>
class Queue {
    int* arr;
    int size;
    int qfront, rear;
public:

    Queue() {
        size = 1000;
        arr = new int[size];
        qfront = rear = 0;
    }

    bool isEmpty() {
       if(qfront == rear)
            return true;
        else
            return false;
    }

    void enqueue(int data) {
        if(rear == size)
            return;
       arr[rear] = data;
       rear++;
    }

    int dequeue() {
        if(isEmpty())
            return -1;
        int element = arr[qfront];
        arr[qfront] = -1;
        qfront++;
        if(qfront == rear){
            qfront = rear = 0;
        }
        return element;
    }

    int front() {
        if(!isEmpty()){
            return arr[qfront];
        }else{
            return -1;
        }
    }
};
*/
class Queue {
		int front;
		int rear;
		int* arr;
		int size;
	public:
		Queue() {
			size = 5;
			arr = new int[size];
			front = 0;
			rear = 0;
		}
		void push(int n) {
			if(rear == size) {
				cout<<"queue is full"<<endl;
			} else {
				arr[rear] = n;
				rear++;
			}
		}
		void pop() {
			if(rear == front) {

				cout<<"Queue is empty"<<endl;
			} else {
				arr[front] = 0;
				front++;
				if(front == rear) {
					front = 0;
					rear = 0;
				}
			}
		}
		int Front() {
			return arr[front];
		}
		int Size() {
			return 0;
		}
		bool isEmpty() {
			if(rear == front) {
				return 1;
			} else {
				return 0;
			}
		}
		void display() {
			for(int i = 0; i < rear; i++) {
				cout<<arr[i]<<" ";
			}
		}
};

class CircularQueue {
		int front;
		int rear;
		int size;
		int* arr;
		CircularQueue() {
			size = 100;
			arr = new int[size];
			front = rear = -1;
		}
		bool push(int val) {
			if((front == 0 and rear == size-1) || (rear == front-1)) {
				cout<<"Queue is full"<<endl;
				return false;
			} else if(front == -1) {
				front = rear = 0;
			} else if(rear == size-1 and front != 0) {
				rear = 0;
			} else {
				rear++;
			}
			arr[rear] = val;
			return true;
		}
		bool pop() {
			if(front == -1) {
				cout<<"Queue is empty"<<endl;
				return false;
			}
			arr[front] = -1;
			if(front == rear) {
				front = rear = -1;
			} else if(front == size-1) {
				front = 0;
			} else {
				front++;
			}
			return true;
		}
};

class DoublyEndedQueue {
		int Front;
		int Back;
		int size;
		int *arr;
	public:
		DoublyEndedQueue(int n) {
			size = n;
			arr = new int[size];
			Front = Back = -1;
		}
		bool pushFront(int val) {
			if(Front == 0 && Back == size-1 || Back == Front-1) {
				cout<<"queue is full"<<endl;
				return false;
			} else if(Front == -1) {
				Front = Back = 0;  // first element inserting
			} else if(Front == 0) {
				Front = size - 1;
			} else {
				Front--;
			}
			arr[Front] = val;
			return true;
		}
		bool pushBack(int val) {
			if(Front == 0 && Back == size-1 || Back == Front-1) {
				cout<<"queue is full"<<endl;
				return false;
			} else if(Back == -1) {
				Front = Back = 0; // first element inserting
			} else if(Back == size - 1 && Front != 0) {
				Back = 0; // to maintain circular behaviour
			} else {
				Back++;
			}
			arr[Back] = val;
			return true;
		}
		bool popFront() {
			if(Front == -1) {
				cout<<"Queue is empty"<<endl;
				return false;
			}
			arr[Front] = false;
			if(Front == Back) {
				Front = Back = -1;
			} else if(Front == size - 1) {
				Front = 0;
			} else {
				Front++;
			}
			return true;
		}
		bool popBack() {
			if(Back == -1) {
				cout<<"Queue is empty"<<endl;
				return false;
			}
			arr[Back] = false;
			if(Front == Back) {
				Front = Back = -1;
			} else if(Back == 0  && Front != 0) {
				Back = size-1;
			} else {
				Back--;
			}
			return true;
		}
		bool isEmpty() {
			if(Front == -1 and Back == -1)
				return true;
			else
				return false;
		}
		bool isFull() {
			if(Front == 0 && Back == size-1 || Back == Front-1)
				return true;
			else
				return false;
		}
		int front() {
			if(!isEmpty())
				return arr[Front];
			else {
				cout<<"Queue is empty"<<endl;
				return false;
			}
		}
		int back() {
			if(!isEmpty())
				return arr[Back];
			else {
				cout<<"Queue is empty"<<endl;
				return false;
			}
		}
		void display() {
			for(int i = 0; i < size; i++) {
				cout<<arr[i]<<" ";
			}
		}
};

int main() {
	/*
	queue<int> q;
	q.push(11);
	q.push(12);
	q.push(13);
	cout<<"size of queue is: "<<q.size()<<endl;
	cout<<"the front of queue is: "<<q.front()<<endl;
	q.pop();
	cout<<"the front of queue is: "<<q.front()<<endl;
	cout<<"size of queue is: "<<q.size()<<endl;
	if(q.empty()){
		cout<<"queue is empty"<<endl;
	}else{
		cout<<"queue is not empty"<<endl;
	}
	q.pop();
	q.pop();
	if(q.empty()){
		cout<<"queue is empty"<<endl;
	}else{
		cout<<"queue is not empty"<<endl;
	}
	cout<<"the front of queue is: "<<q.front()<<endl;
	*/

	/*
	Queue q;
	q.push(11);
	q.push(12);
	q.push(13);
	q.push(14);
	q.push(15);
	q.pop();
	q.pop();
	q.pop();
	q.push(16);
	q.push(17);
	//	cout<<q.Front()<<endl;
	//	q.pop();
	//	cout<<q.Front()<<endl;
	//	q.pop();
	//	cout<<q.Front()<<endl;
	q.display();
	*/

	/*
	deque<int> d;
	d.push_front(12);
	d.push_back(14);
	cout<<d.front()<<endl;
	cout<<d.back()<<endl;
	d.pop_back();
	cout<<d.front()<<endl;
	cout<<d.back()<<endl;
	d.pop_front();
	if(d.empty()){
		cout<<"queue is empty"<<endl;
	}else{
		cout<<"queue is not empty"<<endl;
	}
	*/

	DoublyEndedQueue d(5);
	d.pushBack(11);
	d.pushBack(12);
	d.pushBack(13);
	d.pushBack(14);
	d.pushBack(15);
	d.popBack();
	d.popBack();
	d.popBack();
	d.popBack();
	d.popBack();
	d.pushBack(11);
	d.pushBack(12);
	d.display();

	return 0;
}
