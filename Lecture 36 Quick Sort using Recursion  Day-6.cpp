//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// } Driver Code Ends
class Solution // https://www.geeksforgeeks.org/problems/quick-sort/1 
// Q # 1 why quick sort is prefered over merge sort for array
// Q # 2 why merge sort is prefered over quick sort for linked list
{
	public:
		// int partition (int arr[], int low, int high);
		//Function to sort an array using quick sort algorithm.
		void quickSort(int arr[], int low, int high)
		{
			if(low >= high)
			{
				return;
			}

			int idx = partition(arr, low, high);

			quickSort(arr, low, idx-1);
			quickSort(arr, idx+1, high);
		}

	public:
		int partition (int arr[], int low, int high)
		{
			int pivot = arr[low];
			int count = 0;

			for(int i = low+1; i <= high; i++)
			{
				if(arr[i] <= pivot)
				{
					count++;
				}
			}

			int pivotCorrectIdx = low+count;

			swap(arr[low], arr[pivotCorrectIdx]);

			int i = low;
			int j = high;

			while(i < pivotCorrectIdx && j > pivotCorrectIdx)
			{
				while(arr[i] <= pivot)
				{
					i++;
				}

				while(arr[j] > pivot)
				{
					j--;
				}
				if(i < pivotCorrectIdx && j > pivotCorrectIdx)
					swap(arr[i++], arr[j--]);
			}

			return pivotCorrectIdx;
		}
};


//{ Driver Code Starts.
int main()
{
	int arr[1000],n,T,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0; i<n; i++)
			scanf("%d",&arr[i]);
		Solution ob;
		ob.quickSort(arr, 0, n-1);
		printArray(arr, n);
	}
	return 0;
}
// } Driver Code Ends
