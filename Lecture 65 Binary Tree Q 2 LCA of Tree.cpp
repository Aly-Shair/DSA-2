#include<iostream>
using namespace std;

// https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1


class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(root == NULL){
           return NULL;
       } 
       
       if(root->data == n1 || root->data == n2){
           return root;
       }
       Node* rootLeft = lca(root->left, n1, n2);
       Node* rootRight = lca(root->right, n1, n2);
       
       if(rootLeft != NULL && rootRight != NULL){
           return root;
       }else if(rootLeft != NULL && rootRight == NULL) {
           return rootLeft;
       }else if(rootLeft == NULL && rootRight != NULL){
           return rootRight;
       }else{
           return NULL;
       }
    }
};

int main(){
	
	return 0;
}
