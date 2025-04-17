// https://www.geeksforgeeks.org/problems/search-a-node-in-bst/1

bool search(Node* root, int val){ // T.C => O(log(n)) and S.C => O(H)
	if(root == NULL){
		return false;
	}
	if(root->data == val){
		return true;
	}
	
	if(val < root->data){
		return search(root->left, val);
	}
	
	if(val > root->data){
		return search(root->right, val);
	}
}
