#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long weight;
    cin>>n>>weight;
    vector<pair<int,int>> itens(n);
    vector<pair<double,int>> proportion(n);

    for(int i=0;i<n;i++){
        int w,v;
        cin>>w>>v;
        itens[i]={w,v};
        proportion[i]={(double)v/w,i};
    }
    sort(proportion.begin(), proportion.end(), greater<>());

    int i=0;
    double value=0;
    while(weight>0 && i<n){
        int index = proportion[i].second;
        if(weight-itens[index].first>=0){
            value+=itens[index].second;
            weight-=itens[index].first;
        }
        else{
            value+=(double)weight/(itens[index].first)*itens[index].second;     
            weight=0;
        }
        i++;
    }

    cout<<fixed<<setprecision(2)<<value<<endl;    
    return 0;
}