//{ Driver Code Starts
#include <bits/stdc++.h>
// https://www.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1
using namespace std;

///*
class Solution
{
		int solveRecurisve(int* nums, int n)
		{
			if(n < 0)
				return 0;

			if(n == 0)
				return nums[0];

			int include = solveRecurisve(nums, n-2) + nums[n];
			int exclude = solveRecurisve(nums, n-1) + 0;

			return max(include, exclude);
		}
	public:
		// calculate the maximum sum with out adjacent
		int findMaxSum(int *arr, int n)
		{
			int ans = solveRecurisve(arr, n-1);
			return ans;
		}
};
//*/
///*
class Solution
{
		int solveMemo(int* nums, int n, vector<int> &dp)
		{
			if(n < 0)
				return 0;

			if(n == 0)
				return nums[0];

			if(dp[n] != -1)
				return dp[n];

			int include = solveMemo(nums, n-2, dp) + nums[n];
			int exclude = solveMemo(nums, n-1, dp) + 0;

			dp[n] = max(include, exclude);

			return dp[n];
		}
	public:
		// calculate the maximum sum with out adjacent
		int findMaxSum(int *arr, int n)
		{
			vector<int> dp(n+1, -1);
			int ans = solveMemo(arr, n-1, dp);
			return ans;
		}
};
//*/


class Solution
{
		int solveTabu(int *nums,int  n)
		{
			vector<int> dp(n+1, -1);

			dp[0] = nums[0];

			for(int i = 1; i < n; i++)
			{
				int include = dp[i-2] + nums[i];
				int exclude = dp[i-1] + 0;

				dp[i] = max(include, exclude);
			}

			return dp[n-1];

		}
	public:
		// calculate the maximum sum with out adjacent
		int findMaxSum(int* arr, int n)
		{

			int ans = solveTabu(arr, n);
			return ans;
		}
};


class Solution
{
		int solveSO(int *nums,int  n)
		{

			int prev_2 = 0;
			int prev_1 = nums[0];

			for(int i = 1; i < n; i++)
			{
				int include = prev_2 + nums[i];
				int exclude = prev_1 + 0;

				int ans = max(include, exclude);
				prev_2 = prev_1;
				prev_1 = ans;
			}

			return prev_1;

		}
	public:
		// calculate the maximum sum with out adjacent
		int findMaxSum(int* arr, int n)
		{

			int ans = solveSO(arr, n);
			return ans;
		}
};

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		Solution ob;
		auto ans = ob.findMaxSum(arr, n);
		cout << ans << "\n";
	}
	return 0;
}
