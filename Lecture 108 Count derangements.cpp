#include<bits/stdc++.h>
using namespace std;

class SolutionRec
{
		int countDisarrangements(int n)
		{
			if(n == 1)
				return 0;

			if(n == 2)
				return 1;

			return (n-1)*(countDisarrangements(n-1) + countDisarrangements(n-2));
		}
};

class SolutionMemo
{

		int solve(int n, vector<int> &dp)
		{
			if(n == 1)
				return 0;

			if(n == 2)
				return 1;

			if(dp[n] != -1)
				return dp[n];

			dp[n] =  (n-1)*(countDisarrangements(n-1, dp) + countDisarrangements(n-2, dp));
			return dp[n];
		}
		int countDisarrangements(int n)
		{
			vector<int> dp(n+1, -1);
			return solve(n, dp);
		}
};

class SolutionTab
{

		int solve(int n)
		{
			vector<int> dp(n+1, 0);

			dp[1] = 0;
			dp[2] = 1;

			for(int i = 3; i <= n; i++)
			{
				int first = dp[i-1];
				int second = dp[i-2];

				int sum = first+second;

				dp[i] = (i-1)*sum;
			}

			return dp[n];
		}
		int countDisarrangements(int n)
		{

			return solve(n);

		}
};

class SolutionSpaceOpt
{

		int solve(int n)
		{

			int prev_2 = 0;
			int prev_1 = 1;

			for(int i = 3; i <= n; i++)
			{
				int first = prev_1;
				int second = prev_2;

				int sum = first+second;

				int ans  = (i-1)*sum;


				prev_2 = prev_1;
				prev_1 = ans;
			}

			return prev_1;
		}
		int countDisarrangements(int n)
		{

			return solve(n);

		}
};

int main()
{



	return 0;
}
