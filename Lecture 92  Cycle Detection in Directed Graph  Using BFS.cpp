//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution // https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
{
	public:
		// Function to detect cycle in a directed graph.
		bool isCyclic(int V, vector<int> adj[])
		{
			vector<int> indegree(V);

			for(int i = 0; i < V; i++)
			{
				for(int j : adj[i])
				{
					indegree[j]++;
				}
			}

			queue<int> Q;

			for(int i = 0; i < V; i++)
			{
				if(indegree[i] == 0)
				{
					Q.push(i);
				}
			}

			int count = 0;

			while(!Q.empty())
			{
				int front = Q.front();
				Q.pop();

				count++;

				for(int neighbour : adj[front])
				{
					indegree[neighbour]--;
					if(indegree[neighbour] == 0)
					{
						Q.push(neighbour);
					}
				}
			}

			if (count == V)
				return false;
			else
				return true;

		}
};

//{ Driver Code Starts.

int main()
{

	int t;
	cin >> t;
	while (t--)
	{
		int V, E;
		cin >> V >> E;

		vector<int> adj[V];

		for (int i = 0; i < E; i++)
		{
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
