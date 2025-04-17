//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution
{
	public:

		bool solve(string s, int i, int j)
		{
			if(i > j)
			{
				return true;
			}

			if(s.at(i) != s.at(j))
			{
				return false;
			}

			return solve(s, i+1, j-1);
		}
		int isPalindrome(string S)
		{
			int i = 0, j = S.size()-1;
			return solve(S, i, j);
		}

};

//{ Driver Code Starts.

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;

		Solution ob;

		cout << ob.isPalindrome(s) << "\n";
	}

	return 0;
}
// } Driver Code Ends
