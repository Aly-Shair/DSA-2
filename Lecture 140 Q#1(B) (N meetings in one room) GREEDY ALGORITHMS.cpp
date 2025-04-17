/*
There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is the start time of meeting i and F[i] is the finish time of meeting i. The task is to find the maximum number of meetings that can be accommodated in the meeting room. You can accommodate a meeting if the start time of the meeting is strictly greater than the finish time of the previous meeting. Print all meeting numbers.

Note: If two meetings can be chosen for the same slot then choose meeting that finishes earlier.

Example 1:

Input:
N = 6
S = {1,3,0,5,8,5}
F = {2,4,6,7,9,9}
Output:
{1,2,4,5}
Explanation:
We can attend the 1st meeting from (1 to 2), then the 2nd meeting from (3 to 4), then the 4th meeting from (5 to 7), and the last meeting we can attend is the 5th from (8 to 9). It can be shown that this is the maximum number of meetings we can attend.
Example 2:

Input:
N = 1
S = {3}
F = {7}
Output:
{1}
Explanation:
Since there is only one meeting, we can attend the meeting.
Your Task:

You don't need to read input or print anything. Your task is to complete the function maxMeetings() which takes the arrays S, F, and its size N as inputs and returns the meeting numbers we can attend in sorted order.

Expected Time Complexity: O(N*log(N))
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 105
0 <= S[i] <= F[i] <= 109
Sum of N over all test cases doesn't exceeds 106
*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution  // https://www.geeksforgeeks.org/problems/maximum-meetings-in-one-room/0
{
		static bool cmp(vector<int> &a, vector<int> &b)
		{
			return a[1] < b[1];
		}
	public:
		vector<int> maxMeetings(int n,vector<int> &start,vector<int> &end)
		{
			vector<vector<int> > meetingsTiming;

			for(int i = 0; i < n; i++)
			{
				vector<int> temp;
				temp.push_back(start[i]);
				temp.push_back(end[i]);
				temp.push_back(i+1);
				meetingsTiming.push_back(temp);
			}

			sort(meetingsTiming.begin(), meetingsTiming.end(), cmp);

			vector<int> ans;
			ans.push_back(meetingsTiming[0][2]);
			int ending = meetingsTiming[0][1];

			for(int i = 1; i < n; i++)
			{
				if(meetingsTiming[i][0] > ending)
				{
					ans.push_back(meetingsTiming[i][2]);
					ending = meetingsTiming[i][1];
				}
			}

			sort(ans.begin(), ans.end()); // ans needed in sorted order

			return ans;
		}
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> S(n),F(n);
		for(int i=0; i<n; i++)
		{
			cin>>S[i];
		}
		for(int i=0; i<n; i++)
		{
			cin>>F[i];
		}
		Solution ob;
		vector<int> ans=ob.maxMeetings(n,S,F);
		for(int i=0; i<ans.size(); i++)
		{
			cout<<ans[i];
			if(i!=ans.size()-1)
			{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}
// } Driver Code Ends
