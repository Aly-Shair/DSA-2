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

void solve(Node* root, int node, vector<int> &ans, bool &pushpop){
	if(!root){
		return;
	}
	
	if(pushpop){
		ans.push_back(root->data);
	}
	if(root -> data == node){
			pushpop = false;
			return;
	}
	solve(root->left, node, ans, pushpop);
	solve(root->right, node, ans, pushpop);
	
	if(pushpop){
		ans.pop_back();
	}
}

vector<int> path(Node* root, int node){
	vector<int> ans;
	bool pushpop = true;
	solve(root, node, ans, pushpop);
	return ans;
}

int main() {
	Node* root = NULL;
	buildFromLevelOrderTriversal(root);
	
	int node = 5;
	vector<int> ans = path(root, node);
	
	for(int i = 0; i < ans.size(); i++){
		cout<<ans.at(i)<<" ";
	}
	
	return 0;
}
