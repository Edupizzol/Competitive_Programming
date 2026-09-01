#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> topologicalOrdering(int n){
    vector<int> degreeIn(n,0);
    vector<int> ans;
    for(int node=0; node<n; node++){
        for(int neighbour:adj[node]) degreeIn[neighbour]++;
    }

    queue<int> q;
    for(int i=0;i<degreeIn.size();i++) if(degreeIn[i]==0)q.push(i);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(int neighbour:adj[node]){
            degreeIn[neighbour]--;
            if(degreeIn[neighbour]==0) q.push(neighbour);
        }
    }

    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;

    adj.assign(n, {});

    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v; 
        adj[u].push_back(v);
    }

    vector<int> ans = topologicalOrdering(n);

    if((int)ans.size() != n){
        cout << "Nao existe ordenacao topologica (grafo tem ciclo)\n";
    } else {
        cout << "Ordenacao topologica: ";
        for(int v : ans) cout << v << " ";
        cout << "\n";
    }

    return 0;
}