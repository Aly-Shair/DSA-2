//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends

#define MOD 1000000007

int add(int a, int b)
{
	return (a%MOD + b%MOD)%MOD;
}

int multi(int a, int b)
{
	return (a%MOD*1LL * b%MOD)%MOD;
}

class SolutionRec
{
	private:

		int solve(int n, int k)
		{
			if(n == 1)
				return k;

			if(n == 2)
				return add(k, multi(k, k-1));

			int ans = add(multi(solve(n-2, k), k-1), multi(solve(n-1, k), k-1));

			return ans;
		}

	public:
		long long countWays(int n, int k)
		{
			return solve(n, k);
		}
};


class SolutionMemo
{
	private:

		int solve(int n, int k, vector<int> &dp)
		{
			if(n == 1)
				return k;

			if(n == 2)
				return add(k, multi(k, k-1));

			if(dp[n] != -1)
				return dp[n];

			dp[n] = add(multi(solve(n-1, k, dp), k-1), multi(solve(n-2, k, dp), k-1));

			return dp[n];
		}

	public:
		long long countWays(int n, int k)
		{
			vector<int> dp(n+1, -1);
			return solve(n, k, dp);
		}
};

class SolutionTab
{
	private:

		int solve(int n, int k)
		{
			vector<int> dp(n+1, -1);


			dp[1] = k;
			dp[2] = add(k, multi(k, k-1));

			for(int i = 3; i <= n; i++)
			{
				dp[i] = add(multi(dp[i-1], k-1), multi(dp[i-2], k-1));
			}

			return dp[n];
		}

	public:
		long long countWays(int n, int k)
		{
			return solve(n, k);
		}
};

class Solution
{
	private:

		int solve(int n, int k)
		{

			if (n == 1) return k;
			if (n == 2) return add(k, multi(k, k - 1));

			int prev_2 = k;
			int prev_1 = add(k, multi(k, k-1));

			int ans = 0;

			for(int i = 3; i <= n; i++)
			{
				ans = add(multi(prev_2, k-1), multi(prev_1, k-1));

				prev_2 = prev_1;
				prev_1 = ans;
			}

			return ans;
		}

	public:
		long long countWays(int n, int k)
		{
			return solve(n, k);
		}
};


//{ Driver Code Starts.

int main()
{

	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends
