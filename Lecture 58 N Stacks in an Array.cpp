#include<iostream>
using namespace std;

class NStack {
	private:
		int *arr;
		int *top;
		int *next;
		int n, s;
		int freespot;

	public:
		// Initialize your data structure.
		NStack(int N, int S) {
			n = N;
			s = S;
			arr = new int[s];
			top = new int[n];
			next = new int[s];

			// Top initialization
			for (int i = 0; i < n; i++) {
				top[i] = -1;
			}

			// Next initialization
			for (int i = 0; i < s; i++) {
				next[i] = i + 1;
			}
			// Update last index value to -1
			next[s - 1] = -1;

			// Initialize freespot
			freespot = 0;
		}

		// Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
		bool push(int x, int m) {
			// Check for overflow
			if (freespot == -1) {
				return false;
			}

			// Find index
			int index = freespot;

			// Insert element into array
			arr[index] = x;

			// Update freespot
			freespot = next[index];

			// Update next
			next[index] = top[m - 1];

			// Update top
			top[m - 1] = index;

			return true;
		}

		// Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
		int pop(int m) {
			// Check underflow condition
			if (top[m - 1] == -1) {
				return -1;
			}

			int index = top[m - 1];

			top[m - 1] = next[index];

			next[index] = freespot;

			freespot = index;

			return arr[index];
		}
};

int main() {
	NStack obj(3, 6);
	obj.push(1, 1);
	obj.push(2, 2);
	obj.push(3, 1);
//	obj.display();
	cout << obj.pop(1) << endl;
	obj.push(4, 1);
//	obj.display();

	return 0;
}

