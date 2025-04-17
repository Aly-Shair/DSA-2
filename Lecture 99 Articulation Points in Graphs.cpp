//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

// Function to perform DFS and find articulation points
void DFS(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<int> &visited, vector<int> adj[], set<int> &articulationPoints)
{
	visited[node] = true;             // Mark the node as visited
	disc[node] = low[node] = timer++; // Initialize discovery and low time
	int children = 0;                 // Count of children in DFS tree

	for (auto neighbour : adj[node])
	{
		if (neighbour == parent)
			continue;                 // If the neighbour is the parent, skip it

		if (!visited[neighbour])      // If neighbour is not visited
		{
			children++;               // Increase the children count
		
			DFS(neighbour, node, timer, disc, low, visited, adj, articulationPoints); // Recursively DFS on the neighbour

			low[node] = min(low[neighbour], low[node]); // Update the low value of the node

			// Check if the node is an articulation point (not root)
			if (low[neighbour] >= disc[node] && parent != -1)
			{
				articulationPoints.insert(node);
			}
		}
		else
		{
			// Update low value for back edge
			low[node] = min(low[node], disc[neighbour]);
		}
	}

	// If node is root and has more than one child, it is an articulation point
	if (parent == -1 && children > 1)
	{
		articulationPoints.insert(node);
	}
}

class Solution
{
	public:
		vector<int> articulationPoints(int V, vector<int> adj[])
		{
			vector<int> disc(V, -1);       // Discovery times of visited vertices
			vector<int> low(V, -1);        // Lowest points reachable
			vector<int> visited(V, 0);     // Visited vertices
			int parent = -1;               // Parent of the current node
			int timer = 0;                 // Timer for discovery times
			set<int> articulationPoints;   // Store unique articulation points

			for (int i = 0; i < V; i++)
			{
				if (!visited[i])
				{
					DFS(i, parent, timer, disc, low, visited, adj, articulationPoints);
				}
			}

			vector<int> result(articulationPoints.begin(), articulationPoints.end());
			if (result.empty())
				result.push_back(-1);      // If no articulation points, return -1

			return result;
		}
};

//{ Driver Code Starts.

int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
