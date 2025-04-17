//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class TrieNode {
	public:
		char data;
		TrieNode* children[26];
		bool isTerminal;
		TrieNode(char data) {
			this -> data = data;
			for(int i = 0; i < 26; i++)
				children[i] = nullptr;
			isTerminal = false;
		}
};

class Trie {
		TrieNode* root;

		void insertUtil(TrieNode* root, string word) {
			if(word.length() == 0) {
				root->isTerminal = true;
				return;
			}


			int index = word[0] - 'a';
			TrieNode* child;

			if(root->children[index] != nullptr) {

				child = root->children[index];
			} else {

				child = new TrieNode(word[0]);
				root->children[index] = child;
			}
			insertUtil(child, word.substr(1));
		}
		
		void printSuggestions(TrieNode* curr, string prefixStr, vector<string> &temp){
		    if(curr == nullptr){
		        return;
		    }
		    if(curr -> isTerminal){
		        temp.push_back(prefixStr);
		    }
		    
		    for(char ch = 'a'; ch <= 'z'; ch++){
		        
		        TrieNode* next = curr -> children[ch - 'a']; 
		        if(next != NULL){
		            prefixStr.push_back(ch);
		            printSuggestions(next, prefixStr, temp);
		            prefixStr.pop_back();
		        }
		      //  else{
		      //      break;
		      //  }
		    }
		}

	public:
		Trie() {
			root = new TrieNode('\0');
		}

		void insertWord(string word) {
			insertUtil(root, word);
		}
		
	    vector<vector<string>> getSuggestions(string word){
	        vector<vector<string>> output;
	        string prefixStr = "";
	        TrieNode* prev = root;
	        TrieNode* curr;
	        
	        
	        for(int i = 0; i < word.size(); i++){
	            char lastChar = word[i];
	            prefixStr.push_back(lastChar);
	            
	            curr = prev->children[lastChar - 'a'];
	            
	            if(curr == nullptr){
	                break;
	            }
	            
	            vector<string> temp;
	            printSuggestions(curr, prefixStr, temp);
	            output.push_back(temp);
	            temp.clear();
	            prev = curr;
	        }
	        
	        while(output.size() < word.size()) {
                output.push_back({"0"});
            }
	        return output;
	    }	

};


class Solution{ // https://www.geeksforgeeks.org/problems/phone-directory4628/1
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {   
        Trie* t = new Trie();
        for(int i = 0; i < n; i++){
            t->insertWord(contact[i]);
        }
        
        return t->getSuggestions(s);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < ans.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
