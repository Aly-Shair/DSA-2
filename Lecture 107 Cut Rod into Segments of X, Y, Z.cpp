//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

/*
class Solution
{   
    int solveRec(int n, int x, int y, int z){
        if(n == 0)
            return 0;
        if(n < 0)
            return INT_MIN;
        
        int a = solveRec(n-x, x, y, z) + 1;
        int b = solveRec(n-y, x, y, z) + 1;
        int c = solveRec(n-z, x, y, z) + 1;
        
        int ans = max(a,max(b,c));
        return ans;
    }
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int ans = solveRec(n, x, y, z);
        
        if(ans < 0)
            return 0;
        else
            return ans;
    }
};
*/

/*
class Solution
{   
    int solveMemo(int n, int x, int y, int z, vector<int> &dp){
        if(n == 0)
            return 0;
        if(n < 0)
            return INT_MIN;
        
        if(dp[n] != -1)
            return dp[n];
        
        int a = solveMemo(n-x, x, y, z, dp) + 1;
        int b = solveMemo(n-y, x, y, z, dp) + 1;
        int c = solveMemo(n-z, x, y, z,dp) + 1;
        
        dp[n] = max(a,max(b,c));
        return dp[n];
    }
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1, -1);
        int ans = solveMemo(n, x, y, z, dp);
        
        if(ans < 0)
            return 0;
        else
            return ans;
    }
};
*/
/*
class Solution
{   
    int solveTab(int n, int x, int y, int z){
        vector<int> dp(n+1, INT_MIN);
        
        dp[0] = 0;
        
        for(int i = 0; i <= n; i++){
            
            if(i-x >= 0)
                dp[i] = max(dp[i], dp[i-x] + 1);
            if(i-y >= 0)
                dp[i] = max(dp[i], dp[i-y] + 1);
            if(i-z >= 0)
                dp[i] = max(dp[i], dp[i-z] + 1);
        }
        
        if(dp[n] < 0)
        
            return 0;
        else
            return dp[n];
        
    }
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        return solveTab(n, x, y, z);
    }
};
*/

class Solution
{   
    int solveTab(int n, int x, int y, int z){
        vector<int> dp(n+1, -1);
        
        dp[0] = 0;
        
        for(int i = 0; i <= n; i++){
            
            if(i-x >= 0 and dp[i-x] != -1)
                dp[i] = max(dp[i], dp[i-x] + 1);
            if(i-y >= 0 and dp[i-y] != -1)
                dp[i] = max(dp[i], dp[i-y] + 1);
            if(i-z >= 0 and  dp[i-z] != -1)
                dp[i] = max(dp[i], dp[i-z] + 1);
        }
        
        if(dp[n] < 0)
        
            return 0;
        else
            return dp[n];
        
    }
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        return solveTab(n, x, y, z);
    }
};


/*space optimization not possible*/

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends
