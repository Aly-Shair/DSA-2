// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++


class Solution {

		bool isSafe(int newX, int newY, vector<vector<int>> &arr, vector<vector<bool> > visited, int n) {
			if((newX >= 0 and newX < n) and (newY >= 0 and newY < n) and (arr[newX][newY] != 0 and visited[newX][newY] != 1))
				return true;
			else
				return false;
		}

		void solve(int x, int y, vector<vector<int>> &arr, vector<vector<bool> > &visited,vector<string> &ans, string path, int n) {
			if(x == n-1 and y == n-1) {
				ans.push_back(path);
				return;
			}

			visited[x][y] = true;

			if(isSafe(x+1, y, arr, visited, n)) {
				solve(x+1, y, arr, visited, ans, path + "D", n);
			}

			if(isSafe(x, y-1, arr, visited, n)) {
				solve(x, y-1, arr, visited, ans, path + "L", n);
			}

			if(isSafe(x, y+1, arr, visited, n)) {
				solve(x, y+1, arr, visited, ans, path + "R", n);
			}

			if(isSafe(x-1, y, arr, visited, n)) {
				solve(x-1, y, arr, visited, ans, path + "U", n);
			}

			visited[x][y] = false;
		}
	public:
		vector<string> findPath(vector<vector<int>> &arr, int n) {
			vector<string> ans;

			if(arr[0][0] == 0) {
				ans.push_back("-1");
				return ans;
			}
			string path = "";
			vector<vector<bool> > visited(n, vector<bool>(n, false));

			solve(0, 0, arr, visited, ans, path, n);

			return ans;
		}
};




//{ Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> m(n, vector<int> (n,0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> m[i][j];
			}
		}
		Solution obj;
		vector<string> result = obj.findPath(m, n);
		sort(result.begin(), result.end());
		if (result.size() == 0)
			cout << -1;
		else
			for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
		cout << endl;
	}
	return 0;
}
// } Driver Code Ends
