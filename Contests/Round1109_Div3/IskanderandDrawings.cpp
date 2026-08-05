#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        
        int m;
        cin>>m;
        string s;
        cin>>s;
        int cont=0;
        int max=0;
        for(int j=0;j<m;j++){
            if(s[j]=='*') cont=0;
            else if(s[j]=='#') cont++;
            if(cont>max) max=cont;
        }

        if(max & 1) max++;
        cout<<max/2<<endl;

    }

    return 0;

}