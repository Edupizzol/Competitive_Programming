#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; vector<vector<int>> adjT;
vector<bool> visited={};
vector<int> pre; vector<int> post;
long long Time=0;

void dfs(int node){

    Time++;
    visited[node]=true;
    pre[node]=Time;
    for(int neighbour:adj[node]) if(!visited[neighbour]) dfs(neighbour);
    Time++; post[node]=Time;

}

void transpor(int node, int n){

    adjT.assign(n,{});
    for(int u=0;u<n;u++){
        for(int v:adj[u]) adjT[v].push_back(u);
    }

}

void dfs2(int node, vector<int> &componente){
    visited[node] = true;              // marca esse nó como visitado
    componente.push_back(node);        // adiciona ele no vetor do SCC atual
    for(int neighbour : adjT[node])    // olha os vizinhos NO GRAFO TRANSPOSTO
        if(!visited[neighbour])        // só desce se ainda não foi visitado
            dfs2(neighbour, componente); // chama recursivamente, passando o MESMO vetor
}

int main(){



}