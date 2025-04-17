//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
		void makeSet(vector<int> &rank, vector<int> &parent, int n)
		{
			for(int i = 0; i < n; i++)
			{
				rank[i] = 0;
				parent[i] = i;
			}
		}

		int findParent(vector<int> &parent, int node)
		{
			if(parent[node] == node)
			{
				return node;
			}

			return parent[node] = findParent(parent, parent[node]);
		}

		void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
		{
			u = findParent(parent, u);
			v = findParent(parent, v);

			if(rank[u] < rank[v])
			{
				parent[u] = v;
			}
			else if(rank[v] < rank[u])
			{
				parent[v] = u;
			}
			else
			{
				parent[v] = u;
				rank[u]++;
			}


		}

		static bool cmp(vector<int> &a, vector<int> &b)
		{
			return a[2] < b[2];
		}

		vector<vector<int>> adjListToEdgeList(vector<vector<int>> adj[], int numVertices)
		{
			vector<vector<int>> edges;

			// Iterate through each vertex
			for (int i = 0; i < numVertices; ++i)
			{
				// Iterate through the adjacency list of the vertex
				for (int j = 0; j < adj[i].size(); ++j)
				{
					int neighbor = adj[i][j][0];
					int weight = adj[i][j][1];
					// Add the edge (i, neighbor, weight) to the edge list
					edges.push_back({i, neighbor, weight});
				}
			}

			return edges;
		}

	public:
		//Function to find sum of weights of edges of the Minimum Spanning Tree.
		int spanningTree(int V, vector<vector<int>> adj[])
		{

			vector<vector<int>> edges = adjListToEdgeList(adj, V);
			sort(edges.begin(), edges.end(), cmp);
			vector<int> parent(V);
			vector<int> rank(V);
			makeSet(rank, parent, V);
			int ans = 0;


			for(int i = 0; i < edges.size(); i++)
			{
				int u = edges[i][0];
				int v = edges[i][1];
				int w = edges[i][2];

				u = findParent(parent, u);
				v = findParent(parent, v);

				if(u != v)
				{
					ans += w;
					unionSet(u, v, parent, rank);
				}
			}

			return ans;
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
		vector<vector<int>> adj[V];
		int i=0;
		while (i++<E)
		{
			int u, v, w;
			cin >> u >> v >> w;
			vector<int> t1,t2;
			t1.push_back(v);
			t1.push_back(w);
			adj[u].push_back(t1);
			t2.push_back(u);
			t2.push_back(w);
			adj[v].push_back(t2);
		}

		Solution obj;
		cout << obj.spanningTree(V, adj) << "\n";
	}

	return 0;
}


// } Driver Code Ends
