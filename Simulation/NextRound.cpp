#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,m,num,count=0;

    cin>>n>>m;
    vector<int> v(n);
    for(int &x:v) cin>>x;
    num=v[m-1];
    for(int i=0;i<n;i++) if(v[i]>=num && v[i]!=0) count++;
    cout<<count<<endl;

}