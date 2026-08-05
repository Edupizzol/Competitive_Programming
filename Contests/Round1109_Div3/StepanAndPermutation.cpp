#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<long long> &v, int x, int y){

    vector<long long> copy = v;

    for(int i=0;i<v.size();i++){
        
        int jumps = __gcd(x,y); 
        int position = i+1;
        if(position%jumps != v[i]%jumps) return false;
        
    }
    return true;

}

int main(){

    int n;
    cin>>n;

    for(int i=0;i<n;i++){

        int m,x,y;
        cin>>m>>x>>y;

        vector<long long> v(m);
        for(long long &d:v) cin>>d;

        if(isPossible(v,x,y)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }

    return 0;

}