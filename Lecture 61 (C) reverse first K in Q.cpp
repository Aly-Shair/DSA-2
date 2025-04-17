#include<iostream>
#include<stack>
#include<queue>
using namespace std;

// https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

class Solution {
		/* space complexity O(k) and time complexity O(k) + O(k) + O(size - k) = O(n)  (k max will be  equal to n)*/

	public:
		stack<int> s;
		// Function to reverse first k elements of a queue.
		queue<int> modifyQueue(queue<int> q, int k) {

			while(s.size() < k) {
				int val = q.front();
				s.push(val);
				q.pop();
			}
			while(s.size() != 0) {
				int val = s.top();
				q.push(val);
				s.pop();
			}
			int t = q.size() - k;
			while(t--) {
				int val = q.front();
				q.push(val);
				q.pop();
			}
			return q;
		}
};

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        stack<int> s;
        for(int i = 0; i < k; i++){
            int Front = q.front();
            q.pop();
            s.push(Front);
            
        }
        
        for(int i = 0; i < k; i++){
            int Top = s.top();
            s.pop();
            q.push(Top);
        }
        
        int t = q.size() - k;
        
        while(t--){
            int Front = q.front();
            q.pop();
            q.push(Front);
        }
        
        return q;
    }
};

int main() {

	return 0;
}
