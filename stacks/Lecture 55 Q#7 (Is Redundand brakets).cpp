//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
	public:
		int checkRedundancy(string str)
		{
			stack<char> s;

			for(int i = 0; i < str.size(); i++)
			{
				char ch = str[i];

				if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(')
				{
					s.push(ch);
				}
				else
				{
					if(ch == ')')
					{
						bool isRedundant = true;
						while(s.top() != '(')
						{

							if(s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/')
							{
								isRedundant = false;
							}

							s.pop();

						}

						if(isRedundant)
						{
							return true;
						}

						s.pop();
					}
				}
			}

			return false;
		}
};


//{ Driver Code Starts.

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{

		string s;
		cin >> s;

		Solution obj;
		int res = obj.checkRedundancy(s);

		cout << res << endl;
	}
}

// } Driver Code Ends
