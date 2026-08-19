#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int node){

    visited[node]=true;
    for(int neighbour:adj[node]) if(!visited[neighbour]) dfs(neighbour);
    
}

int main(){
    int n,m;
    cin>>n>>m;
    adj.assign(n+1, {});
    visited.assign(n+1, false);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    dfs(1);
    return 0;
}