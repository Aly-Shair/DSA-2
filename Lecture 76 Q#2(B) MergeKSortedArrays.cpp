//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++

class Node{
    public:
        int data;
        int i;
        int j;
    Node(int data, int row, int col){
    	this -> data = data;
    	i = row;
    	j = col;
	}
};

class compare{
	  public:
	  	bool operator()(Node* a, Node* b){
	  		return a->data > b->data;
		  }
};

class Solution
{
    private:
        
    public:
    //Function to merge k sorted arrays.
        vector<int> mergeKArrays(vector<vector<int>> arr, int K)
        {
        	priority_queue<Node*, vector<Node*>, compare> minHeap;
        	
        	for(int i = 0; i < K; i++){
        		Node* temp = new Node(arr[i][0], i, 0);
        		minHeap.push(temp);
			}
			
			vector<int> ans;
			
			while(minHeap.size() > 0){
				Node* temp = minHeap.top();
				ans.push_back(temp->data);
				minHeap.pop();
				
				int i = temp->i;
				int j = temp->j;
				
				if(j+1 < arr[i].size()){
					Node* next = new Node(arr[i][j+1], i, j+1);
					minHeap.push(next);
				}
				
//				for(int col = j+1; col < arr[i].size(); col++){
//					ans.push_back(arr[i][col]);
//				}
			}
			return ans;
        
        }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends
