//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
	public:
		string revStr(string s)
		{
			if(s.length() == 0)
			{
				return "";
			}

			string str = revStr(s.substr(1));
			return str+s.at(0);

		}
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		Solution ob;
		cout << ob.revStr(s) << endl;
	}
	return 0;
}

// } Driver Code Ends


/*
class Solution
{
		void solve(int i, int j, string &s)
		{
			if(i > j)
			{
				return;
			}

			swap(s[i], s[j]);
			i++;
			j--;

			solve(i, j, s);
		}

	public:
		string revStr(string s)
		{
			int i = 0;
			int j = s.size()-1;
			solve(i, j, s);
			return s;
		}
};
*/

