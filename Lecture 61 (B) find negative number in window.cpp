#include<iostream>
#include<queue>
using namespace std;

// https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

/*
	Q: Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.
*/

void solve(int* arr, int n, int k){
	int* ans = new int[n-2];
	int neg = 0;
	for(int i = 0; i < n - 2; i++){
		neg = 0;
		for(int j = i; j < i + k; j++){
			if(arr[j] < 0){
				neg = arr[j];
				break;
			}
		}
		ans[i] = neg;	
	}
	
	for(int i = 0; i < n-2; i++){
		cout<<ans[i]<<", ";
	}cout<<endl;
}


vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
                                             
        deque<long long int> dq;
        vector<long long int> ans;
        
        for(int i = 0; i < K; i++){
            if(A[i] < 0){
                dq.push_back(i);
            }
        }
        
        if(dq.size() > 0){
            ans.push_back(A[dq.front()]);
        }else{
            ans.push_back(0);
        }
        
        for(int i = K; i < N; i++){
            if(!dq.empty() && i-dq.front() >= K){
                dq.pop_front();
            }
            
            if(A[i] < 0){
                dq.push_back(i);
            }
            
            if(dq.size() > 0){
                ans.push_back(A[dq.front()]);
            }else{
                ans.push_back(0);
            }
        }
        return ans;
 }

int main(){
	int arr[8] = {12, -1, -7, 8, -15, 30, 16, 28};
	solve(arr, 8, 3);
	return 0;
}


/*
geeksforgeeks
Tutorials
DSA
Data Science
Web Tech
Courses
S


First negative integer in every window of size k
MediumAccuracy: 48.61%Submissions: 139K+Points: 4
Internship Alert
New month-> Fresh Chance to top the leaderboard and get SDE Internship! 

banner
Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

 

Example 1:

Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6
 
Example 2:
Input : 
N = 8
A[] = {12, -1, -7, 8, -15, 30, 16, 28}
K = 3
Output :
-1 -1 -7 -15 -15 0 
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function printFirstNegativeInteger() which takes the array A[], its size N and an integer K as inputs and returns the first negative number in every window of size K starting from the first till the end. If a window does not contain a negative integer , then return 0 for that window.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(K)

Constraints:
1 <= N <= 105
-105 <= A[i] <= 105
1 <= K <= N

Company Tags
Topic Tags
If you are facing any issue on this page. Please let us know.
Output Window
Suggest Feedback
Problem Solved Successfully
You get marks only for the first correct submission if you solve the problem without viewing the full solution.
Test Cases Passed: 
10100 /10100
Your Total Score: 
4
Total Time Taken: 
0.45
Correct Submission Count: 
3
Attempts No.: 
5
Next Suggested Problem(s):
Count distinct elements in every window
Maximum of all subarrays of size k
Length of longest subarray
Suggested Contest:
Based on your excellent performance, we believe you are fully prepared to participate in this upcoming contest.
Suggested Contest Banner
GFG Weekly Coding Contest
Participate every Sunday at 7 PM. Practice DSA, compete with peers, win Geekbits !
Participate now
C++ (g++ 5.4)
Average Time: 15m
Your Time: 21m 11s



using namespace std;


 

Custom Input
Hint 1

 Full Solution

// function to find the first negative
// integer in every window of size k
vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k) {
    // A Double Ended Queue, Di that will store indexes of
    // useful array elements for the current window of size k.
    // The useful elements are all negative integers.
    deque<long long int> Di;
    vector<long long> ans;

    // Process first k (or first window) elements of array 
    long long int i;
    for (i = 0; i < k; i++)
        // Add current element at the rear of Di
        // if it is a negative integer
        if (arr[i] < 0) Di.push_back(i);

    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for (; i < n; i++) {
        // if Di is not empty then the element at the
        // front of the queue is the first negative integer
        // of the previous window
        if (!Di.empty()) ans.push_back(arr[Di.front()]);

        // else the window does not have a
        // negative integer
        else
            ans.push_back(0);

        // Remove the elements which are out of this window
        while ((!Di.empty()) && Di.front() < (i - k + 1))
            Di.pop_front(); // Remove from front of queue

        // Add current element at the rear of Di
        // if it is a negative integer
        if (arr[i] < 0) Di.push_back(i);
    }

    // Print the first negative
    // integer of last window
    if (!Di.empty())
        ans.push_back(arr[Di.front()]);
    else
        ans.push_back(0);

    return ans;
}
*/
