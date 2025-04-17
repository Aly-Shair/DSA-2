//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Node{
    public:
    int data;
    int col;
    int row;
    
    Node(int data, int row, int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare{
    public:
    
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

class Solution{ // https://www.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        int mini = INT_MAX;
        int maxi =  INT_MIN;
        priority_queue<Node*, vector<Node*>, compare> minHeap;
        
        for( int i = 0; i < k; i++){
            int element = KSortedArray[i][0];
            mini = min(mini, element);
            maxi = max(maxi, element);
            
            minHeap.push(new Node(element, i, 0));
        }
        
        int start = mini; int end = maxi;
        
        while(!minHeap.empty()){
            Node* temp = minHeap.top();
            minHeap.pop();
            mini = temp->data;
            if(maxi - mini < end - start){
                start = mini;
                end = maxi;
            }
            
            if(temp->col + 1 < n){
                int element = KSortedArray[temp->row][temp->col+1];
                maxi = max(maxi, element);
                minHeap.push(new Node(element, temp->row, temp->col+1));
            }else{
                break;
            }
            
            delete temp;
        }
        pair<int, int> ans = make_pair(start, end);
        return ans;
        
    }
};
//3 5
//1 3 5
//7 8 9
//2 4 6
//2 3 8
//5 7 11

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends
