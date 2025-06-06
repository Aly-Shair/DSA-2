// https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		// Function to return the adjacency list for each vertex.
		vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
			vector<vector<int> > ans(V);


			for(int i = 0; i < edges.size(); i++) {
				int u = edges[i].first;
				int v = edges[i].second;

				ans[u].push_back(v);
				ans[v].push_back(u);
			}

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
		vector<pair<int,int>>edges;
		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		vector<vector<int>> adj = obj.printGraph(V, edges);
		for(int i=0; i<V; i++) {
			sort(adj[i].begin(),adj[i].end());
			for(auto it:adj[i])
				cout<<it<<" ";
			cout<<endl;
		}
	}
	return 0;
}
// } Driver Code Ends
