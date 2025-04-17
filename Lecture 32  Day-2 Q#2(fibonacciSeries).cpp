//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution   // https://geeksforgeeks.org/problems/nth-fibonacci-number1335/1
{
	public:
		int nthFibonacci(int n)
		{
			if(n == 0 || n == 1)
				return n;

			return nthFibonacci(n-1) + nthFibonacci(n-2);
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
		Solution ob;
		cout << ob.nthFibonacci(n) << endl;
	}
	return 0;
}

// } Driver Code Ends
