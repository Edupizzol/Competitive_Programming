#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;
vector<vector<bool>> visited;
int n;
int ax,ay;
int bx,by;

bool isAttacked(int r, int c, int rq, int cq){
    return(r==rq || c==cq || (abs(r-rq)==abs(c-cq)));
}

void dfs(int i, int j){
    if(i>=n || j>=n || i<0 || j<0) return;
    if(visited[i][j]) return;
    if(isAttacked(i,j,ax,ay)) return;

    visited[i][j]=true;
    dfs(i+1,j);
    dfs(i,j+1);
    dfs(i+1,j+1);
    dfs(i+1,j-1);
    dfs(i-1,j);
    dfs(i,j-1);
    dfs(i-1,j-1);
    dfs(i-1,j+1);
}

int main(){

    cin>>n;
    grid.assign(n,vector<int>(n,0));
    visited.assign(n,vector<bool>(n,false));
    cin>>ax>>ay;
    cin>>bx>>by;
    int cx,cy;
    cin>>cx>>cy;

    dfs(bx,by);
    (visited[cx][cy]) ? cout<<"YES"<<endl : cout<<"NO"<<endl;    
    return 0;
}