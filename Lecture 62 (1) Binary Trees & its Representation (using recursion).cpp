#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int data);
	
};

Node :: Node(int data){
	this->data = data;
	this->left = NULL;
	this->right = NULL;
}

Node* buildTree(Node* root){
	int data;
	cout<<"Enter the data: ";
	cin>>data;
	if(data == -1){
		return NULL;
	}
	root = new Node(data);
	
	cout<<"Enter the data for left of "<<data<<endl;
	root->left = buildTree(root->left);
	
	cout<<"Enter the data for right of "<<data<<endl;
	root->right = buildTree(root->right);
	
	return root;
}

///*
int main(){
	
	Node* root = NULL;
	
	root = buildTree(root);
	
	return 0;
}
//*/
