// https://www.geeksforgeeks.org/binary-search-tree-data-structure/
#include<iostream>
#include<queue>
using namespace std;

class Node
{
	public:
		int data;
		Node* left;
		Node* right;

		Node(int data)
		{
			this->data = data;
			this->left = this->right = NULL;
		}
};

Node* insertIntoBST(Node* root, int data)
{
	if(root == NULL)
	{
		root = new Node(data);
		return root;
	}

	if(data > root->data)
	{
		root->right = insertIntoBST(root->right, data);
	}
	else
	{
		root->left = insertIntoBST(root->left, data);
	}

	return root;
}

void takeInput(Node* &root)
{

	int data;
	cin>>data;

	while(data != -1)
	{
		root = insertIntoBST(root, data);
		cin>>data;
	}
}
void levelOrderTriversal(Node* root)
{
	cout<<endl<<"Printing the data"<<endl;
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{

		Node* temp = q.front();
		q.pop();

		if(temp == NULL)
		{
			cout<<endl;
			if(!q.empty())
			{
				q.push(NULL);
			}
		}
		else
		{
			cout<<temp->data<<" ";

			if(temp->left != NULL)
			{
				q.push(temp->left);
			}

			if(temp->right)
			{
				q.push(temp->right);
			}
		}
	}
}
/*
void levelOrderTriversal(Node* root){
    if(root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int levelSize = q.size(); // Number of nodes at current level

        // Process all nodes at the current level
        for(int i = 0; i < levelSize; ++i){
            Node* front = q.front();
            q.pop();

            cout << front->data << " ";

            if(front->left)
                q.push(front->left);

            if(front->right)
                q.push(front->right);
        }

        cout << endl; // Move to the next level
    }
}
*/

int main()
{

	Node* root = NULL;

	takeInput(root); // 10 8 21 7 27 5 4 3 -1

	levelOrderTriversal(root);

	return 0;
}
