#include <bits/stdc++.h>
using namespace std;

vector<char> answer;
vector<string> grid;
vector<vector<bool>> visited;
vector<vector<char>> path;
int n,m;

bool limits(int i, int j){if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='#') return false; return true;}
void bfs(int Sline, int Scolumn){
    queue<pair<int,int>> q;
    q.push({Sline,Scolumn});
    visited[Sline][Scolumn]=true;

    while(!q.empty()){
        auto[line,column]=q.front();
        q.pop();

        int newLine, newColumn; 
        newLine=line+1;newColumn=column;
        if(limits(newLine,newColumn) && !visited[newLine][newColumn]){
            q.push({newLine,newColumn});
            visited[newLine][newColumn]=true;
            path[newLine][newColumn]='D';
        }
        newLine=line-1;newColumn=column;
        if(limits(newLine,newColumn) && !visited[newLine][newColumn]){
            q.push({newLine,newColumn});
            visited[newLine][newColumn]=true;
            path[newLine][newColumn]='U';
        }
        newLine=line;newColumn=column+1;
        if(limits(newLine,newColumn) && !visited[newLine][newColumn]){
            q.push({newLine,newColumn});
            visited[newLine][newColumn]=true;
            path[newLine][newColumn]='R';
        }
        newLine=line;newColumn=column-1;
        if(limits(newLine,newColumn) && !visited[newLine][newColumn]){
            q.push({newLine,newColumn});
            visited[newLine][newColumn]=true;
            path[newLine][newColumn]='L';
        }
        
    }


}

int main(){
    cin>>n>>m;
    grid.resize(n);
    for(int i=0;i<n;i++) cin>>grid[i];
    visited.assign(n,vector<bool>(m,false));
    path.assign(n,vector<char>(m,' '));

    int bLine, bColumn;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A') bfs(i,j);
            if(grid[i][j]=='B'){
                bLine=i;bColumn=j;
            }
        }
    }

    vector<char> ans;
    if(visited[bLine][bColumn]){
        cout<<"YES"<<endl;
        int cont=0;
        int i=bLine,j=bColumn;
        do{
            ans.push_back(path[i][j]);
            cont++;
            if(path[i][j]=='U') i+=1;    
            else if(path[i][j]=='D') i-=1;  
            else if(path[i][j]=='L') j+=1;   
            else if(path[i][j]=='R') j-=1;
        }while(grid[i][j]!='A');
        reverse(ans.begin(), ans.end());
        cout<<cont<<endl;
        for(char c:ans) cout<<c;
        cout<<endl;
    }
    else cout<<"NO"<<endl;

    return 0;
}