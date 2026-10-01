#include  <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(auto&[x,y]:v) cin>>x>>y;

    sort(v.begin(),v.end(), [](const pair<int, int> &a, const pair<int,int> &b){return a.second<b.second;});
    long long time=0;
    long long lateness=0;
    for(int i=0;i<v.size();i++){
        time+=v[i].first;
        if(time>v[i].second) lateness=max(lateness,time-v[i].second);
    }

    (lateness>0) ? cout<<lateness<<endl : cout<<"PERFECT"<<endl;
    return 0;
}