#include <bits/stdc++.h>
using namespace std;

long long resolve(const vector<long long> &v, int step, long long group1, long long group2, int n){

    if(step>=n) return abs(group1-group2);

    long long choose1=resolve(v,step+1,group1+v[step],group2,n);
    long long choose2=resolve(v,step+1,group1,group2+v[step],n);
    return min(choose1,choose2);

}

int main(){

    int n,step=0;
    long long group1=0,group2=0;
    cin>>n;
    vector<long long> v(n);
    for(long long &x:v) cin>>x;
    cout<<resolve(v,step,group1,group2,n)<<endl;

    return 0;

}