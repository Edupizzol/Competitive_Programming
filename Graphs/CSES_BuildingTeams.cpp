#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> color;
bool isPossible=true;

void bfs_divide(int origem){
    queue<int> q;
    q.push(origem);
    color[origem]=1;

    while(!q.empty()){
        int node=q.front();
        q.pop();

        for(int neighbour:adj[node]){
            if(color[neighbour]==-1){
                q.push(neighbour);
                color[neighbour] = (color[node]==1) ? 2 :1;
            }
            else if(color[neighbour]==color[node]){
                cout<<"IMPOSSIBLE"<<endl;
                isPossible=false;
                return;
            }
        }

    }

    return;
}

int main(){
    int n,m;
    cin>>n>>m;
    adj.assign(n+1,{});
    color.assign(n+1,-1);

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(color[i]==-1) bfs_divide(i);
    }

    if(isPossible){
        for(int i=1;i<=n;i++) cout<<color[i]<<" ";
    }
    cout<<endl;

    return 0;
}