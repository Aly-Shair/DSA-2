//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
	public:
		// Function to search x in arr
		// arr: input array
		// X: element to be searched for
		int search(int arr[], int N, int X)
		{

			if(N == 0)
			{
				return -1;
			}

			if(arr[0] == X)
				return 0;


			int ans = search(arr+1, N-1, X);

			if(ans >= 0)
			{
				return ans+1;
			}
			else
			{
				return ans;
			}

		}

};

//{ Driver Code Starts.

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
		int sizeOfArray;
		cin>>sizeOfArray;
		int arr[sizeOfArray];
		int x;

		for(int i=0; i<sizeOfArray; i++)
		{
			cin>>arr[i];
		}
		cin>>x;
		Solution ob;
		cout<<ob.search(arr,sizeOfArray,x)<<endl; //Linear search
	}

	return 0;

}

// } Driver Code Ends
