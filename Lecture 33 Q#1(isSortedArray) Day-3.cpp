//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution   // https://www.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1
{
	public:
		bool arraySortedOrNot(int arr[], int n)
		{
			if(n == 0 || n == 1)
				return true;

			if(arr[0] > arr[1])
				return false;
			else
			{
				return arraySortedOrNot(arr+1, n-1);
			}
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
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		Solution ob;
		bool ans = ob.arraySortedOrNot(arr, n);
		cout << ans << "\n";
	}
	return 0;
}

// } Driver Code Ends
