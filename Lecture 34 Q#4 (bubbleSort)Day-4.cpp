//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	private:
		void solve(vector<int> &arr, int n)
		{
			if(n == 0 or n == 1)
			{
				return;
			}

			for(int i = 0; i < n-1; i++)
			{
				if(arr[i] > arr[i+1])
				{
					swap(arr[i], arr[i+1]);
				}
			}

			solve(arr, n-1);
		}
	public:
		vector<int> sortArr(vector<int>arr, int n)
		{
			solve(arr, n);
			return arr;
		}
};

//{ Driver Code Starts.
int main()
{

	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int>s(n);
		for(int i = 0; i < n; i++)
			cin >> s[i];
		Solution ob;
		vector<int>v = ob.sortArr(s, n);
		for(auto i : v)
			cout << i << ' ';
		cout << endl;
	}
	return 0;
}


// } Driver Code Ends
