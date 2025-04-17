//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	private:
		bool cycleDetectionBST(int node, vector<int> adj[], unordered_map<int, bool > &visited) {
			map<int, int> parent;
			queue<int> q;

			q.push(node);
			visited[node] = true;
			parent[node] = -1;

			while(!q.empty()) {
				int front = q.front();
				q.pop();

				for(auto neighbour : adj[front]) {
					if(visited[neighbour] and parent[front] != neighbour) {
						return true;
					} else if(!visited[neighbour]) {
						q.push(neighbour);
						visited[neighbour] = true;
						parent[neighbour] = front;
					}
				}
			}

			return false;
		}

		bool cycleDetectionDFS(int node, int parent, vector<int> adj[], unordered_map<int, bool > &visited) {
			visited[node] = true;

			for(auto neighbour : adj[node]) {
				if(!visited[neighbour]) {
					bool isCycleDetected = cycleDetectionDFS(neighbour, node, adj, visited);
					if(isCycleDetected)
						return true;
				} else if(neighbour != parent) {
					return true;
				}
			}

			return false;
		}
	public:
		// Function to detect cycle in an undirected graph.
		bool isCycle(int V, vector<int> adj[]) {

			unordered_map<int, bool > visited;

			for(int i = 0; i < V; i++) {
				if(!visited[i]) {
					bool ans = cycleDetectionDFS(i, -1, adj, visited);
					if(ans) {
						return true;
					}
				}
			}

			return false;


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
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if (ans)
			cout << "1\n";
		else
			cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends
