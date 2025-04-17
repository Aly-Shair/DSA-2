//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution // https://www.geeksforgeeks.org/problems/bridge-edge-in-graph/1
{
		void dfs(int node, int &parent, vector<int> &disc, vector<int> &low, vector<int> &visited, vector<int> adj[], int &timer, vector<vector<int>> &bridges)
		{
			visited[node] = true;
			disc[node] = low[node] = timer++;

			for(auto neighbour : adj[node])
			{
				if(neighbour == parent)
					continue;

				if(!visited[neighbour])
				{
					dfs(neighbour, node, disc, low, visited, adj, timer, bridges);
					low[node] = min(low[node], low[neighbour]);

					if(low[neighbour] > disc[node])
					{
						vector<int> ans;
						ans.push_back(node);
						ans.push_back(neighbour);
						bridges.push_back(ans);
					}

				}
				else
				{
					// visited ha or parent bhi nahi ha

					low[node] = min(low[node], disc[neighbour]);
				}
			}
		}
	public:
		//Function to find if the given edge is a bridge in graph.
		int isBridge(int V, vector<int> adj[], int c, int d)
		{
			vector<int> disc(V, -1);
			vector<int> low(V, -1);
			vector<int> visited(V, false);
			int parent = -1;
			int timer = 0;
			vector<vector<int> > bridges;
			for(int i = 0; i < V; i++)
			{
				if(!visited[i])
					dfs(i, parent, disc, low, visited, adj, timer, bridges);
			}

			for(auto bridge : bridges)
			{
				if(bridge[0] == c and bridge[1] == d)
					return 1;
				else if(bridge[0] == d and bridge[1] == c)
					return 1;
			}

			return 0;

			if(low[d] > disc[c])
				return 1;
			else
				return 0;
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
		int i=0;
		while (i++<E)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back (v);
			adj[v].push_back (u);
		}

		int c,d;
		cin>>c>>d;

		Solution obj;
		cout << obj.isBridge(V, adj, c, d) << "\n";
	}

	return 0;
}


// } Driver Code Ends
