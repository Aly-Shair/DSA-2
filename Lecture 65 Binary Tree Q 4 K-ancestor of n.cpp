Node* solve(Node* root, int &k, int node) {
	if(root == NULL)
		return NULL;
	if(root->data == node)
		return root;
	Node* Left = solve(root->left, k, node);
	Node* Right = solve(root->right, k, node);

	if(Left && !Right) {
		k--;
		if(k == 0) {
			k = INT_MAX;
			return root;
		} else
			return Left;
	} else if(!Left && Right) {
		k--;
		if(k == 0) {
			k = INT_MAX;
			return root;
		} else
			return Right;
	} else {
		return NULL;
	}
}

int kthAncestor(Node *root, int k, int node) {
	Node* ans = solve(root, k, node);
	if(ans == NULL || ans->data == node) {
		return -1;
	} else {
		return ans->data;
	}
}
