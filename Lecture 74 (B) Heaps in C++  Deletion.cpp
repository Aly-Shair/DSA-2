#include<iostream>
using namespace std;

class Heap
{
	private:
		int arr[100];
		int size;
	public:
		Heap()
		{
			arr[0] = -1;
			size = 0;
		}

		void insert(int val)
		{
			int idx = ++size;
			arr[idx] = val;

			while(idx > 1)
			{
				int parent = idx/2;

				if(arr[parent] < arr[idx])
				{
					swap(arr[parent], arr[idx]);
					idx = parent;
				}
				else
				{
					return;
				}
			}
		}

		void remove()
		{
			if(size == 0)
				return;

			int idx = 1;
			arr[idx] = arr[size];
			size--;

			while(idx < size)
			{
				int leftChild = 2*idx;
				int rightChild = 2*idx+1;
				int val;

				if(leftChild <= size and rightChild <= size)
				{

					val = max(arr[idx], max(arr[leftChild], arr[rightChild]));

					if(val == arr[leftChild])
					{

						swap(arr[idx], arr[leftChild]);
						idx = leftChild;

					}
					else if(val == arr[rightChild])
					{

						swap(arr[idx], arr[rightChild]);
						idx = rightChild;

					}
					else
					{
						return;
					}
				}
				else if(leftChild <= size  and (arr[leftChild] > arr[idx]))
				{

					swap(arr[idx], arr[leftChild]);
					idx = leftChild;

				}
				else if(rightChild <= size  and (arr[rightChild] > arr[idx]))
				{

					swap(arr[idx], arr[rightChild]);
					idx = rightChild;

				}
				else
				{
					return;
				}
			}
		}

		void print()
		{
			for(int i = 1; i <= size; i++)
			{
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
};

int main()
{

	Heap h;
	h.insert(60);
	h.insert(50);
	h.insert(40);
	h.insert(55);
	h.print();
	h.remove();
	h.print();

	h.remove();
	h.print();

	return 0;
}

/*
A binary heap is a Binary Tree with the following properties:
1) Its a complete tree (All levels are completely filled except possibly the last level and the last level has all keys as left as possible). This property of Binary Heap makes them suitable to be stored in an array.

2) A Binary Heap is either Min Heap or Max Heap. In a Min Binary Heap, the key at the root must be minimum among all keys present in Binary Heap. The same property must be recursively true for all nodes in Binary Tree. Max Binary Heap is similar to MinHeap.

You are given an empty Binary Min Heap and some queries and your task is to implement the three methods insertKey,  deleteKey,  and extractMin on the Binary Min Heap and call them as per the query given below:
1) 1  x  (a query of this type means to insert an element in the min-heap with value x )
2) 2  x  (a query of this type means to remove an element at position x from the min-heap)
3) 3  (a query like this removes the min element from the min-heap and prints it ).

Example 1:

Input:
Q = 7
Queries:
insertKey(4)
insertKey(2)
extractMin()
insertKey(6)
deleteKey(0)
extractMin()
extractMin()
Output: 2 6 - 1
Explanation: In the first test case for
query 
insertKey(4) the heap will have  {4}  
insertKey(2) the heap will be {2 4}
extractMin() removes min element from 
             heap ie 2 and prints it
             now heap is {4} 
insertKey(6) inserts 6 to heap now heap
             is {4 6}
deleteKey(0) delete element at position 0
             of the heap,now heap is {6}
extractMin() remove min element from heap
             ie 6 and prints it  now the
             heap is empty
extractMin() since the heap is empty thus
             no min element exist so -1
             is printed.
Example 2:

Input:
Q = 5
Queries:
insertKey(8)
insertKey(9)
deleteKey(1)
extractMin()
extractMin()
Output: 8 -1
Your Task:
You are required to complete the 3 methods insertKey() which take one argument the value to be inserted, deleteKey() which takes one argument the position from where the element is to be deleted and extractMin() which returns the minimum element in the heap(-1 if the heap is empty)

Expected Time Complexity: O(Q*Log(size of Heap) ).
Expected Auxiliary Space: O(1).

Constraints:
1 <= Q <= 104
1 <= x <= 104
*/
// Link: --> https://www.geeksforgeeks.org/problems/operations-on-binary-min-heap/1


/*
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct MinHeap
{
	int *harr;
	int capacity;
	int heap_size;

	MinHeap(int c)
	{
		heap_size = 0;
		capacity = c;
		harr = new int[c];
	}

	~MinHeap()
	{
		delete[] harr;
	}

	int parent(int i)
	{
		return (i - 1) / 2;
	}

	int left(int i)
	{
		return (2 * i + 1);
	}

	int right(int i)
	{
		return (2 * i + 2);
	}

	void MinHeapify(int); // Implemented in user editor
	int extractMin();
	void decreaseKey(int i, int new_val);
	void deleteKey(int i);
	void insertKey(int k);
};


int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		ll a;
		cin >> a;
		MinHeap h(a);
		for (ll i = 0; i < a; i++)
		{
			int c;
			int n;
			cin >> c;
			if (c == 1)
			{
				cin >> n;

				h.insertKey(n);
			}
			if (c == 2)
			{
				cin >> n;
				h.deleteKey(n);
			}
			if (c == 3)
			{
				cout << h.extractMin() << " ";
			}
		}
		cout << endl;
		// delete h.harr;
		h.harr = NULL;

		cout << "~" << "\n";
	}
	return 0;
}

//Function to extract minimum value in heap and then to store
//next minimum value at first index.
int MinHeap::extractMin()
{
	if(heap_size == 0)
		return -1;

	int minElement = harr[0];

	harr[0] = harr[heap_size-1];
	heap_size--;

	int idx = 0;

	while(idx < heap_size)
	{

		if(left(idx) < heap_size and right(idx) < heap_size)
		{
			int N = harr[idx];
			int L = harr[left(idx)];
			int R = harr[right(idx)];

			int mini = min(N, min(L, R));

			if(mini == N)
				break;

			if(mini == L)
			{
				int l = left(idx);
				swap(harr[idx], harr[l]);
				idx = l;
			}
			else if(mini == R)
			{
				int r = right(idx);
				swap(harr[idx], harr[r]);
				idx = r;
			}
		}
		else if(left(idx) < heap_size)
		{
			int N = harr[idx];
			int L = harr[left(idx)];

			if(N > L)
			{
				swap(harr[idx], harr[left(idx)]);
				idx = left(idx);
			}
			else
			{
				break;
			}
		}
		else
		{
			break;
		}
	}

	return minElement;

}

//Function to delete a key at ith index.
void MinHeap::deleteKey(int i)
{
	if(i >= heap_size)
		return;

	harr[i] = -1;
	int idx = i;

	while(idx > 0)
	{
		swap(harr[idx], harr[parent(idx)]);
		idx = parent(idx);
	}
	extractMin();
}

//Function to insert a value in Heap.
void MinHeap::insertKey(int k)
{
	int idx = heap_size++;
	harr[idx] = k;
	if(idx >= capacity)
		return;

	while(idx > 0)
	{
		int Parent = (idx-1)/2;
		if(harr[parent(idx)] > harr[idx])
		{
			swap(harr[parent(idx)], harr[idx]);
			idx = Parent;
		}
		else
		{
			return;
		}
	}
}

//Function to change value at ith index and store that value at first index.
void MinHeap::decreaseKey(int i, int new_val)
{
	harr[i] = new_val;
	while (i != 0 && harr[parent(i)] > harr[i])
	{
		swap(harr[i], harr[parent(i)]);
		i = parent(i);
	}
}

// You may call below MinHeapify function in
// above codes. Please do not delete this code
// if you are not writing your own MinHeapify 
void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l] < harr[i]) smallest = l;
	if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
	if (smallest != i)
	{
		swap(harr[i], harr[smallest]);
		MinHeapify(smallest);
	}
}
*/
