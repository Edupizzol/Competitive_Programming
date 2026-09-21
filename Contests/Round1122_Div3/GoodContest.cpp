#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int> v(3);
        for(int &x:v) cin>>x;

        sort(v.begin(),v.end());
        cout<<n-v[0]<<endl;
    }   

}