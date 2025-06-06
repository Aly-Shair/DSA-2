#include<iostream>
#include<pair>
// https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1
using namespace std;

/*
// not optimized
class Solution {
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
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        if(root == NULL){
            return 0;
        }
        int op1 = diameter(root->left);
        int op2 = diameter(root->right);
        int op3  = height(root->left) + 1 + height(root->right);
        int ans = max(op1, max(op2, op3));
        return ans;
    }
};
*/

// optimized

pair<int, int> diameterFast(Node* root){
	
	if(root == NULL){
		pair<int, int> p = make_pair(0, 0);
		return p;
	}
	
	pair<int, int> left = diameterFast(root->left);
	pair<int, int> right = diameterFast(root->right);
	int opt1 = left.first;
	int opt2 = right.first;
	int opt3 = left.second + right.second + 1;
	
	pair<int, int> ans;
	ans.first = max(opt1, max(opt2, opt3));
	ans.second = max(left.second, right.second) + 1;
	
	return ans;
}
// T.C = O(n) S.C = O(h)
int diameter(Node* root){
	return diameterFast(root).first;
}

int main(){
	
	return 0;
}
