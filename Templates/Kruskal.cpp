#include <bits/stdc++.h>
using namespace std;

vector<int> parent, sizes;

int find(int x){
    while(parent[x]!=x) x=parent[x];
    return x;
}

bool unite(int x, int y){
    int rootX=find(x);
    int rootY=find(y);
    if(rootX==rootY) return false;

    if(sizes[rootY]>sizes[rootX]) swap(rootX,rootY);
    parent[rootY]=rootX;
    sizes[rootX]+=sizes[rootY];
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;

    // cada aresta: {peso, u, v}
    vector<array<int,3>> arestas(m);
    for(auto &e : arestas){
        int u, v, peso;
        cin >> u >> v >> peso;
        e = {peso, u, v};
    }

    sort(arestas.begin(), arestas.end());

    // passo 2: inicializa o Union-Find (cada no eh pai de si mesmo)
    parent.resize(n);
    sizes.assign(n, 1);
    for(int i=0;i<n;i++) parent[i] = i;

    long long totalCost=0, edgesUsed=0;
    for(auto &[peso,u,v]:arestas){
        if(unite(u,v)){
            totalCost+=peso;
            edgesUsed++;
        }
    }

    cout << "Custo total da MST: " << totalCost << "\n";
    cout << "Arestas usadas: " << edgesUsed << " (esperado: " << n-1 << ")\n";

    return 0;
}