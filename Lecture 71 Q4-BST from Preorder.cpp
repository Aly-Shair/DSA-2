// https://www.geeksforgeeks.org/problems/construct-tree-from-preorder-traversal/1
struct Node* solve(int n, int min, int max, int pre[], int &i){
    if(i >= n){
        return nullptr;
    }
    
    if(pre[i] < min || pre[i] > max){
        return nullptr;
    }
    
    Node* root = new Node(pre[i++]);
    
    root->left = solve(n, min, root->data, pre, i);
    root->right = solve(n, root->data, max, pre, i);
    
    return root;
}

struct Node *constructTree(int n, int pre[], char preLN[])
{
    int min = INT_MIN;
    int max = INT_MAX;
    int i = 0;
    Node* root =  solve(n, min, max, pre, i);
    return root;
}
