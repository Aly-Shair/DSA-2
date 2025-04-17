//{ Driver Code Starts
//
/*
Given 2 Arrays of Inorder and preorder traversal. The tree can contain duplicate elements. Construct a tree and print the Postorder traversal. 

Example 1:

Input:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1
Example 2:

Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5
Your Task:
Your task is to complete the function buildTree() which takes 3 arguments(inorder traversal array, preorder traversal array, and size of tree n) and returns the root node to the tree constructed. You are not required to print anything and a new line is added automatically (The post order of the returned tree is printed by the driver's code.)

Expected Time Complexity: O(N*N).
Expected Auxiliary Space: O(N).

Constraints:
1<=Number of Nodes<=1000


*/
/*
Key Issue
The position function finds the first occurrence of an element in the entire array, while findPosition is supposed to find it within the specified range. For this specific test case, the repeated element '3' causes a problem. The position function returns the first '3' it finds, which is at index 1, leading to an incorrect tree construction.

Example Walkthrough
Let's step through the provided inputs:

Preorder: 7, 3, 11, 1, 17, 3, 18
Inorder: 1, 3, 7, 11, 3, 17, 18

The first element in preorder is 7, the root of the tree.
7 splits inorder into: left subtree [1, 3] and right subtree [11, 3, 17, 18].
Now, the next element in preorder is 3:

Using position, the first occurrence of 3 in the inorder array is at index 1, splitting incorrectly.
The correct split should be at index 4 for this '3', but position doesn't account for subarray boundaries.
*/

#include<bits/stdc++.h> // https://www.geeksforgeeks.org/problems/construct-tree-1/1
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
