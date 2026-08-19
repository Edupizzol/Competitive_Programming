#include <bits/stdc++.h>
using namespace std;

vector<string> grid;
vector<vector<bool>> visited;
int n,m;

void dfs(int line, int column){

    if(line<0 || column<0 || line>=n || column>=m) return;
    if(visited[line][column]) return;
    if(grid[line][column]=='#') return;
    visited[line][column]=true;

    dfs(line+1,column);
    dfs(line-1,column);
    dfs(line,column+1);
    dfs(line,column-1);

}

int main(){
    
    int cont=0;
    cin>>n>>m;
    grid.resize(n);

    for(int i=0;i<n;i++) cin>>grid[i];
    visited.assign(n,vector<bool>(m,false));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(grid[i][j]=='.' && !visited[i][j]){
                dfs(i,j);
                cont++;
            }
            
        }
    }

    cout<<cont<<endl;

}