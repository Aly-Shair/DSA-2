#include"Lecture 62 (4) Binary Tree Build through level order triversal.cpp"
using namespace std;

void inorderTriversal(Node* root, int &count){
	if(root == NULL){
		return;
	}
	
	inorderTriversal(root->left,count);
	if(root->left == NULL && root->right == NULL){
		count++;
	}
	inorderTriversal(root->right, count);
}

int leafNodes(Node* root){
	int count;
	inorderTriversal(root, count);
	return count;
}

int main() {
	Node* root = NULL;
	buildFromLevelOrderTriversal(root);
	cout<<leafNodes(root);
	return 0;
}
