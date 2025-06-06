//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*Complete the function below

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

/*class Solution {
    int inorder(Node* root, int k, int &i){
        if(!root)
            return -1;
        
        int Left = inorder(root->left, k, i);
        i++;
        if(i == k){
            return root->data;
        }
        
        int Right = inorder(root->right, k, i);
        
        if(Left && Right == -1){
            return Left;
        }else if(Left == -1 && Right){
            return Right;
        }
    }
  public:
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        int i = 0;
        return inorder(root, K, i);
    }
};*/

class Solution {
    int solve(Node* root, int k, int &i){
        if(!root)
            return -1;
        
        int Left = solve(root->left, k, i);
        
        if(Left != -1)
            return Left;
        
        i++;
        if(i == k)
            return root->data;
            
         int Right = solve(root->right, k, i);
        
        if(Right != -1)
            return Right;
    }
  public:
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        int i = 0;
        return solve(root, K, i);
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        getline(cin, s);
        int k = stoi(s);
        //  getline(cin, s);
        Solution obj;
        cout << obj.KthSmallestElement(root, k) << endl;
        // cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends
