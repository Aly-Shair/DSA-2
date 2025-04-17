#include"Lecture 62 Binary Trees & its Representation (using recursion).cpp"
#include<queue>
void levelOrderTriversal(Node* root) {
	cout<<endl<<"Printing the data"<<endl;
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()) {
		
			Node* temp = q.front();
			q.pop();
		
		if(temp == NULL) {
			cout<<endl;
			if(!q.empty()) {
				q.push(NULL);
			}
		} else {
			cout<<temp->data<<" ";

			if(temp->left != NULL) {
				q.push(temp->left);
			}

			if(temp->right) {
				q.push(temp->right);
			}
		}
	}
}

int main() {

	Node* root = NULL;
//	input 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
	root = buildTree(root);

	levelOrderTriversal(root);

	return 0;
}

