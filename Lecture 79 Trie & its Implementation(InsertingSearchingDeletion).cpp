//	https://www.geeksforgeeks.org/problems/trie-insert-and-search0651/1
/*
#include<iostream>
#include<string>
using namespace std;

class TrieNode
{
	public:
		char data;
		TrieNode* children[26];
		bool isTerminal;
		TrieNode(char data)
		{
			this -> data = data;
			for(int i = 0; i < 26; i++)
				children[i] = nullptr;
			isTerminal = false;
		}
};

class Trie
{
		TrieNode* root;

		void insertUtil(TrieNode* root, string word)
		{
			if(word.length() == 0)
			{
				root->isTerminal = true;
				return;
			}


			int index = word[0] - 'A';
			TrieNode* child;

			if(root->children[index] != nullptr)
			{

				child = root->children[index];
			}
			else
			{

				child = new TrieNode(word[0]);
				root->children[index] = child;
			}
			insertUtil(child, word.substr(1));
		}

		bool searchUtil(TrieNode* root, string word)
		{
			if(word.length() == 0)
			{
				return root->isTerminal;
			}

			int index = word[0] - 'A';
			TrieNode* child;

			if(root->children[index] != nullptr)
			{
				child = root->children[index];
			}
			else
			{
				return false;
			}

			return searchUtil(child, word.substr(1));
		}
		
//		void deleteUtil(TrieNode* root, string word) {
//			if (word.length() == 0) {
//				// When the word is completely traversed
//				root->isTerminal = false;
//				return;
//			}
//
//			int index = word[0] - 'A';
//			TrieNode* child = root->children[index];
//
//			if (child == nullptr) {
//				// If the word is not present
//				return;
//			}
//
//			// Recursive call for the next character in the word
//			deleteUtil(child, word.substr(1));
//
//			// Check if the child node can be deleted
//			bool childHasNoChildren = true;
//			for (int i = 0; i < 26; i++) {
//				if (child->children[i] != nullptr) {
//					childHasNoChildren = false;
//					break;
//				}
//			}
//
//			if (!child->isTerminal && childHasNoChildren) {
//				// Delete the child node if it's not terminal and has no children
//				delete child;
//				root->children[index] = nullptr;
//			}
		}
		
		void deleteUtil(TrieNode* root, string word)
		{
			if(word.length() == 0)
			{
				if(root->isTerminal)
					root->isTerminal = false;
				else
					cout<<"Word not exist"<<endl;
					
				return;
			}

			int index = word[0] - 'A';
			TrieNode* child;

			if(root->children[index] != nullptr)
			{
				child = root->children[index];
			}
			else
			{
				cout<<"Word does not exist"<<endl;
				return;
			}

			deleteUtil(child, word.substr(1));

			bool childHasNoChildren = true;

			for(int i = 0; i < 26; i++)
			{
				if(child->children[i] != nullptr)
				{
					childHasNoChildren = false;
					break;
				}
			}

			if(!child->isTerminal and childHasNoChildren)
			{
				delete child; // delete child to freeup memory occupied by child
				root->children[index] = nullptr; // make root's child null which is deleted
			}
		}

	public:
		Trie()
		{
			root = new TrieNode('\0');
		}

		void insertWord(string word)
		{
			insertUtil(root, word);
		}

		bool searchWord(string word)
		{
			return searchUtil(root, word);
		}

		void deleteWord(string word)
		{
			deleteUtil(root, word);
		}

};

int main()
{

	Trie* t = new Trie();
	t->insertWord("ARE");
	t->insertWord("ARY");
	t->insertWord("DO");
	t->insertWord("DO");
	t->insertWord("TIME");
	t->insertWord("TIM");

	t->deleteWord("TIM");
	t->deleteWord("TIME");
	cout<<"Present or Not "<<t->searchWord("TIM")<<endl;
	cout<<"Present or Not "<<t->searchWord("TIME")<<endl;
	cout<<"Present or Not "<<t->searchWord("T")<<endl;
	t->deleteWord("ABC");
	
	return 0;
}
*/

///* //  gfg practice

//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>

using namespace std;

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// trie node
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void) {
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *) malloc(sizeof(struct TrieNode));

    if (pNode) {
        int i;

        pNode->isLeaf = false;

        for (i = 0; i < ALPHABET_SIZE; i++) pNode->children[i] = NULL;
    }

    return pNode;
}
//
//
// } Driver Code Ends
// User function template for C++

// trie node

//struct TrieNode {
//    struct TrieNode *children[ALPHABET_SIZE];
//
//    // isLeaf is true if the node represents
//    // end of a word
//    bool isLeaf;
//};

class Solution
{
    public:
        //Function to insert string into TRIE.
        void insert(struct TrieNode *root, string key)
        {
            if(key.length() == 0){
                root->isLeaf = true;
                return;
            }

            int idx = CHAR_TO_INDEX(key[0]);
            TrieNode* child;

            if(root->children[idx] != nullptr){
                child = root->children[idx];
            }else{
                // child = new TrieNode(key[0]);
                child = root->children[idx] = getNode();
            }

            insert(child, key.substr(1));
        }

        //Function to use TRIE data structure and search the given string.
        bool search(struct TrieNode *root, string key)
        {
//            if(key.length() == 0){
//                return root->isLeaf;
//            }
//
//            int idx = CHAR_TO_INDEX(key[0]);
//            TrieNode* child;
//
//            if(root->children[idx] != nullptr){
//                child = root->children[idx];
//            }else{
//                return false;
//            }
//
//            return search(child, key.substr(1));

			TrieNode* prev = root;
            TrieNode* curr; 
            
            for(int i = 0; i < key.size(); i++){
                curr = prev->children[key[i] - 'a'];
                if(curr != nullptr){
                    prev = curr;
                }else{
                	return false;
				}
            }
            
            if(prev->isLeaf)
                return true;
            return false;
        }
};


//{ Driver Code Starts.

// Driver
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        // Input keys (use only 'a' through 'z' and lower case)
        int n;
        cin >> n;
        string keys[n];

        for (int i = 0; i < n; i++) {
            cin >> keys[i];
        }

        Solution obj;
        struct TrieNode *root = getNode();
        // Construct trie
        for (int i = 0; i < n; i++) obj.insert(root, keys[i]);

        string abc;

        cin >> abc;
        // Search for different keys

        if (obj.search(root, abc))
            cout << "1\n";
        else
            cout << "0\n";
        // char ex;
        // cin >> ex;
        // cout << ex << "\n";
    }
    return 0;
}
// } Driver Code Ends
//*/

