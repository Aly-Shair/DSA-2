//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution // https://www.geeksforgeeks.org/problems/topological-sort/1
{  
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
    
        vector<int> indegree(V,0);
        
        /*The error you are encountering is due to the use of the range-based for loop on a pointer to an array of vectors. The adj variable is declared as vector<int> adj[], which is an array of vectors, not a single vector. The range-based for loop does not directly support iterating over arrays of containers like this.*/
        
        for(int i = 0; i < V; i++){
            for(auto j : adj[i]){
                indegree[j]++;
            }
        }
        
        queue<int> Q;
        
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                Q.push(i);
            }
        }
        vector<int> ans;
        
        while(!Q.empty()){
            int front = Q.front();
            Q.pop();
            ans.push_back(front);
            for(auto neighbour : adj[front]){
                indegree[neighbour]--;
                
                if(indegree[neighbour] == 0){
                    Q.push(neighbour);
                }
            }
        }
        
        return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
