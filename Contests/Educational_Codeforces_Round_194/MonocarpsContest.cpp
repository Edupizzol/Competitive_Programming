#include <bits/stdc++.h>
using namespace std;

int main(){

    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int n;
        cin>>n;
        vector<int> v(n);
        int count=0;
        for(int &x:v){
            cin>>x;
            if(x==0)count++;
        }

        if(count<2) cout<<-1<<endl;
        else if(v[0]==0 && v[n-1]==0) cout<<0<<endl;
        else if(v[0]==1 && v[n-1]==1) cout<<2<<endl;
        else cout<<1<<endl;
    
    }

    return 0;
}