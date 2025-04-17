//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left;
	struct Node *right;

	Node(int x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};


void printPostOrder(Node *root) {
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution {
	public:
		int positionInInorder(int in[], int element, int start, int end) {
			for(int i = start; i <= end; i++) {
				if(in[i] == element) {
					return i;
				}
			}
			return -1;
		}
		Node* solve(int in[],int pre[], int n, int &index, int inorderStart, int inorderEnd) {
			if(index >= n || inorderStart > inorderEnd) {
				return NULL;
			}
			int element = pre[index++];
			Node* node = new Node(element);
			int position = positionInInorder(in, element, inorderStart, inorderEnd);
			node->left =  solve(in, pre, n, index, inorderStart, position-1);
			node->right = solve(in, pre, n, index, position+1, inorderEnd);
			return node;
		}
		Node* buildTree(int in[],int pre[], int n) {
			int preorderIndex = 0;
			int inorderStart = 0;
			int inorderEnd = n-1;
			Node* root = solve(in, pre, n, preorderIndex, inorderStart, inorderEnd);
			return root;
		}
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;

		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends

/*
Solution{ // mapping gives wrong answer in case of duplicate nodes
    public:
    void createMapping(int in[], map<int, int> &findingIndexInInorder, int n){
         for(int i = 0; i < n; i++){
            findingIndexInInorder[in[i]] = i;
        }
    }

    Node* solve(int in[], int pre[], int n, int &index, int inorderStart, int inorderEnd, map<int, int> &findingIndexInInorder){
        if(index >= n || inorderStart > inorderEnd){
            return nullptr;
        }
        int element = pre[index++];
        Node* node = new Node(element);
        int position = findingIndexInInorder[element];
        node->left =  solve(in, pre, n, index, inorderStart, position-1, findingIndexInInorder);
        node->right = solve(in, pre, n, index, position+1, inorderEnd, findingIndexInInorder);
        return node;
    }

    Node* buildTree(int in[],int pre[], int n)
    {
        int preorderIndex = 0;
        int inorderStart = 0;
        int inorderEnd = n-1;
        map<int, int> findingIndexInInorder;
       createMapping(in, findingIndexInInorder, n);
        Node* root = solve(in, pre, n, preorderIndex, inorderStart, inorderEnd, findingIndexInInorder);
        return root;
    }
*/
