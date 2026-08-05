#include <bits/stdc++.h>
using namespace std;

bool isSimilar(vector<int> &v){

    int count = v.size()/2;
    sort(v.begin(),v.end());
    for(int i=1;i<v.size();i++){

        if(abs(v[i]-v[i-1])==1){
            count--;
            v[i]=0; v[i-1]=0;
            i++;
        }

    }

    for(int i=0; i<(int)v.size(); ){
        if(v[i]==0) v.erase(v.begin()+i);  
        else i++;                            
    }

    sort(v.begin(),v.end());
    for(int i=1;i<v.size();i+=2){
        if((v[i] & 1) && (v[i-1] & 1)) count--;
        else if (!(v[i] & 1) && !(v[i-1] & 1)) count--;
    }

    return count==0;

}


int main(){

    int n;
    cin>>n;
    for(int i=0;i<n;i++){

        int m;
        cin>>m;
        vector<int> v(m);
        for(int &x:v) cin>>x;

        if(isSimilar(v)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;

}