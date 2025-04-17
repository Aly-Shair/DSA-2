#include<iostream>
#include<queue>
using namespace std;

class Node {
	public:
		int data;
		Node* left;
		Node* right;
	
		Node(int data) {
			this->data = data;
			this->left = NULL;
			this->right = NULL;
		}
};

void buildFromLevelOrderTriversal(Node* &root) {
	queue<Node*> q;
	int data;
	cout<<"Enter data for Node "<<" ";
	cin>>data;
	root = new Node(data);
	q.push(root);
	while(!q.empty()){
		Node* temp = q.front();
		q.pop();
		int leftData;
		cout<<"Enter left Node for "<<temp->data<<" ";
		cin>>leftData;
		if(leftData != -1){
			temp->left = new Node(leftData);
			q.push(temp->left);
		}
		int rightData;
		cout<<"Enter right Node for "<<temp->data<<" ";
		cin>>rightData;
		if(rightData != -1){
			temp->right = new Node(rightData);
			q.push(temp->right);
		}
		
	}
	
}


/*
int main() {
	Node* root = NULL;
	buildFromLevelOrderTriversal(root);
	levelOrderTriversal(root);
	return 0;
}
*/
