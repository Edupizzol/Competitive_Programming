#include <bits/stdc++.h>
using namespace std;

vector<int> memo;
long long memoization(int n){

    if(n==0) return 0;
    if(memo[n]!=-1) return memo[n];

    int temp=n;
    long long total=1e9+10;
    while(temp>=1){
        int digit=temp%10;
        temp/=10;
        if(digit>0) total = min(total,memoization(n-digit)+1);
    }

    return memo[n]=total;
}

int main(){
    int n;
    cin>>n;
    memo.assign(n+1,-1);
    cout<<memoization(n)<<endl;
    return 0;
}