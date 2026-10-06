#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9+7;
vector<long long> memo;

long long dp(int n){
    if(n==0) return 1;
    if(memo[n]!=-1) return memo[n];
    int max=6;
    if(n<6) max=n;
    long long total=0;
    for(int i=1;i<=max;i++){
        total=(total+dp(n-i))%mod;
    }
    return memo[n]=total;
}

int main(){
    int n;
    cin>>n;
    memo.assign(n+1,-1);
    cout<<dp(n)<<endl;
    return 0;
}