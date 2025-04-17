//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:
   int positionInInorder(int in[], int element, int start, int end) {
			for(int i = start; i <= end; i++) {
				if(in[i] == element) {
					return i;
				}
			}
			return -1;
		}
		Node* solve(int in[],int post[], int n, int &index, int inorderStart, int inorderEnd) {
			if(index < 0 || inorderStart > inorderEnd) {
				return NULL;
			}
			int element = post[index--];
			Node* node = new Node(element);
			int position = positionInInorder(in, element, inorderStart, inorderEnd);
			node->right = solve(in, post, n, index, position+1, inorderEnd);
			node->left =  solve(in, post, n, index, inorderStart, position-1);
			return node;
		}


    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
        int postorderIndex = n-1;
        int inorderStart = 0;
        int inorderEnd = n-1;
        Node* root  = solve(in, post, n, postorderIndex, inorderStart, inorderEnd);
        return root;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

/*
// optimized approach not work if the any two or more nodes have same value

class Solution{
    public:
    void createMapping(int in[], map<int, int> &findingIndexInInorder, int n){
         for(int i = 0; i < n; i++){
            findingIndexInInorder[in[i]] = i;
        }
    }
    
    Node* solve(int in[], int post[], int n, int &index, int inorderStart, int inorderEnd, map<int, int> &findingIndexInInorder){
        if(index < 0 || inorderStart > inorderEnd){
            return nullptr;
        }
        int element = post[index--];
        Node* node = new Node(element);
        int position = findingIndexInInorder[element];
        node->right = solve(in, post, n, index, position+1, inorderEnd, findingIndexInInorder);
        node->left =  solve(in, post, n, index, inorderStart, position-1, findingIndexInInorder);
        return node;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {   
        int postorderIndex = n-1;
        int inorderStart = 0;
        int inorderEnd = n-1;
        map<int, int> findingIndexInInorder;
       createMapping(in, findingIndexInInorder, n);
        Node* root = solve(in, pre, n, postorderIndex, inorderStart, inorderEnd, findingIndexInInorder);
        return root;
    }
};
*/
