/*
Given a string S. The task is to print all unique permutations of the given string that may contain dulplicates in lexicographically sorted order.

Example 1:

Input:
ABC
Output:
ABC ACB BAC BCA CAB CBA
Explanation:
Given string ABC has permutations in 6
forms as ABC, ACB, BAC, BCA, CAB and CBA .
Example 2:

Input:
ABSG
Output:
ABGS ABSG AGBS AGSB ASBG ASGB BAGS
BASG BGAS BGSA BSAG BSGA GABS GASB
GBAS GBSA GSAB GSBA SABG SAGB SBAG
SBGA SGAB SGBA
Explanation:
Given string ABSG has 24 permutations.
Your Task:
You don't need to read input or print anything. Your task is to complete the function find_permutation() which takes the string S as input parameter and returns a vector of string in lexicographical order.

Expected Time Complexity: O(n! * n)
Expected Space Complexity: O(n! * n)

Constraints:
1 <= length of string <= 5
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution // https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1
{
	private:
		void solve(string S, int idx, set<string> &setAns)
		{
			if(idx >= S.size())
			{
				setAns.insert(S);
				return;
			}

			for(int j = idx; j < S.size(); j++)
			{
				swap(S[idx], S[j]);
				solve(S, idx+1, setAns);
				swap(S[idx], S[j]);
			}
		}
	public:
		vector<string>find_permutation(string S)
		{
			set<string> setAns;

			solve(S, 0, setAns);
			vector<string> ans(setAns.begin(), setAns.end());

			return ans;
		}
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string S;
		cin >> S;
		Solution ob;
		vector<string> ans = ob.find_permutation(S);
		sort(ans.begin(),ans.end());
		for(auto i: ans)
		{
			cout<<i<<" ";
		}
		cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends
