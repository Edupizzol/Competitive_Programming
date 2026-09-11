#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;
    long long sum_boys=0;
    vector<int> boys(n), girls(m);
    for(int &x:boys) cin>>x;
    for(int &x:girls) cin>>x;

    sort(boys.begin(),boys.end());
    sort(girls.begin(),girls.end());
    if(girls[0]<boys[n-1]){cout<<-1<<endl; return 0;}

    for(int &x:boys) sum_boys+=x;
    long long total = sum_boys * m;

    for(int i = 0; i < m; i++){
        total += (girls[i] - boys[n-1]);
    }

    if(girls[0] > boys[n-1]){
        total += (boys[n-1] - boys[n-2]);
    }

    cout << total << "\n";
    return 0;
}