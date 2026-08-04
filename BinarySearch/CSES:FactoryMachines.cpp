#include <bits/stdc++.h>
using namespace std;

bool check(const vector<long long> &v, long long x, long long t){
    long long total=0;
    for(int i=0;i<v.size();i++){
        total+=x/v[i];
        if(total>=t) return true;
    }

    return total>=t;
}

int main(){

    int n,t;
    cin>>n>>t;
    
    vector<long long> v(n);
    for(long long &x:v){
        cin>>x;
    }

    long long low = 0;
    long long high = t * (*max_element(v.begin(),v.end()));

    long long ans=0;
    while(low<=high){

        long long mid = low + (high-low)/2;
        if(check(v,mid,t)){
            ans = mid;
            high=mid-1;
        }
        else low=mid+1;

    }

    cout<<ans<<endl;

}