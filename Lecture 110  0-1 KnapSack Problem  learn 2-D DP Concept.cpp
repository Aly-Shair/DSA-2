//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
	public:

		int knapSack(int W, int wt[], int val[], int n)
		{

			if(n == 0 or W == 0)
			{
				return 0;
			}

			if(wt[n-1] > W)
			{
				return knapSack(W, wt, val, n-1);
			}

			return max(knapSack(W, wt, val, n-1), knapSack(W-wt[n-1], wt, val, n-1)+val[n-1]);

		}


		int solve(int W, int wt[], int val[], int n, vector<vector<int> > &dp)
		{
			if (W == 0 || n == 0)
				return 0;

			if (dp[n][W] != -1)
				return dp[n][W];

			if (wt[n-1] > W)
				return dp[n][W] = solve(W, wt, val, n-1, dp);

			int incl = solve(W-wt[n-1], wt, val, n-1, dp) + val[n-1];
			int excl = solve(W, wt, val, n-1, dp);

			dp[n][W] = max(incl, excl);

			return dp[n][W];
		}

		int knapSackMem(int W, int wt[], int val[], int n)
		{
			vector<vector<int> > dp(n+1, vector<int>(W+1, -1));
			return solve(W, wt, val, n, dp);
		}


		int knapSackTab(int W, int wt[], int val[], int n)
		{
			vector<vector<int> > dp(n+1, vector<int>(W+1, -1));

			for(int i = 0; i < n+1; i++)
			{
				for(int j = 0; j < W+1; j++)
				{
					if(i == 0 ||  j == 0)
						dp[i][j] = 0;
				}
			}

			for(int i = 1; i < n+1; i++)
			{
				for(int j = 1; j < W+1; j++)
				{
					if (wt[i-1] <= j)
					{
						int incl = dp[i-1][j-wt[i-1]] + val[i-1];
						int excl = dp[i-1][j];

						dp[i][j] = max(incl, excl);
					}
					else
					{
						dp[i][j] = dp[i-1][j];
					}

				}
			}

			return dp[n][W];

		}

		int knapSackSpaceOpt(int W, int wt[], int val[], int n) // space optmized to O(2*W)
		{
			vector<int> prev(W+1, 0);
			vector<int> curr(W+1, 0);

			for(int i = 1; i < n+1; i++)
			{
				for(int j = 1; j < W+1; j++)
				{
					if (wt[i-1] <= j)
					{
						int incl = prev[j-wt[i-1]] + val[i-1];
						int excl = prev[j];

						curr[j] = max(incl, excl);


					}
					else
					{
						curr[j] = prev[j];
					}


				}
				prev = curr;
			}

			return curr[W];

		}
		
		int knapSackSO(int W, int wt[], int val[], int n) { // space optimized to O(W)
      
        vector<int> curr(W+1, 0);
        
        for(int i = 1;i < n+1; i++){
            for(int j = W; j >= 0; j--){
                if (wt[i-1] <= j){
                    int incl = curr[j-wt[i-1]] + val[i-1];
                    int excl = curr[j];
        
                    curr[j] = max(incl, excl);
                    
                    
                }
                else{
                    curr[j] = curr[j];
                }
                
                    
            }
        }
        
        return curr[W];
        
    }

};

//{ Driver Code Starts.

int main()
{
	//taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
		//reading number of elements and weight
		int n, w;
		cin>>n>>w;

		int val[n];
		int wt[n];

		//inserting the values
		for(int i=0; i<n; i++)
			cin>>val[i];

		//inserting the weights
		for(int i=0; i<n; i++)
			cin>>wt[i];
		Solution ob;
		//calling method knapSack()
		cout<<ob.knapSack(w, wt, val, n)<<endl;

	}
	return 0;
}
// } Driver Code Ends
