//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Node
{
	public:
		int data;
		Node* left;
		Node* right;

		Node(int data)
		{
			this->data = data;
			this->left = this->right = nullptr;
		}
};

class cmp
{
	public:
		bool operator()(Node* a, Node* b)
		{
			return a->data > b->data;
		}
};



class Solution // https://www.geeksforgeeks.org/problems/huffman-encoding3345/1
{
	private:
		void traversal(Node* root, vector<string> &ans, string temp)
		{
			if(!root->left && !root->right)
			{
				ans.push_back(temp);
				return;
			}

			traversal(root->left, ans, temp+'0');
			traversal(root->right, ans, temp+'1');
		}
	public:
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
			priority_queue<Node*, vector<Node*>, cmp> minHeap;

			for(int i = 0; i < N; i++)
			{
				Node* n = new Node(f[i]);
				minHeap.push(n);
			}

			while(minHeap.size() > 1)
			{
				Node* left = minHeap.top();
				minHeap.pop();

				Node* right = minHeap.top();
				minHeap.pop();

				Node* n = new Node(left->data+right->data);

				n->left = left;
				n->right = right;

				minHeap.push(n);
			}

			Node* root = minHeap.top();

			string temp = "";
			vector<string> ans;

			traversal(root, ans, temp);

			return ans;
		}
};


//{ Driver Code Starts.
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		string S;
		cin >> S;
		int N = S.length();
		vector<int> f(N);
		for(int i=0; i<N; i++)
		{
			cin>>f[i];
		}
		Solution ob;
		vector<string> ans = ob.huffmanCodes(S,f,N);
		for(auto i: ans)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
