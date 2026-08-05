#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        vector<int> v(m);
        for(int &x:v) cin>>x;
        sort(v.begin(),v.end());

        int interval=v[1]-v[0];
        for(int i=1;i<m;i++){
            if(v[i]-v[i-1]<interval) interval=v[i]-v[i-1];
        }
        
        cout<<interval<<endl;

    }

}