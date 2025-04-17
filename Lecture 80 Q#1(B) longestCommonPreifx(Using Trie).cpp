//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class TrieNode
{
	public:
		char data;
		TrieNode* children[26];
		bool isTerminal;
		int childCount;
		TrieNode(char data)
		{
			this -> data = data;
			isTerminal = false;
			for(int i = 0; i < 26; i++)
			{
				children[i] = nullptr;
			}

			childCount = 0;
		}
};

class Trie
{
	public:
		TrieNode* root;
		Trie()
		{
			root = new TrieNode('\0');
		}

		void insertUtil(TrieNode* root, string word)
		{
			if(word.length() == 0)
			{
				root->isTerminal = true;
				return;
			}

			int idx = word[0] - 'a';
			TrieNode* child;

			if(root->children[idx] != nullptr)
			{
				child = root->children[idx];
			}
			else
			{
				child = new TrieNode(word[0]);
				root->children[idx] = child;
				root->childCount++;
			}

			insertUtil(child, word.substr(1));
		}

		void insertWord(string word)
		{
			insertUtil(root, word);
		}

		void findLCP(string word, string &ans)
		{
			for(int i = 0; i < word.size(); i++)
			{
				char ch = word[i];

				int idx = ch - 'a';

				if(root->childCount == 1)
				{
					ans.push_back(root->children[idx]->data);
					root = root->children[idx];
				}
				else
				{
					break;
				}

				if(root -> isTerminal)  // not necessary
				{
					break;
				}
			}
		}
};

class Solution  // https://www.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1
{
	public:

		string longestCommonPrefix (string arr[], int N)
		{
			Trie* t = new Trie();

			for(int i = 0; i < N; i++)
			{
				t -> insertWord(arr[i]);
			}

			string ans = "";
			t-> findLCP(arr[0], ans);
			if(ans != "")
				return ans;
			return "-1";
		}
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string arr[n];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];

		Solution ob;
		cout << ob.longestCommonPrefix (arr, n) << endl;
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
