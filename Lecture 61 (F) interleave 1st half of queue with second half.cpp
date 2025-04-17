#include<iostream>
#include<queue>
#include<stack>
using namespace std;
// https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
void interleave(queue<int> &q) {
	
	stack<int> s;
	
	int qsize = q.size();
	
	while(s.size() != (qsize/2)) {
	
		int val = q.front(); 
		s.push(val);
		q.pop();
	}
	
	while(!s.empty()) {
	
		int val = s.top();
		q.push(val);
		s.pop();
	}
	
	int i = 0;
	while(i != (qsize/2)) {
		
		int val = q.front();
		q.push(val);
		q.pop();
		i++;
	}
	
	while(s.size() != (qsize/2)) {
	
		int val = q.front();
		s.push(val);
		q.pop();
	}

	while(!s.empty()) {
	
		int sval = s.top();
		q.push(sval);
		s.pop();
	
		int qval = q.front();
		q.push(qval);
		q.pop();
	}
}

int main() {
	
	int n = 8;
	int arr[n] = {11, 12, 13, 14, 15, 16, 17, 18};

	queue<int> q;

	for(int i = 0; i < n; i++) {
		q.push(arr[i]);
	}

	interleave(q);

	for(int i = 0; i < n; i++) {
		cout<<q.front()<<" ";
		q.pop();
	}

	return 0;
}

/*


class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        vector<int> v;
        int t = q.size();
        stack<int> s;
        while(t--){
            int val = q.front();
            q.pop();
            s.push(val);
        }
        t = s.size()/2;
        while(t--){
            int val = s.top();
            s.pop();
            q.push(val);
        }
        t = q.size();
        
        while(t--){
            
            int front = q.front();
            q.pop();
            q.push(front);
            int top = s.top();
            s.pop();
            q.push(top);
        }
        t = q.size();
        while(t--){
            int val = q.front();
            q.pop();
            s.push(val);
        }
        t = s.size();
        while(t--){
             int val = s.top();
            s.pop();
            v.push_back(val);

        }
        return v;
    }
};
*/
