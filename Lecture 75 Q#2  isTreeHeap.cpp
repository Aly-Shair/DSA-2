//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
    int nodeCount(struct Node* root){
        if(root == nullptr)
            return 0;
  
        int Left = nodeCount(root->left);
        int Right = nodeCount(root->right);
        
        int ans = Left + Right + 1;
        
        return ans;
    }
    
    bool isCBT(struct Node* root, int index, int treeSize){
        if(root == nullptr)
            return true;
        
        // if(!root->left and !root->right){ // 8 7 6 N N 5 4
        //     return true;
        // }
        
        if(index >= treeSize){
            return false;
        }else{
            bool Left = isCBT(root->left, 2*index + 1, treeSize);
            bool Right = isCBT(root->right, 2*index + 2, treeSize);
            
            return (Left and Right);
        }
    }
    
    bool isMaxOrder(struct Node* root){
        if(!root)
            return true;
            
        if(!root->left  and !root->right)
            return true;
        
        if(root->left and !root->right){
            return (root->data > root->left->data);
        }
        else{
            bool Left = isMaxOrder(root->left);
            bool Right = isMaxOrder(root->right);
            
            return (Left and Right and (root->data > root->left->data and root->data > root->right->data));
        }
    }
  public:
    bool isHeap(struct Node* tree) {
        int index = 0;
        int treeSize = nodeCount(tree);
        return  (isCBT(tree, index, treeSize) and isMaxOrder(tree));
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
// } Driver Code Ends
