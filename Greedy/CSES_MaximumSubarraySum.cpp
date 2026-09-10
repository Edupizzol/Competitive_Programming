#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<long long> v(n);
    for(long long &x:v) cin>>x;

    long long res=v[0], maxEnding=v[0];
    for(int i=1;i<n;i++){
        maxEnding=max(v[i],maxEnding+v[i]);
        res=max(res,maxEnding);
    }
    
    cout<<res<<endl;
    return 0;

}