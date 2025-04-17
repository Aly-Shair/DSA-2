#include<iostream>
#include<vector>
using namespace std;

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

int main()
{
	int n = 7;
	vector<int> rank (n,0);
	vector<int> parent(n);
	return 0;
}
