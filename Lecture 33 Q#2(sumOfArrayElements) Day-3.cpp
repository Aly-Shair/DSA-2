//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
	private:
		void solve(int* arr, int n, int &ans)
		{	
			if(n == 0) // no need
				return;
				
			if(n == 1)
			{
				ans += arr[0];
				return;
			}

			ans += (arr[0]);

			solve(arr+1, n-1, ans);
		}

		int solve2(int* arr, int n)
		{
			if(n == 0) // no need
				return 0;

			if(n == 1)
			{
				return arr[0];
			}

			return (arr[0] + solve2(arr+1, n-1));
		}
	public:
		// function to return sum of elements
		// in an array of size n
		int sum(int arr[], int n)
		{
			int ans = 0;
			solve(arr, n, ans);
			return ans;
		}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, i;
		cin >> n;
		int arr[n];
		for (i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		Solution ob;
		auto ans = ob.sum(arr, n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
