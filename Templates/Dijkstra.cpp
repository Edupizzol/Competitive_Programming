#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj;
const long long INF=1e18;

vector<long long> dijkstra(int n, int origin){

    vector<long long> distances(n,INF);
    distances[origin]=0;

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> minHeap;
    minHeap.push({0,origin});
    
    while(!minHeap.empty()){
        auto[d, v] = minHeap.top();
        minHeap.pop();

        if(d>distances[v]) continue;

        for(auto[w,weight]:adj[v]){
            long long newDistance = distances[v]+weight;
            if(newDistance<distances[w]){
                distances[w]=newDistance;
                minHeap.push({newDistance,w});
            }
        }
    }

    return distances;
}

int main(){
    int n, m, origem;
    cin >> n >> m >> origem;

    adj.assign(n, {});
    for(int i=0;i<m;i++){
        int u, v, peso;
        cin >> u >> v >> peso;
        adj[u].push_back({v, peso});
        // se o grafo for NAO-direcionado, descomenta:
        // adj[v].push_back({u, peso});
    }

    vector<long long> dist = dijkstra(n, origem);

    for(int i=0;i<n;i++){
        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}   