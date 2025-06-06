//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution // https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
{
	public:
		//Function to find the shortest distance of all the vertices
		//from the source vertex S.
		vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
		{
			set<pair<int, int> > st;

			vector<int> dist(V, INT_MAX);

			dist[S] = 0;

			st.insert(make_pair(0, S));

			while(!st.empty())
			{
				set<pair<int, int> >  :: iterator itr = st.begin();
				pair<int, int> top = *itr;

				int topDistance = top.first;
				int topNode = top.second;

				st.erase(itr);

				for(auto neighbour : adj[topNode])
				{
					if(topDistance + neighbour[1] < dist[neighbour[0]])
					{
						auto record = st.find(make_pair(dist[neighbour[0]], neighbour[0]));

						if(record != st.end())
						{
							st.erase(record);
						}

						dist[neighbour[0]] = topDistance + neighbour[1];

						st.insert(make_pair(dist[neighbour[0]], neighbour[0]));

					}
				}
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
		int S;
		cin>>S;

		Solution obj;
		vector<int> res = obj.dijkstra(V, adj, S);

		for(int i=0; i<V; i++)
			cout<<res[i]<<" ";
		cout<<endl;
	}

	return 0;
}


// } Driver Code Ends
