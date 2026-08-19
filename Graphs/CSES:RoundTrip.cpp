#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> path;
bool isPossible=false;
int endingNode;
int startNode;

void dfs(int node, int pai){
    visited[node]=true;
    for(int neighbour: adj[node]){
        if(neighbour == pai) continue;
        if(visited[neighbour]){
            isPossible=true;
            endingNode=neighbour;
            startNode=node;
            return;
        }
        path[neighbour]=node;
        dfs(neighbour, node);
        if(isPossible) return;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    adj.assign(n+1,{});
    visited.assign(n+1,false);
    path.assign(n+1,-1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b); adj[b].push_back(a);
    }

    dfs(1,0);
    vector<int> ans;
    if(!isPossible) cout<<"IMPOSSIBLE"<<endl;
    else{
        int position=startNode;
        ans.push_back(endingNode);
        while(position!=endingNode){
            ans.push_back(position);
            position=path[position];
        }
        cout<<(int)ans.size()+1<<endl;
        for(int x:ans) cout<<x<<" ";
        cout<<endingNode<<endl;
    }

    return 0;
}