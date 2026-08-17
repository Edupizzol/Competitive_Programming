#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int n,m;
        cin>>n>>m;

        vector<long long> bea(n), ver(m);
        for(long long &x:bea) cin>>x;
        for(long long &x:ver) cin>>x;

        long long beaCount=0, verCount=0;
        for(int j=1;j<bea.size();j++){
            beaCount+=(abs(bea[j]-bea[j-1]))+1;
        }
        for(int j=1;j<ver.size();j++){
            verCount+=(abs(ver[j]-ver[j-1]))+1;
        }

        if(bea[n-1]+beaCount>=ver[m-1]+verCount) cout<<1<<endl;
        else cout<<2<<endl;
    }

    return 0;
}