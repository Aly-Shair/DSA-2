/*
Given a Binary Search Tree. Convert a given BST into a Special Max Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied on all the nodes in the so converted Max Heap.

Example 1:

Input :
                 4
               /   \
              2     6
            /  \   /  \
           1   3  5    7

Output : 1 2 3 4 5 6 7
Exaplanation :
               7
             /   \
            3     6
          /   \  /   \
         1    2 4     5
The given BST has been transformed into a
Max Heap and it's postorder traversal is
1 2 3 4 5 6 7.

Your task :
You don't need to read input or print anything. Your task is to complete the function convertToMaxHeapUtil() which takes the root of the tree as input and converts the BST to max heap.
Note : The driver code prints the postorder traversal of the converted BST.

Expected Time Complexity : O(n)
Expected Auxiliary Space : O(n)

Constraints :
1 = n = 105
*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

/* Helper function that allocates a new node
with the given data and NULL left and right
pointers. */
Node* newNode(int val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node* root = newNode(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size())
	{

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N")
		{

			// Create the left child for the current node
			currNode->left = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N")
		{

			// Create the right child for the current node
			currNode->right = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}
void postorderTraversal(Node* root)
{
	if (!root)
		return;

	// recur on left subtree
	postorderTraversal(root->left);

	// then recur on right subtree
	postorderTraversal(root->right);

	// print the root's data
	cout << root->data << " ";
}



// } Driver Code Ends
//User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution
{
		void inorder(Node* root, vector<int> &inorderedVals)
		{
			if(!root)
				return;

			inorder(root->left, inorderedVals);
			inorderedVals.push_back(root->data);
			inorder(root->right, inorderedVals);
		}

		void copyVals(Node* &root, vector<int> &inorderedVals, int &idx)
		{
			if(!root or idx < 0)
				return;

			root->data = inorderedVals[idx--];
			copyVals(root->right, inorderedVals, idx);
			copyVals(root->left, inorderedVals, idx);

		}

	public:
		void convertToMaxHeapUtil(Node* root)
		{
			vector<int> inorderedVals;

			inorder(root, inorderedVals);

			int idx = inorderedVals.size()-1;
			copyVals(root, inorderedVals, idx);
		}
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	getchar();
	while (t--)
	{
		string inp, ch;
		getline(cin, inp);
		struct Node* root = buildTree(inp);
		Solution ob;
		ob.convertToMaxHeapUtil(root);
		postorderTraversal(root);
		cout << "\n";

		cout << "~" << "\n";
	}
	return 0;
}


// } Driver Code Ends
