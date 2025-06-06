/*
There is one meeting room in a firm. There are n meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time? Return the maximum number of meetings that can be held in the meeting room.



Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.


Examples :

Input: n = 6, start[] = {1,3,0,5,8,5}, end[] =  {2,4,6,7,9,9}
Output: 4
Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
Input: n = 3, start[] = {10, 12, 20}, end[] = {20, 25, 30}
Output: 1
Explanation: Only one meetings can be held with given start and end timings.
Expected Time Complexity : O(n*Logn)
Expected Auxilliary Space : O(n)


Constraints:
1 = n = 105
0 = start[i] < end[i] = 105


*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution // https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
{
		static bool cmp(pair<int, int> a, pair<int, int> b)
		{
			return a.second < b.second;
		}
	public:
		//Function to find the maximum number of meetings that can
		//be performed in a meeting room.
		int maxMeetings(int start[], int end[], int n)
		{
			vector<pair<int, int> > meetingsTiming;

			for(int i = 0; i < n; i++)
			{
				pair<int, int> p = {start[i], end[i]};
				meetingsTiming.push_back(p);
			}

			sort(meetingsTiming.begin(), meetingsTiming.end(), cmp);

			int count = 1;
			int ending = meetingsTiming[0].second;

			for(int i = 1; i < n; i++)
			{
				if(meetingsTiming[i].first > ending)
				{
					count++;
					ending = meetingsTiming[i].second;
				}
			}

			return count;
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
		int start[n], end[n];
		for (int i = 0; i < n; i++) cin >> start[i];

		for (int i = 0; i < n; i++) cin >> end[i];

		Solution ob;
		int ans = ob.maxMeetings(start, end, n);
		cout << ans << endl;
	}
	return 0;
}
// } Driver Code Ends
