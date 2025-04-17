//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
	public:
		vector<int> shortestPath(int N,int M, vector<vector<int>>& edges)
		{

			unordered_map<int, list<pair<int, int> > >adjList;
			for(int i = 0; i < M; i++)
			{
				pair<int, int> p = make_pair(edges[i][1], edges[i][2]);

				adjList[edges[i][0]].push_back(p);
			}
			vector<int> dist(N, INT_MAX);

			queue<int> Q;
			Q.push(0);
			dist[0] = 0;

			while(!Q.empty())
			{
				int front = Q.front();
				Q.pop();

				for(auto neighbour : adjList[front])
				{
					if(dist[front] + neighbour.second < dist[neighbour.first])
					{
						Q.push(neighbour.first);
						dist[neighbour.first] = dist[front] + neighbour.second;
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
