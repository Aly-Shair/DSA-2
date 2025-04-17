/*
Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

Example 1:

Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8
Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.
Your Task:
Your task is to complete the function maxArea which returns the maximum size rectangle area in a binary-sub-matrix with all 1’s. The function takes 3 arguments the first argument is the Matrix M[ ] [ ] and the next two are two integers n and m which denotes the size of the matrix M.

Expected Time Complexity : O(n*m)
Expected Auixiliary Space : O(m)

Constraints:
1<=n,m<=1000
0<=M[][]<=1
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution // https://www.geeksforgeeks.org/problems/max-rectangle/1
{
		vector<int> previousPoint(int heights[], int n)
		{
			stack<int> s;
			vector<int> ans(n);
			s.push(-1);
			for(int i = 0; i < n; i++)
			{
				int curr = heights[i];
				while(s.top() != -1 && heights[s.top()] >= curr)
				{
					s.pop();
				}
				ans[i] = s.top();
				s.push(i);
			}
			return ans;
		}
		vector<int> nextPoint(int heights[], int n)
		{
			stack<int> s;
			vector<int> ans(n);
			s.push(-1);
			for(int i = n-1; i >= 0; i--)
			{
				int curr = heights[i];
				while(s.top() != -1 && heights[s.top()] >= curr)
				{
					s.pop();
				}
				ans[i] = s.top();
				s.push(i);
			}
			return ans;
		}
		int largestAreaInHistogram(int heights[], int n)
		{
			vector<int> pre, next;
			pre = previousPoint(heights, n);
			next = nextPoint(heights, n);
			int area = 0;
			for(int i = 0; i < n; i++)
			{
				int h = heights[i];
				if(next[i] == -1)
				{
					next[i] = n;
				}

				int w = next[i] - pre[i] - 1;
				int newArea = h*w;
				area = max(newArea, area);
			}
			return area;
		}
	public:
		int maxArea(int M[MAX][MAX], int n, int m)
		{
			int area = largestAreaInHistogram(M[0], m);

			for(int i = 1; i < n; i++)
			{
				for(int j = 0; j < m; j++)
				{
					if(M[i][j] != 0)
						M[i][j] += M[i-1][j];
					else
						M[i][j] = 0;
				}

				area = max(area, largestAreaInHistogram(M[i], m));
			}

			return area;
		}
};


//{ Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	int M[MAX][MAX];

	while (T--)
	{
		int n, m;
		cin >> n >> m;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> M[i][j];
			}
		}
		Solution obj;
		cout << obj.maxArea(M, n, m) << endl;
	}
}

// } Driver Code Ends
