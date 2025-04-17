/*Node* BST2LL(Node* root){
	if(root == nullptr)
		return root;
	
	BST2LL(root->left);
	
	BST2LL(root->right);
}
*/
/*int i = 0;
while(i < size){
	vec[i]->left = nullptr;
	if(vec[i+1])
		vec[i]->right = vec[i+1];
	else
		vec[i]->right = nullptr;
}*/


  void inorder(Node* root, vector<int> &inorderVal){
        if(!root)
            return;
        
        inorder(root->left, inorderVal);
        inorderVal.push_back(root->data);
        inorder(root->right, inorderVal);
    }
    
Node* flatten(Node* root){
	vector<int> inorderVal;
	inorder(root, inorderVal);
	
	int n = inorderVal.size();
	Node* newRoot = new Node(inorderVal[0]);
	Node* curr = newRoot;
	
	for(int i = 1; i < n; i++){
		Node* temp = new Node[inorderVal(i)];
		curr->left = NULL;
		curr->right = temp;
		curr = temp;
	}
	curr->left = curr->right = nullptr;
	return newRoot;
}
