//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

bool detectCycle(int node,  unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, vector<int> adj[]) {
	visited[node] = true;
	dfsVisited[node] = true;

	for(auto neighbour : adj[node]) {
		if(!visited[neighbour]) {
			bool detected = detectCycle(neighbour, visited, dfsVisited, adj);
			if(detected)
				return true;
		} else if(dfsVisited[neighbour]) {
			return true;
		}
	}

	dfsVisited[node] = false;
	return false;
}

class Solution { // https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
	public:
		// Function to detect cycle in a directed graph.
		bool isCyclic(int V, vector<int> adj[]) {
			unordered_map<int, bool> visited;
			unordered_map<int, bool> dfsVisited;

			for(int i = 0; i < V; i++) {
				if(!visited[i]) {
					bool ans = detectCycle(i, visited, dfsVisited, adj);
					if(ans)
						return true;
				}
			}

			return false;
		}
};

//{ Driver Code Starts.

int main() {

	int t;
	cin >> t;
	while (t--) {
		int V, E;
		cin >> V >> E;

		vector<int> adj[V];

		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}

		Solution obj;
		cout << obj.isCyclic(V, adj) << "\n";
	}

	return 0;
}

// } Driver Code Ends
