#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<long long> &v){

    long long books=0;

    for(int i=0;i<v.size();i++){

        if(v[i]>i+1){
            books+=v[i]-i+1;
            v[i]-=books;
        }
        else if(v[i]<i+1){
            int need = i+1-v[i];
            if(books>=need){
                books-=need; v[i]+=need;
            }
            else return false;
        }

        for(int j=0;j<v.size();j++) cout<<v[i] <<endl;

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

}