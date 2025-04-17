//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution // https://geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
{
		void dfs(int node, vector<bool> &visited, stack<int> &sorted, vector<vector<int>> &adj)
		{
			{
				visited[node] = true;

				for(auto nbr : adj[node])
				{
					if(!visited[nbr])
					{
						dfs(nbr, visited, sorted, adj);
					}
				}

				sorted.push(node);
			}
		}

		void revDFS(int node, vector<bool> &visited, vector<vector<int> > &transpose)
		{
			visited[node] = true;

			for(auto nbr : transpose[node])
			{
				if(!visited[nbr])
				{
					revDFS(nbr, visited, transpose);
				}
			}
		}
	public:
		//Function to find number of strongly connected components in the graph.
		int kosaraju(int V, vector<vector<int>>& adj)
		{
			vector<bool> visited(V, 0);
			stack<int> sorted;

			for(int i = 0; i < V; i++)
			{
				if(!visited[i])
				{
					dfs(i, visited, sorted, adj);
				}
			}

			vector<vector<int> > transpose(V);

			for(int i = 0; i < V; i++)
			{
				visited[i] = 0;
				for(auto nbr : adj[i])
				{
					transpose[nbr].push_back(i);
				}
			}

			int count = 0;

			while(!sorted.empty())
			{
				int top = sorted.top();
				sorted.pop();
			
				if(!visited[top])
				{
					count++;
					revDFS(top, visited, transpose);
				}
			}

			return count;
		}
};

//{ Driver Code Starts.


int main()
{

	int t;
	cin >> t;
	while(t--)
	{
		int V, E;
		cin >> V >> E;

		vector<vector<int>> adj(V);

		for(int i = 0; i < E; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}

		Solution obj;
		cout << obj.kosaraju(V, adj) << "\n";
	}

	return 0;
}


// } Driver Code Ends
