#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> path;
int n,m;

void bfs(int origin){
    queue<int> q;
    q.push(origin);
    visited[origin]=true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int neighbour:adj[node]){
            if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]=true;
                path[neighbour]=node;
            }
        }
    }

    return;
}

int main(){
    cin>>n>>m;
    adj.assign(n+1,{});
    visited.assign(n+1,false);
    path.assign(n+1,-1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b); adj[b].push_back(a);
    }

    bfs(1);

    if(visited[n]){
        int cont=0,position=n;
        vector<int> ans;
        do{
            ans.push_back(position);
            position=path[position];
            cont++;
        }while(position>=1);
        cout<<cont<<endl;
        reverse(ans.begin(),ans.end());
        for(int x:ans) cout<<x<<" ";
        cout<<endl;
    }
    else cout<<"IMPOSSIBLE"<<endl;

}