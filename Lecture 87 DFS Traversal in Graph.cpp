/*
You are given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use the recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.


Example 1:

Input: V = 5 , adj = [[2,3,1] , [0], [0,4], [0], [2]]

Output: 0 2 4 3 1
Explanation:
0 is connected to 2, 3, 1.
1 is connected to 0.
2 is connected to 0 and 4.
3 is connected to 0.
4 is connected to 2.
so starting from 0, it will go to 2 then 4,
and then 3 and 1.
Thus dfs will be 0 2 4 3 1.
Example 2:

Input: V = 4, adj = [[1,3], [2,0], [1], [0]]

Output: 0 1 2 3
Explanation:
0 is connected to 1 , 3.
1 is connected to 0, 2.
2 is connected to 1.
3 is connected to 0.
so starting from 0, it will go to 1 then 2
then back to 0 then 0 to 3
thus dfs will be 0 1 2 3.

Your task:
You don't need to read input or print anything. Your task is to complete the function dfsOfGraph() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns a list containing the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)


Constraints:
1 = V, E = 104
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution { // https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
		void solve(int node, vector<int> &ans, unordered_map<int, bool> &visited, vector<int> adj[]) {

			ans.push_back(node);
			visited[node] = true;

			for(auto i : adj[node]) {
				if(!visited[i]) {
					solve(i, ans, visited, adj);
				}
			}
		}
	public:
		// Function to return a list containing the DFS traversal of the graph.
		vector<int> dfsOfGraph(int V, vector<int> adj[]) {
			unordered_map<int, bool> visited;
			vector<int> ans;
			solve(0, ans, visited, adj);

			return ans;
		}
};

//{ Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int V, E;
		cin >> V >> E;

		vector<int> adj[V];

		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		// string s1;
		// cin>>s1;
		Solution obj;
		vector<int> ans = obj.dfsOfGraph(V, adj);
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
// } Driver Code Ends


/*For disconnected graph*/

class Solution { // https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
		void DFS(int node, vector<int> &component, unordered_map<int, bool> &visited, vector<int> adj[]) {

			component.push_back(node);
			visited[node] = true;

			for(auto i : adj[node]) {
				if(!visited[i]) {
					solve(i, component, visited, adj);
				}
			}
		}
	public:
		// Function to return a list containing the DFS traversal of the graph.
		vector<vector<int> > dfsOfGraph(int V, vector<int> adj[]) {
			unordered_map<int, bool> visited;
			vector<vector<int> > ans;

			for(int i = 0; i < V; i++) {
				if(!visited[i]) {
					vector<int> component;
					DFS(i, component, visited, adj);
					ans.push_back(component);
				}
			}

			return ans;
		}
};
