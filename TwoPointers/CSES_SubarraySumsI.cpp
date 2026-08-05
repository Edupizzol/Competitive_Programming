#include <bits/stdc++.h>
using namespace std;

int sliding_window(const vector<long long> &v, long long x){

    int left=0;
    long long sum=0,count=0;

    for(int right=0;right<v.size();right++){
        sum+=v[right];

        while(sum>x){
            sum-=v[left];
            left++;
        }   
        if(sum==x) count++;
    }

    return count;

}

int main(){

    long long n,x;
    cin>>n>>x;
    vector<long long> v(n);
    for(long long &x:v) cin>>x;

    cout<<sliding_window(v,x)<<endl;

    return 0;

}