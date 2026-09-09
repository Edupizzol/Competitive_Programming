#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<long long> v(n);
    for(long long &x:v) cin>>x;
    sort(v.begin(),v.end());
    long long median=v[n/2];
    
    long long count=0;
    for(int i=0;i<v.size();i++){
        count+=abs(median-v[i]);
    }

    cout<<count<<endl;
    return 0;
}