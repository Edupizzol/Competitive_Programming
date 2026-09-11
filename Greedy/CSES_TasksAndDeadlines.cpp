#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(auto &[x,y]:v) cin>>x>>y;
    sort(v.begin(),v.end());

    long long answer=0, time=0;
    for(int i=0;i<v.size();i++){
        time+=v[i].first;
        answer+=(v[i].second-time);
    }

    cout<<answer<<endl;
    return 0;
}