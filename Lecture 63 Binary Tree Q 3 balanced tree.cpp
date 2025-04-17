#include<iostream>
#include<cmath>
// https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
using namespace std;
/*
class Solution{
    public:
    int height(struct Node* node){
        if(node == NULL){
            return 0;
        }
        int left = height(node->left);
        int right = height(node->right);
        int ans = max(left, right) + 1;
        return ans;
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
       if(root == NULL){
           return true;
       }
       bool left = isBalanced(root->left);
       bool right = isBalanced(root->right);
       bool diff = abs(height(root->left) - height(root->right)) <= 1;
       if(left && right && diff)
           return true;
       else
        return false;
       
       
       
    }
};
*/

class Solution{
    public:
    int height(struct Node* node){
        if(node == NULL){
            return 0;
        }
        int left = height(node->left);
        int right = height(node->right);
        int ans = max(left, right) + 1;
        return ans;
    }
    //Function to check whether a binary tree is balanced or not.

    pair<bool, int> isBalancedFast(Node* root){
        if(root == NULL){
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        pair<bool, int> left = isBalancedFast(root->left);
        pair<bool, int> right = isBalancedFast(root->right);
        
        int height = max(left.second, right.second) + 1;
        
        pair<bool, int> ans;
        ans.first = (abs (left.second - right.second) <= 1) && (left.first) && (right.first);
        ans.second = height;
        return ans;
    }
    
    bool isBalanced(Node *root )
    {
        return isBalancedFast(root).first; 
    }
};


int main(){

/*	
	int a = abs(-5);
	cout<<a;
*/
	return 0;
}
