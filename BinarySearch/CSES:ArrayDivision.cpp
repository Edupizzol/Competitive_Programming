#include <bits/stdc++.h>
using namespace std;

bool check(const vector<long long> &v, int x, int k){
    long long num=0,max=0;
    for(int i=0;i<v.size();i++){
        if(num+v[i]>=x){
            if(num>max) max=num;
            num=0;
            k--;
        }

        num+=v[i];
    }

    return max==x && k==0;
}

int main(){

    int n,k;
    cin>>n>>k;

    vector<long long> v(n);
    for(long long &x:v){
        cin>>x;
    }

    long long low=0, high=1e15;

    long long ans;
    while(low<=high){
        long long middle = low + (high-low)/2;

        if(check(v,middle,k)){
            ans = middle;
            high = middle-1;
        }
        else low = middle+1;

    }

    cout<<ans<<endl;

}