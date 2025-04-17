/*
Given a keypad as shown in the diagram, and an N digit number which is represented by array a[ ], the task is to list all words which are possible by pressing these numbers.


Example 1:

Input: N = 3, a[] = {2, 3, 4}
Output:
adg adh adi aeg aeh aei afg afh afi
bdg bdh bdi beg beh bei bfg bfh bfi
cdg cdh cdi ceg ceh cei cfg cfh cfi
Explanation: When we press 2,3,4 then
adg, adh, adi, ... cfi are the list of
possible words.
Example 2:

Input: N = 3, a[] = {3, 4, 5}
Output:
dgj dgk dgl dhj dhk dhl dij dik dil
egj egk egl ehj ehk ehl eij eik eil
fgj fgk fgl fhj fhk fhl fij fik fil
Explanation: When we press 3,4,5 then
dgj, dgk, dgl, ... fil are the list of
possible words.
*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution // https://www.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1
{
		void solve(int a[], int N, string output, int idx, string mapping[], vector<string> &ans)  // without backtracking
		{
			if(idx >= N)
			{
				ans.push_back(output);
				return;
			}

			int number = a[idx];
			string value = mapping[number];

			for(int i = 0; i < value.size(); i++)
			{
				solve(a, N, output + value[i], idx+1, mapping, ans);
			}
		}

		void solve(int a[], int N, string output, int idx, string mapping[], vector<string> &ans)  // with backtracking
		{
			if(idx >= N)
			{
				ans.push_back(output);
				return;
			}

			int number = a[idx];
			string value = mapping[number];

			for(int i = 0; i < value.size(); i++)
			{
				output.push_back(value[i]);
				solve(a, N, output, idx+1, mapping, ans);
				output.pop_back();
			}
		}
	public:
		//Function to find list of all words possible by pressing given numbers.
		vector<string> possibleWords(int a[], int N)
		{
			vector<string> ans;
			string mapping[10] = {"", "" , "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
			string output;
			int idx = 0;

			solve(a, N, output, idx, mapping, ans);
			return ans;
		}
};


//{ Driver Code Starts.

int main()
{

	int T;

	cin >> T; //testcases

	while(T--)  //while testcases exist
	{
		int N;

		cin >> N; //input size of array

		int a[N]; //declare the array

		for(int i =0; i<N; i++)
		{
			cin >> a[i]; //input the elements of array that are keys to be pressed
		}

		Solution obj;

		vector <string> res = obj.possibleWords(a,N);
		for (string i : res) cout << i << " ";
		cout << endl;
	}

	return 0;
}
// } Driver Code Ends

/*
Best solution better than sir no mapping required.


void solve(string num,string ans,int index)
{
	if(num[index] == '\0')
	{
		cout<<"ans.  "<<ans<<endl;
		return;
	}
	int number= num[index]-'0';
	int i=3;
	char start='a'+ (number-2)*3;

	if(number == 7 || number == 9)
	{
		i=4;
	}
	if(number==8 || number==9)
	{
		start= start+1;
	}
	int count=0;
	char j=start;
	while(count<i)
	{
		ans+=j;
		solve(num,ans,index+1);
		ans.pop_back();
		count++;
		j=j+1;

	}

}


*/
