#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, value;
    cin>>n>>value;
    vector<int> v(n);
    for(int &x:v) cin>>x;
    sort(v.begin(),v.end());
    int ans=0;
    
    for(int i=v.size()-1;i>=0;i--){
        ans+=value/v[i];
        value=value%v[i];
    }

    cout<<ans<<endl;
    return 0;
}