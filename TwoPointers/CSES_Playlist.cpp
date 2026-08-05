#include <bits/stdc++.h>
using namespace std;

long long sliding_window(const vector<long long> &v){

    unordered_set<long long> s;
    int left=0;
    long long ans=0;

    for(int right=0;right<v.size();right++){
        
        while(s.count(v[right])){
            s.erase(v[left]);
            left++;
        }
        s.insert(v[right]);

        ans = max(ans, (long long)(right-left+1));
    }

    return ans;

}

int main(){

    int n;
    cin>>n;
    vector<long long> v(n);
    for(long long &x:v) cin>>x;

    cout<<sliding_window(v)<<endl;

}