//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	private:
		void merge(vector<int> &arr, int s, int e)
		{
			int mid = (s+e)/2;
			int len_1 = mid-s+1;
			int len_2 = e-mid;

			// create arry 1
			int *arr_1 = new int[len_1];
			// create arry 2
			int *arr_2 = new int[len_2];

			int mainArrayIdx = s;

			// copying values in arry 1
			for(int i = 0; i < len_1; i++)
			{
				arr_1[i] = arr[mainArrayIdx++];
			}

			// copying values in arry ?
			for(int i = 0; i < len_2; i++)
			{
				arr_2[i] = arr[mainArrayIdx++];
			}


			int idx_1 = 0;
			int idx_2 = 0;
			mainArrayIdx = s;

			// merge two sorted arrays
			while(idx_1 < len_1 && idx_2 < len_2)
			{
				if(arr_1[idx_1] > arr_2[idx_2])
				{
					arr[mainArrayIdx++] = arr_2[idx_2++];
				}
				else
				{
					arr[mainArrayIdx++] = arr_1[idx_1++];
				}
			}

			while(idx_1 < len_1)
			{
				arr[mainArrayIdx++] = arr_1[idx_1++];
			}

			while(idx_2 < len_2)
			{
				arr[mainArrayIdx++] = arr_2[idx_2++];
			}

			delete []arr_1;
			delete []arr_2;
		}

		void mergeSort(vector<int> &arr, int s, int e)
		{
			if(s >= e)
			{
				return;
			}

			int mid = (s+e)/2;

			mergeSort(arr, s, mid);

			mergeSort(arr, mid+1, e);

			merge(arr, s, e);
		}
	public:
		vector<int> sortArr(vector<int>arr, int n)
		{
			mergeSort(arr, 0, n-1);
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
