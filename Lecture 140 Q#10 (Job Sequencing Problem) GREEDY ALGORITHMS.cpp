/*
Job Sequencing Problem
Difficulty: MediumAccuracy: 34.51%Submissions: 217K+Points: 4
Given a set of N jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job. Deadline of the job is the time before which job needs to be completed to earn the profit.


Example 1:

Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).
Example 2:

Input:
N = 5
Jobs = {(1,2,100),(2,1,19),(3,2,27),
        (4,1,25),(5,1,15)}
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).

Your Task :
You don't need to read input or print anything. Your task is to complete the function JobScheduling() which takes an integer N and an array of Jobs(Job id, Deadline, Profit) as input and returns the count of jobs and maximum profit as a list or vector of 2 elements.


Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(N)


Constraints:
1 <= N <= 105
1 <= Deadline <= N
1 <= Profit <= 500
*/

//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include<bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
	int id;	 // Job Id
	int dead; // Deadline of job
	int profit; // Profit if job is over before or on deadline
};


// } Driver Code Ends
/*
struct Job
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class cmp
{
	public:
		bool operator()(Job a, Job b)
		{
			return a.profit > b.profit;
		}
};

class Solution // https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
{
		static bool acmp(Job a, Job b)
		{
			return a.profit > b.profit;
		}
	public:
		//Function to find the maximum profit and the number of jobs done.
		vector<int> JobScheduling(Job arr[], int n)
		{

			sort(arr, arr+n, cmp());

			int maxDedline = INT_MIN;
			for(int i = 0; i < n; i++)
			{
				maxDedline = max(maxDedline, arr[i].dead);
			}

			vector<int> shedule(maxDedline+1, -1);

			int jobsDone = 0;
			int maxProfit = 0;

			for(int i = 0; i < n; i++)
			{
				int currProfit = arr[i].profit;
				int currDeadline = arr[i].dead;
				int currID = arr[i].id;

				for(int k = currDeadline; k > 0; k--) // 0 to deadline loop not works
				{
					if(shedule[k] == -1)
					{
						jobsDone++;
						shedule[k] = currID;
						maxProfit += currProfit;
						break;
					}
				}
			}

			vector<int> ans;
			ans.push_back(jobsDone);
			ans.push_back(maxProfit);
			return ans;
		}
};

//{ Driver Code Starts.
// Driver program to test methods
int main()
{
	int t;
	//testcases
	cin >> t;

	while(t--)
	{
		int n;

		//size of array
		cin >> n;
		Job arr[n];

		//adding id, deadline, profit
		for(int i = 0; i<n; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;
			arr[i].id = x;
			arr[i].dead = y;
			arr[i].profit = z;
		}
		Solution ob;
		//function call
		vector<int> ans = ob.JobScheduling(arr, n);
		cout<<ans[0]<<" "<<ans[1]<<endl;
	}
	return 0;
}



// } Driver Code Ends
