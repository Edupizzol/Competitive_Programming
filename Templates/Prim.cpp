#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
vector<vector<pair<int,int>>> adj;

long long prim(int n){
    vector<long long> minEdge(n, INF);
    vector<bool> inMST(n, false);
    minEdge[0]=0;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> minHeap;
    minHeap.push({0,0});
    long long totalcost=0;

    while(!minHeap.empty()){
        auto[v,d] = minHeap.top();
        minHeap.pop();
        if(inMST[v]) continue;

        totalcost+=d;
        inMST[v]=true;

        for(auto[w,weight] : adj[v]){
            if(!inMST[w] && weight<minEdge[w]){
                minEdge[w]=weight;
                minHeap.push({w,weight});
            }
        }
    }

    return totalcost;
}

int main(){
    int n, m;
    cin >> n >> m;

    adj.assign(n, {});
    for(int i=0;i<m;i++){
        int u, v, peso;
        cin >> u >> v >> peso;
        adj[u].push_back({v, peso});
        adj[v].push_back({u, peso}); 
    }

    cout << prim(n) << "\n";
}