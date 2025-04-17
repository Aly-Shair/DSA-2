#include<iostream>
using namespace std;

class Solution{
	private:
		
		void inorder(Node* root, vector<int> &inOrderVal){
			if(!root)
				return;
			
			inorder(root->left, inOrderVal);
			inOrderVal.push_back(root->data);
			inorder(root->right, inOrderVal);
		}
		
		void preorder(Node* &root, vector<int> inOrderVal, int &idx){
			if(!root)
				return;
			
			root->data = inOrderVal[idx++];
			preorder(root->left, inOrderVal, idx);
			preorder(root->right, inOrderVal, idx);
		}
		
	public:
		Node* BST2MinHeap(Node* root){
			vector<int> inOrderVal;
			inorder(root, inOrderVal);
			int idx = 0;
			preorder(root, inOrderVal, idx);
			
			return root;
		}
};

int main(){
	return 0;
}
