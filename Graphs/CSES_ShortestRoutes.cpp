#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj;
const long long INF = 1e18;

vector<long long> dijkstra(auto n, int origin){
    vector<long long> distances(n,INF);
    distances[origin]=0;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> minHeap;
    minHeap.push({0,origin});

    while(!minHeap.empty()){
        auto[d,v] = minHeap.top();
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    adj.assign(n, {});

    for(int i=0;i<m;i++){
        long long u, v, peso;
        cin >> u >> v >> peso;
        u--;v--;
        adj[u].push_back({v, peso});
    }

    for(long long x:(dijkstra(n,0))){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}