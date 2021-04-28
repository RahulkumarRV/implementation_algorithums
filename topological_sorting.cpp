#include<bits/stdc++.h>

using namespace std;

class Graph{
	int V;
	vector<int> *adj;
	public :
	    Graph(int V){
			this->V = V;
			adj = new vector<int>[V];
		}
		void topological_sorting_ref(int src, vector<bool> &visited, stack<int>& Stack);
		void topological_sorting();
		void addEdge(int u, int v);
};
void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
}
void Graph::topological_sorting_ref(int src, vector<bool> &visited, stack<int> &Stack){
	visited[src] = true;
	
	for(auto it = adj[src].begin(); it != adj[src].end(); it++){
		if(visited[*it] == false){
			topological_sorting_ref(*it, visited, Stack);
		}
	}
	Stack.push(src);
}
void Graph::topological_sorting(){
	vector<bool> visited(V, false);
	stack<int> Stack;
	
	for(int i=0; i<V; i++){
		if(visited[i] == false){
			topological_sorting_ref(i, visited, Stack);
		}
	}
	while(!Stack.empty()){
		cout<<Stack.top()<< " ";
		Stack.pop();
	}
}


int main(){
	
	int t;
	cin>>t;
	while(t--){
		int v, e;
		cin>>v>>e;
		Graph graph(v);
		for(int i = 0; i<e; i++){
			int u, v;
			cin>>u>>v;
			graph.addEdge(u, v);
		}
		graph.topological_sorting();
	}
	
	return 0;
}