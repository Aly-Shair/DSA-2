//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		cout << countRev (s) << '\n';
	}
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string str) // https://www.geeksforgeeks.org/problems/count-the-reversals0401/1
{

	if(str.length()%2 != 0)
	{
		return -1;
	}
	stack<char>s;
	for(int i = 0; i < str.length(); i++)
	{
		char ch = str[i];
		if(ch == '{')
		{
			s.push(ch);
		}
		else
		{
			if(!s.empty() && s.top() == '{')
			{
				s.pop();
			}
			else
			{
				s.push(ch);
			}
		}
	}
	int open = 0, close = 0;
	while(!s.empty())
	{
		if(s.top() == '{')
		{
			open++;
		}
		else
		{
			close++;
		}
		s.pop();
	}
	int ans = (open+1)/2 + (close + 1)/2;
	return ans;

}
