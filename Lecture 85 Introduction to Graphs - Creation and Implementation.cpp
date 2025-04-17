#include<iostream>
#include<unordered_map>
#include<map>
#include<list>
using namespace std;

template <typename T>
class graph{
	private:
		unordered_map<T, list<T> > adj;
//		map<T, list<T> > adj;
	public:
		void addEdge(T u, T v, bool direction){
			adj[u].push_back(v);
			
			if(direction == 0){
				adj[v].push_back(u);
			}
		}
		
		void printAdjList(){
			for(auto i : adj){
				cout<<i.first<<" -> ";
				
				for(auto j : i.second){
					cout<<j<<", ";
				}cout<<endl;
			}
		}
};

int main(){
	graph<int> g1;
	
	int n, e;
	cout<<"Enter no of nodes ";
	cin>>n;
	cout<<"Enter no of edges ";
	cin>>e;
	
	
	
	for(int i = 0; i < e; i++){
		int u, v;
		cout<<"Enter two nodes' values with spaces ";
		cin>>u>>v;
		
		g1.addEdge(u, v, 0);
	}
	
	g1.printAdjList();
	
	return 0;
}
