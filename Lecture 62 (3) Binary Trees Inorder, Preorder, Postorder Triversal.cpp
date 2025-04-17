#include "Lecture 62 (1) Binary Trees & its Representation (using recursion).cpp"

void inorderTriversal(Node* root){
	if(root == NULL){
		return;
	}
	
	inorderTriversal(root->left);
	cout<<root->data<<" ";
	inorderTriversal(root->right);
}

void preorderTriversal(Node* root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<" ";
	preorderTriversal(root->left);
	preorderTriversal(root->right);
}

void postorderTriversal(Node* root){
	if(root == NULL){
		return;
	}
	postorderTriversal(root->left);
	postorderTriversal(root->right);
	cout<<root->data<<" ";
}

int main(){
	
	
	//	input 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
	Node* root = NULL;
	
	root = buildTree(root);
	
	cout<<endl<<"Inorder Trivesal"<<endl;
	inorderTriversal(root);
	
	cout<<endl<<"Preorder Triversal"<<endl;
	preorderTriversal(root);
	
	cout<<endl<<"Postorder Triversal"<<endl;
	postorderTriversal(root);
	return 0;
}
