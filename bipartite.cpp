#include<bits/stdc++.h>

using namespace std;

bool isBipartite(int V, vector<int> adj[]){
	vector<int> color(V, -1);
	queue<pair<int,int>> q;
	
	for(int i=0; i<V; i++){
		if(color[i] == -1){
			q.push({i, 0});
			while(!q.empty()){
				pair<int, int> node = q.front();
				q.pop();
				int v = node.first;
				int c = node.second;
				for(int j : adj[v]){
					if(color[j] == c){
						return false;
					}
					if(color[j] == -1){
						color[j] = (c) ? 0 : 1;
						q.push({j, color[j]});
					}
				}
			}
		}
	}
	return true;
}

int main(){
	int V, E;
    V = 4 , E = 6;
      //adjacency list for storing graph
    vector<int> adj[V];
      adj[0] = {0,1};
      adj[1] = {0,2};
      adj[2] = {1,2};
      //adj[3] = {0,2};
     
   
    bool ans = isBipartite(V, adj);
    //returns 1 if bipatite graph is possible
      if (ans)
        cout << "Yes\n";
    //returns 0 if bipartite graph is not possible
      else
        cout << "No\n";
	return 0;
}