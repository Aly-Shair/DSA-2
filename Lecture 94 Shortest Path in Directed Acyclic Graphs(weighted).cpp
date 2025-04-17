//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution // https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
{
	private:

		void topoSort(int node, vector<bool> &visited, stack<int> &topo, unordered_map<int, list<pair<int, int> > > &adjList)
		{
			visited[node] = true;
			for(auto i : adjList[node])
			{
				if(!visited[i.first])
				{
					topoSort(i.first, visited, topo, adjList);
				}
			}

			topo.push(node);
		}

	public:
		vector<int> shortestPath(int N,int M, vector<vector<int>>& edges)
		{
			unordered_map<int, list<pair<int, int> > >adjList;
			for(int i = 0; i < M; i++)
			{
				pair<int, int> p = make_pair(edges[i][1], edges[i][2]);

				adjList[edges[i][0]].push_back(p);
			}

			stack<int> topo;
			vector<bool> visited(N, false);

			for(int i = 0; i < N; i++)
			{
				if(!visited[i])
				{
					topoSort(i, visited, topo, adjList);
				}

			}


			vector<int> dist(N, INT_MAX);

			dist[0] = 0;


			while(!topo.empty())
			{
				int top = topo.top();
				topo.pop();

				if((dist[top] != INT_MAX))
				{
					for(auto i : adjList[top])
					{
						if(dist[top] + i.second < dist[i.first])
						{
							dist[i.first] = dist[top] + i.second;
						}
					}
				}

			}

			for(int i = 0; i < N; i++)
			{
				if(dist[i] == INT_MAX)
					dist[i] = -1;
			}

			return dist;

		}
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<vector<int>> edges;
		for(int i=0; i<m; ++i)
		{
			vector<int> temp;
			for(int j=0; j<3; ++j)
			{
				int x;
				cin>>x;
				temp.push_back(x);
			}
			edges.push_back(temp);
		}
		Solution obj;
		vector<int> res = obj.shortestPath(n, m, edges);
		for (auto x : res)
		{
			cout << x << " ";
		}
		cout << "\n";
	}
}

// } Driver Code Ends
