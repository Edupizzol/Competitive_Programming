#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> v(n);
    for(long long &x:v) cin>>x;

    long long count=0;
    for(int i=1;i<v.size();i++){
        if(v[i-1]>v[i]){count+=(v[i-1]-v[i]); v[i]+=(v[i-1]-v[i]);}
    }

    cout<<count<<endl;
    return 0;
}