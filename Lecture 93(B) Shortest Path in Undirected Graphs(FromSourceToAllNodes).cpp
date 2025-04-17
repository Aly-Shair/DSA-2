//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution   // https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
{
	public:
		vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src)
		{
			map<int, list<int> > adjList;

			for(int i = 0; i < M; i++)
			{
				int u = edges[i][0];
				int v = edges[i][1];

				adjList[u].push_back(v);
				adjList[v].push_back(u);
			}

			vector<bool> visited(N);
			vector<int> parent(N);
			queue<int> Q;

			Q.push(src);
			visited[src] = true;
			parent[src] = -1;

			while(!Q.empty())
			{
				int front = Q.front();
				Q.pop();

				for(auto neighbour : adjList[front])
				{
					if(!visited[neighbour])
					{
						Q.push(neighbour);
						visited[neighbour] = true;
						parent[neighbour] = front;
					}
				}
			}

			int count;
			vector<int> ans;
			int currNode;

			for(int i = 0; i < N; i++)
			{
				count = -1;
				currNode = i;


				if(visited[currNode])
				{
					while(currNode != -1)
					{
						currNode = parent[currNode];
						count++;
					}
				}

				ans.push_back(count);

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
		int n, m;
		cin >> n >> m;
		vector<vector<int>> edges;

		for (int i = 0; i < m; ++i)
		{
			vector<int> temp;
			for(int j=0; j<2; ++j)
			{
				int x;
				cin>>x;
				temp.push_back(x);
			}
			edges.push_back(temp);
		}

		int src;
		cin >> src;

		Solution obj;

		vector<int> res = obj.shortestPath(edges, n, m, src);

		for (auto x : res)
		{
			cout<<x<<" ";
		}
		cout << "\n";
	}
}

// } Driver Code Ends
