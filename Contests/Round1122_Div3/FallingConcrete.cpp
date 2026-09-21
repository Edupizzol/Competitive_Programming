#include <bits/stdc++.h>
using namespace std;

void moveRoad(vector<long long> &v, int i, int j){
    int temp=j-1;
    while(temp>=i){
        v[temp]++;
        v[j]--;
        temp--;
    }
    swap(v[j],v[i]);
}

int main(){

    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        vector<long long> v(n);
        for(long long &x:v) cin>>x;

        int max=1;
        int left=0,right=0;

        for(int i=1;i<v.size();i++){
            if(v[i]==v[i-1]){max++; right=i; continue;}
            
            

        }

    }

}