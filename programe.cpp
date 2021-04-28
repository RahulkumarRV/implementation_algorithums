#include<bits/stdc++.h>
using namespace std;

bool iscycleutil(vector<int> adj[], vector<int> visited, int current){
	if(visited[current] == 2){
		return true;
	}
	visited[current] = 1;
	for(int i=0; i<adj[i].size(); i++){
		if(visited[current] ==1 ){
			visited[current] = 2;
		}else {
		if(iscycleutil(adj, visited, adj[current][i])){
			return true;
		}
		}
	}
	return false;
}


bool iscyle(int v, vector<int> adj[]){
	vector<int> visited(v, 0);
	for(int i=0; i<v; i++){
		visited[i] = 1;
		for(int j=0; j<adj[i].size(); j++){
			if(iscycleutil(adj, visited, adj[i][j])){
				return true;
			}
		}
		visited[i] = 0;
	}
	return false;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int v, e;
		
		cin>>v>>e;
		vector<int> adj[v];
		while(e--){
			int u, v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		cout<<iscyle(v, adj)<<endl;
	}
	return 0;
}