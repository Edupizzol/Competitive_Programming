#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<long long> &v){

    long long books=0;
    for(int i=0;i<v.size();i++){

        if(v[i]>i+1) books+=v[i]-(i+1);
        else if(v[i]<i+1){
            long long need = i+1-v[i];
            if(books>=need) books-=need;
            else return false;
        }
    }   
    return true;

}

int main(){

    int t;
    cin>>t;

    for(int i=0;i<t;i++){

        int n;
        cin>>n;

        vector<long long> v(n);
        for(long long &x:v) cin>>x;
        if(isPossible(v)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }

    return 0;

}