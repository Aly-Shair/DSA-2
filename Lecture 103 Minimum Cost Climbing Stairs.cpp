//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++


class Solution
{
		int solve(vector<int> &cost, int N)
		{
			if(N == 0)
				return cost[0];

			if(N == 1)
				return cost[1];

			int mini = cost[N] + min(solve(cost, N-1), solve(cost, N-2));
			return mini;
		}
	public:
		int minCostClimbingStairs(vector<int>&cost ,int N)
		{
			int ans = min(solve(cost, N-1), solve(cost, N-2));
			return ans;
		}
};


/*
class Solution {
    int solve(vector<int> &cost, int N, vector<int> &dp){
        if(N == 0)
            return cost[0];

        if(N == 1)
            return cost[1];

        if(dp[N] != -1)
            return dp[N];

        dp[N] = cost[N] + min(solve(cost, N-1, dp), solve(cost, N-2, dp));
        return dp[N];
    }
  public:
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        vector<int> dp(N+1, -1);
        int ans = min(solve(cost, N-1, dp), solve(cost, N-2, dp));
        return ans;
    }
};
*/
/*
class Solution {

  public:
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        vector<int> dp(N+1, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < N; i++){
            dp[i] = min(dp[i-2], dp[i-1]) + cost[i];
        }

        dp[N] = min(dp[N-2], dp[N-1]);

        return dp[N];
    }
};
*/
/*
class Solution
{

	public:
		int minCostClimbingStairs(vector<int>&cost ,int N)
		{
			if(N == 0 || N == 1)
				return cost[N];

			int prev_2 = cost[0];
			int prev_1 = cost[1];

			int minCost = 0;

			for(int i = 2; i < N; i++)
			{
				minCost = min(prev_2, prev_1) + cost[i];
				prev_2 = prev_1;
				prev_1 = minCost;
			}

			minCost = min(prev_2, prev_1);

			return minCost;
		}
};
*/

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int N;

		cin>>N;
		vector<int>cost(N);

		for(int i=0 ; i<N ; i++)
		{
			cin>>cost[i];
		}

		Solution ob;
		cout<<ob.minCostClimbingStairs(cost,N);
		cout<<"\n";
	}
	return 0;
}
// } Driver Code Ends
