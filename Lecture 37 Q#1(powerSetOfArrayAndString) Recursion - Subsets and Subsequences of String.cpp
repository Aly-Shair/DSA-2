//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
		void solve(string s, int idx, string output, vector<string> &ans)
		{
			if(idx >= s.size())
			{
				if(!output.empty())
					ans.push_back(output);
				return;
			}

			// exclude
			solve(s, idx+1, output, ans);
			
			// include
			char ch = s.at(idx);
			output.push_back(ch);
			solve(s, idx+1, output, ans);
		}

		void solve(string s, int idx, string output, vector<string> &ans)
		{
			if(idx >= s.size())
			{
				if(!output.empty())
					ans.push_back(output);
				return;
			}
			// include
			char ch = s.at(idx);
			solve(s, idx+1, output+ch, ans);

			// exclude
			solve(s, idx+1, output, ans);
		}



	public:
		vector<string> AllPossibleStrings(string s)
		{
			int idx = 0;
			vector<string> ans;
			string output = "";
			solve(s, idx, output, ans);
			sort(ans.begin(), ans.end());
			return ans;
		}
};

//{ Driver Code Starts.
int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends
