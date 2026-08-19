#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void bfs(int origem){
    queue<int> q;
    q.push(origem);
    visited[origem]=true;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int neighbour:adj[node]){
            if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]=true;
            }
        }

    }

    return;
}

int main(){

    int n,m;
    cin>>n>>m;

    adj.assign(n+1,{});
    visited.assign(n+1,false);
    vector<int> compounds;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b); adj[b].push_back(a);
    }   

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            bfs(i);
            compounds.push_back(i);
        }
    }

    cout<<compounds.size()-1<<endl;
    for(int i=1;i<compounds.size();i++){
        cout<<compounds[i-1]<<" "<<compounds[i]<<endl;
    }

    return 0;

}