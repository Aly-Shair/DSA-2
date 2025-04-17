#include<iostream>
using namespace std;
// https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1
class Solution // recursive
{
	private:
		int solve(vector<int> &num, int target)
		{
			if(target == 0)
				return 0;

			if(target < 0)
				return INT_MAX;

			int mini = INT_MAX;

			for(int i = 0; i < num.size(); i++)
			{
				int ans = solve(num, target-num[i]);
				if(ans != INT_MAX)
					mini = min(ans+1, mini);
			}
			return mini;
		}
	public:
		int minCoins(vector<int> &num, int target)
		{
			int ans = solve(num, target);

			if(ans != INT_MAX)
				return ans;

			return -1;
		}
};

class Solution // recursive + memoization
{
	private:
		int solve(vector<int> &num, int target, vector<int> &dp)
		{
			if(target == 0)
				return 0;

			if(target < 0)
				return INT_MAX;

			if(dp[x] != -1)
				return dp[x];

			int mini = INT_MAX;

			for(int i = 0; i < num.size(); i++)
			{
				int ans = solve(num, target-num[i]);
				if(ans != INT_MAX)
					mini = min(ans+1, mini);
			}

			dp[x] = mini;
			return dp[x];
		}
	public:
		int minCoins(vector<int> &num, int target)
		{
			vector<int> dp(target+1, -1);
			int ans = solve(num, target, dp);

			if(ans != INT_MAX)
				return ans;

			return -1;
		}
};

class Solution // tabulation
{
	private:
		int solve(vector<int> &num, int target)
		{
			vector<int> dp(target+1, INT_MAX);

			dp[0] = 0;

			for(int i = 1; i <= target; i++)
			{
				for(int j = 0; j < num.size(); j++)
				{
					if(i-num[j] >= 0 and dp[i-num[j]] != INT_MAX)
						dp[i] = min(dp[i], 1+dp[i-num[j]]);
				}
			}

			if(dp[target] == INT_MAX)
				return -1;
			else
				return dp[target];
		}
	public:
		int minCoins(vector<int> &num, int target)
		{
			return solve(num, target);
		}
};

class Solution // space optimization not possible
{
		
	public:
		int minCoins(vector<int> &num, int target)
		{
			
		}
};

int main()
{

	

	return 0;
}
