-//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution { // https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        unordered_map<int, bool> visited;
        queue<int> q;
        vector<int> ans;
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            ans.push_back(front);
            
            for(auto i : adj[front]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/*
#include<iostream>
#include<unordered_map>
#include<queue>
#include<set>
using namespace std;

class Solution {
	private:
		void createAdjList(vector<pair<int, int> > edges, unordered_map<int, set<int> > &adjList) {
			for(int i = 0; i < edges.size(); i++) {
				int u = edges[i].first;
				int v = edges[i].second;

				adjList[u].insert(v);
				adjList[v].insert(u);
			}
		}

		void BFS(unordered_map<int, set<int> > &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node) {
			queue<int> q;

			q.push(node);
			visited[node] = true;

			while(!q.empty()) {
				int front = q.front();
				q.pop();

				ans.push_back(front);

				for(auto i : adjList.at(front)) {
					if(!visited[i]) {
						q.push(i);
						visited[i] = true;
					}
				}
			}


		}

	public:
		vector<int> bfsOfGraph(int vertex, vector<pair<int, int> > edges) {
			unordered_map<int, set<int> > adjList;
			vector<int> ans;
			unordered_map<int, bool> visited;
			creatAdjList(edges, adjList);

			for(int i = 0; i < vertex; i++) { // loop for disconnected graph or i ki jagah 0 pass kar detay funciton ma
				if(!visited[i]) {
					BFS(adjList, visited, ans, i);
				}
			}
			
			return ans;
		}
};

int main() {

	return 0;
}
*/
