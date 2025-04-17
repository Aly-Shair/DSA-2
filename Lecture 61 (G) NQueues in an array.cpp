/*
// A C++ program to demonstrate implementation
// of k queues in a single
// array in time and space efficient way
#include<iostream>
#include<climits>
using namespace std;

// A C++ class to represent k queues
// in a single array of size n
class kQueues
{
	// Array of size n to store actual
	// content to be stored in queue
	int *arr;

	// Array of size k to store indexes
	// of front elements of the queue
	int *front;

	// Array of size k to store indexes
	// of rear elements of queue
	int *rear;

	// Array of size n to store next
	// entry in all queues
	int *next;
	int n, k;

	int free; // To store the beginning index of the free list

public:
	//constructor to create k queue
	// in an array of size n
	kQueues(int k, int n);

	// A utility function to check if
	// there is space available
	bool isFull() { return (free == -1); }

	// To enqueue an item in queue number
	// 'qn' where qn is from 0 to k-1
	void enqueue(int item, int qn);

	// To dequeue an from queue number
	// 'qn' where qn is from 0 to k-1
	int dequeue(int qn);

	// To check whether queue number
	// 'qn' is empty or not
	bool isEmpty(int qn) { return (front[qn] == -1); }

	void displayQ();
};

// Constructor to create k queues
// in an array of size n
kQueues::kQueues(int k1, int n1)
{
	// Initialize n and k, and allocate
	// memory for all arrays
	k = k1, n = n1;
	arr = new int[n];
	front = new int[k];
	rear = new int[k];
	next = new int[n];

	// Initialize all queues as empty
	for (int i = 0; i < k; i++)
		front[i] = -1;

	// Initialize all spaces as free
	free = 0;
	for (int i=0; i<n-1; i++)
		next[i] = i+1;
	next[n-1] = -1; // -1 is used to indicate end of free list
}

// To enqueue an item in queue number
// 'qn' where qn is from 0 to k-1
void kQueues::enqueue(int item, int qn)
{
	// Overflow check
	if (isFull())
	{
		cout << "\nQueue Overflow\n";
		return;
	}

	int i = free;	 // Store index of first free slot

	// Update index of free slot to index of next slot in free list
	free = next[i];

	if (isEmpty(qn))
		front[qn] = i;
	else
		next[rear[qn]] = i;

	next[i] = -1;

	// Update next of rear and then rear for queue number 'qn'
	rear[qn] = i;

	// Put the item in array
	arr[i] = item;
}

// To dequeue an from queue number 'qn' where qn is from 0 to k-1
int kQueues::dequeue(int qn)
{
	// Underflow checkSAS
	if (isEmpty(qn))
	{
		cout << "\nQueue Underflow\n";
		return INT_MAX;
	}

	// Find index of front item in queue number 'qn'
	int i = front[qn];

	// Change top to store next of previous top
	front[qn] = next[i];

	// Attach the previous front to the
	// beginning of free list
	next[i] = free;
	free = i;

	// Return the previous front item
	return arr[i];
}

void kQueues :: displayQ(){
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}cout<<endl;
}

// Driver program to test kStacks class
int main()
{
	// Let us create 3 queue in an array of size 10
	int k = 3, n = 10;
	kQueues ks(k, n);

	// Let us put some items in queue number 1
	ks.enqueue(17, 1);
	ks.enqueue(49, 1);
	ks.enqueue(39, 1);

	// Let us put some items in queue number 2
	ks.enqueue(15, 2);
	ks.enqueue(45, 2);

	// Let us put some items in queue number 0
	ks.enqueue(11, 0);
	ks.enqueue(9, 0);
	ks.enqueue(7, 0);

	cout << "Dequeued element from queue 2 is " << ks.dequeue(2) << endl;
	cout << "Dequeued element from queue 1 is " << ks.dequeue(1) << endl;
	cout << "Dequeued element from queue 0 is " << ks.dequeue(0) << endl;

	return 0;
}
*/
/*
#include<iostream>
using namespace std;

class kQueue {

	private:
		int* arr;
		int* next;
		int* front;
		int* rear;
		int n, k, freeSpot, size;
	public:

		kQueue(int n, int k);

		void push_back(int val, int qn);

		int pop_front(int qn);

		bool isFull() {
			return freeSpot == -1;
		};

		bool isEmpty(int qn) {
			return front[qn - 1] == -1;
		}

		void displayQ();

};

kQueue :: kQueue(int n, int k) {

	this->n = n;
	this->k = k;
	arr = new int[n];
	size = 0;
	freeSpot = 0;
	next = new int[n];
	for(int i = 0; i < n-1; i++) {
		next[i] = i+1;
		arr[i] = 0;
	}
	next[n-1] = -1;

	front = new int[k];
	rear = new int[k];
	for(int i = 0; i < k; i++) {
		front[i] = -1;
		rear[i] = -1;
	}

}

void kQueue :: push_back(int val, int qn) {

	if(isFull()){
		cout<<"Queue is full"<<endl;
		return;
	}

	int idx  = freeSpot;
	freeSpot = next[idx];

	if(isEmpty(qn)) {
		front[qn-1] = idx;
	} else {
		next[rear[qn-1]] = idx;
	}

	next[idx] = -1;

	rear[qn-1] = idx;

	arr[idx] = val;
}

int kQueue :: pop_front(int qn){
	if(isEmpty(qn)){
		cout<<"Queue is Empty"<<endl;
		return -1;
	}
	int idx = front[qn-1];

	front[qn -1] = next[idx];

	next[idx] = freeSpot;
	freeSpot = idx;

	return arr[idx];
}

void kQueue :: displayQ(){
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}cout<<endl;
}

int main() {

	kQueue obj(10, 3);

	obj.push_back(11, 1);
	obj.push_back(12, 1);
	obj.push_back(17, 2);
	obj.displayQ();
	cout<<obj.pop_front(1)<<endl;;
	obj.push_back(19, 2);
	obj.displayQ();

	return 0;
}
*/

#include<iostream>
using namespace std;

class NQueue {
	public:
		int* arr;
		int* next;
		int* front;
		int* rear;
		int freeSpot;
		int size;
		NQueue(int k, int n) {

			size = n;

			arr = new int[n];
			next = new int[n];

			for(int i = 0; i < size; i++) {
				arr[i] = -1;
				next[i] = i+1;
			}
			next[size-1] = -1;

			front = new int[k];
			rear = new int[k];

			for(int i = 0; i < k; i++) {
				front[i] = rear[i] = -1;
			}

			freeSpot = 0;
		}

		void push(int q, int val) {

			if(isFull()) {
				cout<<"Queue is Full"<<endl;
				return;
			}

			int idx = freeSpot;
			freeSpot = next[idx];

			if(isEmpty(q)) {
				front[q-1] = idx;
			} else {
				next[rear[q-1]] = idx;
			}
			rear[q-1] = idx;
			next[idx] = -1;

			arr[idx] = val;
		}

		void pop(int q) {

			if(isEmpty(q)) {
				cout<<"Queue is Empty"<<endl;
				return;
			}
			int idx = freeSpot;
			freeSpot = front[q-1];

			front[q-1] = next[front[q-1]];

			next[freeSpot] = idx;
		}
		
		int kQueue :: pop_front(int qn) {
			if(isEmpty(qn)) {
				cout<<"Queue is Empty"<<endl;
				return -1;
			}
			int idx = front[qn-1];

			front[qn -1] = next[idx];

			next[idx] = freeSpot;
			freeSpot = idx;

			return arr[idx];
		}
		 
		bool isFull() {
			return (freeSpot == -1);
		}

		bool isEmpty(int q) {
			return front[q-1] == -1;
		}
};

int main() {

	return 0;
}

