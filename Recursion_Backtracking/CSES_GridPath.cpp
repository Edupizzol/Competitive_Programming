#include <bits/stdc++.h>
using namespace std;

int cont=0;
bool visited[7][7]={};
string order;

void resolve(int line, int column, int step){

    if(line>=7 || column>=7 || line<0 || column<0) return;
    if(visited[line][column]) return;

    if(line==6 && column==0){
        if(step==48){
            cont++; 
            return;
        }
    }
    if(step==48) return;

    visited[line][column]=true;

    char movement = order[step];
    if(movement=='?' || movement=='D') resolve(line+1,column,step+1);
    if(movement=='?' || movement=='U') resolve(line-1,column,step+1);
    if(movement=='?' || movement=='L') resolve(line,column-1,step+1);
    if(movement=='?' || movement=='R') resolve(line,column+1,step+1);

    visited[line][column]=false;

}

int main(){

    cin>>order;
    int line=0,column=0,step=0;
    resolve(line,column,step);
    cout<<cont<<endl;

    return 0;

}