
class Solution{
	
	int signum(int a, int b){
		if(a == b)
			return 0;
		if(a > b)
			return 1;
		else 
			return -1;
	}
	
	void callMedian(int element, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int> > &minHeap, int &median){
		switch(signum(maxHeap.size(), minHeap.size())){
			case 0:
				if(element > median){
					minHeap.push(element);
					median = minHeap.top();
				}
				else{
					maxHeap.push(element);
					median = maxHeap.top();	
				}
				break;
			case 1:
				if(element > median){
					minHeap.push(element);
					median = (maxHeap.top()+ minHeap.top())/2;
				}
				else{
					minheap.push(maxHeap.top());
					maxHeap.pop();
					maxHeap.push(element);
					median = (maxHeap.top() + minHeap.top())/2;
				}
				break;
			case -1:
				if(element > median){
					maxHeap.push(minHeap.top());
					minHeap.pop();
					minHeap.push(element);
					median = (minHeap.top() + maxHeap.top())/2;
				}
				else{
					maxHeap.push(element);
					median = (minHeap.top() + maxHeap.top())/2;
				}
				break;
		}
	}
	public:
		vector<int> findMedian(vector<int> &arr, int n){
			vector<int> ans;
			priority_queue<int> maxHeap;
			priority_queue<int, vector<int>, greater<int> > minHeap;
			int median = 0;
			
			for(int i = 0; i < n; i++){
				callMedian(arr[i], maxHeap, minHeap, median);
				ans.push_back(median);
			}			
			
			return ans;
		}
};

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
    double median = 0;
    priority_queue <int> maxHeap;
    priority_queue <int, vector<int>, greater<int>> minHeap;
    
    int signum(int a, int b){
        if(a == b)
            return 0;
        else if(a > b)
            return 1;
        else if(a < b)
            return -1;
    }
    
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        switch(signum(maxHeap.size(), minHeap.size())){
            case 0:
                if(x > median){
                    minHeap.push(x);
                    median = minHeap.top();
                }else{
                    maxHeap.push(x);
                    median = maxHeap.top();
                }
            break;
            case 1:
                if(x > median){
                    minHeap.push(x);
                    median = (minHeap.top() + maxHeap.top())/2.0;
                }else{
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(x);
                    median = (minHeap.top() + maxHeap.top())/2.0;
                }
            break;
            case -1:
                if(x > median){
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(x);
                    median = (minHeap.top() + maxHeap.top())/2.0;
                }else{
                    maxHeap.push(x);
                    median = (minHeap.top() + maxHeap.top())/2.0;
                }
            break;
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
     return median;   
    }
};



//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends
