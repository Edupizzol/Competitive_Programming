urn;
        }
    }
    if(step==49) return;

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
