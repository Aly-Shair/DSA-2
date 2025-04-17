//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class compare{
	public:
		bool operator()(Node* a, Node* b){
			return a->data > b->data;
		}
};


class Solution{ // https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr, int K)
    {
           priority_queue<Node*, vector<Node*>, compare> minHeap;
		   if(K == 0)
				return nullptr;
		
		   for(int i = 0; i < K; i++){
			   if(arr[i] != nullptr){
				   minHeap.push(arr[i]);
			   }
		   }
		   
		   Node* head = NULL;
		   Node* tail = nullptr;
		   
		   while(minHeap.size() > 0){
			   Node* top = minHeap.top();
			   minHeap.pop();
			   
			   if(top->next != NULL){
					   minHeap.push(top->next);
			    }
			   
			   if(head == nullptr){
				   head = tail = top;
				   //if(head->next != NULL){
					 //  minHeap.push(tail->next);
				   //}
			   }else{
				   tail -> next = top;
				   tail = top;
			   }
		   }
		   
		   return head;
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends

/*
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

class CMP{
  public:
    bool operator() (Node* a, Node* b){
        return a->data > b->data;
    }
};

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
    
    	if(arr.size() == 0)
            return;
    
        priority_queue <Node*, vector<Node*>, CMP> minHeap;
        
        
        
        for(int i = 0; i < arr.size(); i++){
           minHeap.push(arr[i]);
        }
        
        Node* ans = minHeap.top();
        minHeap.pop();
        
        if(ans -> next)
            minHeap.push(ans->next);
        
        Node* tail = ans;
        
        while(!minHeap.empty()){
            Node* n = minHeap.top();
            minHeap.pop();
            
            tail->next = n;
            tail = tail->next;
            
            if(n->next){
                minHeap.push(n->next);
            }
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<Node*> arr;
        vector<int> nums;
        string input;

        getline(cin, input); 
        stringstream ss(input);
        int number;
        while (ss >> number) {
            nums.push_back(number);
        }
        int ind = 0;
        int N = nums.size();

        while (ind < N) {
            int n = nums[ind++];
            int x = nums[ind++];
            Node* head = new Node(x);
            Node* curr = head;
            n--;

            for (int i = 0; i < n; i++) {
                x = nums[ind++];
                Node* temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
            arr.push_back(head);
        }

        Solution obj;
        Node* res = obj.mergeKLists(arr);
        printList(res);
    }
    return 0;
}
*/
