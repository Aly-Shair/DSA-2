/*
Given a string s and a dictionary of words dict of length n, add spaces in s to construct a sentence where each word is a valid dictionary word. Each dictionary word can be used more than once. Return all such possible sentences.

Follow examples for better understanding.

Example 1:

Input: s = "catsanddog", n = 5
dict = {"cats", "cat", "and", "sand", "dog"}
Output: (cats and dog)(cat sand dog)
Explanation: All the words in the given
sentences are present in the dictionary.
Example 2:

Input: s = "catsandog", n = 5
dict = {"cats", "cat", "and", "sand", "dog"}
Output: Empty
Explanation: There is no possible breaking
of the string s where all the words are present
in dict.
Your Task:
You do not need to read input or print anything. Your task is to complete the function wordBreak() which takes n, dict and s as input parameters and returns a list of possible sentences. If no sentence is possible it returns an empty list.

Expected Time Complexity: O(N2*n) where N = |s|
Expected Auxiliary Space: O(N2)

Constraints:
1 = n = 20
1 = dict[i] = 15
1 = |s| = 500
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution { // https://www.geeksforgeeks.org/problems/word-break-part-23249/1
		bool isPresent(vector<string> &dict, string &word, int n) {
			for(int i = 0; i < n; i++) {
				if(word == dict[i]) {
					return true;
				}
			}
			return false;
		}

		void solve(int n, vector<string>& dict, string s,  vector<string> &ans, string sentence, int index) {
			if(index >= s.length()) {
				sentence.pop_back();
				ans.push_back(sentence);
				return;
			}

			string word = "";
			for(int i = index; i < s.size(); i++) {
				word.push_back(s[i]);
				if(isPresent(dict, word, n)) {
					// sentence += (word + " "); // it will make an error because when function returns the sentence is updated which should not
					solve(n, dict, s, ans, sentence + word + " ", i+1);
				}
			}

		}

	public:
		vector<string> wordBreak(int n, vector<string>& dict, string s) {
			vector<string> ans;
			string sentence = "";
			int index = 0;
			solve(n, dict, s, ans, sentence, index);

			return ans;
		}
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		vector<string> dict;
		string s;
		cin>>n;
		for(int i = 0; i < n; i++) {
			cin>>s;
			dict.push_back(s);
		}
		cin>>s;

		Solution ob;
		vector<string> ans = ob.wordBreak(n, dict, s);
		if(ans.size() == 0)
			cout<<"Empty\n";
		else {
			sort(ans.begin(), ans.end());
			for(int i = 0; i < ans.size(); i++)
				cout<<"("<<ans[i]<<")";
			cout<<endl;
		}
	}
	return 0;
}
// } Driver Code Ends
