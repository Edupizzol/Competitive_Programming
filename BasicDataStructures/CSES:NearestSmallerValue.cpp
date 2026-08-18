#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<long long> v(n);
    for(long long &x:v) cin>>x;
    stack<long long> s;

    for(int i=0;i<v.size();i++){
        while(!s.empty() && v[s.top()]>=v[i]){s.pop();}
        if(s.empty()) cout<<0<<" ";
        else cout<<s.top()+1<<" ";
        s.push(i);
    }
    cout<<endl;

    return 0;
}