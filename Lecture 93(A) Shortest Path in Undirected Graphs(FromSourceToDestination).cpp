class Solution
{
	public:
		vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src, int dest)
		{

			map<int, list<int> > adjList;

			for(int i = 0; i < M; i++)
			{
				int u = edges[i][0];
				int v = edges[i][1];

				adjList[u].push_back(v);
				adjList[v].push_back(u);
			}

			unordered_map<int, bool> visited;
			unordered_map<int, int> parent;
			queue<int> Q;

			Q.push(src);
			visited[src] = true;
			parent[src] = -1;

			while(!Q.empty())
			{
				int front = Q.front();
				Q.pop();

				for(auto neighbour : adjList[src])
				{
					if(!visited[neighbour])
					{
						Q.push(neighbour);
						visited[neighbour] = true;
						parent[neighbour] = front;
					}
				}
			}

			if(!visited[dest])
			{
				// If destination is not reachable, return an empty vector
				return ans;
			}


			vector<int> ans;
			int currNode = dest;
			ans.push_back(currNode);

			while(currNode != src)
			{
				currNode = parent[currNode];
				ans.push_back(currNode);
			}

			reverse(ans.begin(), ans.end());

			return ans;

		}
};
