
#include <bits/stdc++.h>
using namespace std;

// MOD is the requirement of question because answer can be very large

class Solution   // Top Down Approach
{

	private:
		const int MOD = 1e9 + 7;
		int solve(int n, vector<int> &dp)
		{
			if(n == 0 || n == 1)
				return n;

			if(dp[n] != -1)
				return dp[n];

			return dp[n] = (solve(n-1, dp) + solve(n-2, dp)) % MOD;
		}
	public:
		int nthFibonacci(int n)
		{
			vector<int> dp(n+1, -1);
			return solve(n, dp);
		}
};

class Solution   // Bottom Up Approach
{

	private:
		const int MOD = 1e9 + 7;
		int solve(int n, vector<int> &dp)
		{
			if(n == 0 || n == 1)
				return n;

			if(dp[n] != -1)
				return dp[n];

			return dp[n] = (solve(n-1, dp) + solve(n-2, dp)) % MOD;
		}
	public:
		int nthFibonacci(int n)
		{
			vector<int> dp(n+1, -1);

			dp[0] = 0;
			dp[1] = 1;

			for(int i = 2; i <= n; i++)
			{
				dp[i] = (dp[i-1] + dp[i-2])%MOD;
			}

			return dp[n];
		}
};

class Solution   // Space Optimization
{

	private:
		const int MOD = 1e9 + 7;

	public:
		int nthFibonacci(int n)
		{
			int prev_2 = 0;
			int prev_1 = 1;

			if(n == 0)
				return 0;

			for(int i = 2; i <= n; i++)
			{
				int curr = (prev_2 + prev_1)%MOD;
				prev_2 = prev_1;
				prev_1 = curr;
			}

			return (prev_1);

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
