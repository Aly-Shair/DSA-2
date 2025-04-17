Node* minVal(Node* root){
	Node* temp = root;
	
	while(temp->left != nullptr)
		temp = temp->left;
		
	return temp;
}

Node* maxVal(Node* root){
	Node* temp = root;
	
	while(temp->right != nullptr)
		temp = temp->right;
		
	return temp;
}


/*
	-> inorder predecessor
	-> inorder successor
*/
