//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution { // https://www.geeksforgeeks.org/problems/n-queen-problem0315/1
		void addSolution( vector<vector<int> > &ans,  vector<vector<int> > &board, int n) {
			vector<int> temp;
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					if(board[i][j] == 1) {
						temp.push_back(j+1);
					}
				}
			}
			ans.push_back(temp);
		}

		bool isSafe(int row, int col, vector<vector<int> > &board, int n) {
			int x = row;
			int y = col;

			while(x >= 0) {
				if(board[x][y] == 1)
					return false;
				x--;
			}

			x = row;
			y = col;

			while(x >= 0 && y >= 0) {
				if(board[x][y] == 1)
					return false;
				x--;
				y--;
			}

			x = row;
			y = col;

			while(x >= 0 && y < n) {
				if(board[x][y] == 1)
					return false;
				x--;
				y++;
			}

			return true;
		}

		void solve(int row,  vector<vector<int> > &ans,  vector<vector<int> > &board, int n) {
			if(row >= n) {
				addSolution(ans, board, n);
				return;
			}

			for(int col = 0; col < n; col++) {
				if(isSafe(row, col, board, n)) {
					board[row][col] = 1;
					solve(row+1, ans, board, n);
					board[row][col] = 0;
				}
			}
		}

	public:
		vector<vector<int>> nQueen(int n) {
			vector<vector<int> > ans;
			vector<vector<int> > board(n, vector<int>(n, 0));

			solve(0, ans, board, n);;

			return ans;

		}
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;

		Solution ob;
		vector<vector<int>> ans = ob.nQueen(n);
		if(ans.size() == 0)
			cout<<-1<<"\n";
		else {
			for(int i = 0; i < ans.size(); i++) {
				cout<<"[";
				for(int u: ans[i])
					cout<<u<<" ";
				cout<<"] ";
			}
			cout<<endl;
		}
	}
	return 0;
}
// } Driver Code Ends
