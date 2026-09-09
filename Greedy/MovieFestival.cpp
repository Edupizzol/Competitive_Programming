#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<pair<long,long>> v(n);
    for(auto&[x,y]:v) cin>>x>>y;
    sort(v.begin(), v.end(), [](const pair<long, long> &a, const pair<long, long> &b){return a.second < b.second;});

    int event1, event2;
    long long count=1;
    event1=v[0].second;
    for(int i=1;i<v.size();i++){
        event2=v[i].first;
        if(event2>=event1){
            count++;
            event1=v[i].second;
        }
    }   

    cout<<count<<endl;
    return 0;
}