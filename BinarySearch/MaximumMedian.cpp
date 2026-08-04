#include <bits/stdc++.h>
using namespace std;

bool check(const vector<int> &v, long long k, long long x){

    int n = v.size();
    for(int i=n/2;i<n;i++){
        if(v[i]<x) k-=(x-v[i]);
    }

    return k>=0;

}

int main(){

    int n,k;
    cin>>n>>k;

    vector<int> v(n);
    for(int &x:v) cin>>x;
    sort(v.begin(),v.end());

    long long lo = v[n/2], hi = 2e9;
    long long resposta = lo;

    while(lo<=hi){
        long long mid = lo + (hi-lo)/2;  
        if(check(v,k,mid)){         
            resposta = mid;        
            lo = mid + 1;
        }
        else hi = mid - 1;          
    }

    cout<<resposta<<endl;

}