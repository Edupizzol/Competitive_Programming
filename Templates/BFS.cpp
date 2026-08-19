#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> distances;

void bfs(int origem){
    queue<int> q;
    q.push(origem);
    visited[origem]=true;
    distances[origem]=0;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        
        for(int neighbour:adj[node]){
            if(!visited[neighbour]){
                visited[neighbour]=true;
                distances[neighbour]=distances[node]+1;
                q.push(neighbour);
            }
        }
    }

    return;
}

int main(){
    int n,m;
    cin>>n>>m;

    adj.assign(n+1, {});
    visited.assign(n+1, false);
    distances.assign(n+1, -1);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); //se o grafo for direcionado obviamente apaga isso
    }

    bfs(1);
    return 0;
}