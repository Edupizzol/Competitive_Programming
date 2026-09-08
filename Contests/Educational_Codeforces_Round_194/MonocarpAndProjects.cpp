#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        long long x, y, k;
        cin>>x>>y>>k;

        long long cont=0;
        for(int j=0;j<k;j++){
            if(x*2<=y){
                cont+=y%x;
                x++; y++; 
            }
            else{
                long long mod=y%x;
                cont+=(mod*(k-j));
                break;
            }
        }
        cout<<cont<<endl;
    }

    return 0;
}   