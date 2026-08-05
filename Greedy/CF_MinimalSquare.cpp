#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    for(int i=0;i<n;i++){

        int a,b;
        cin>>a>>b;

        int minimum = min(a,b);
        int maximum = max(a,b);
        if(minimum+minimum<maximum) cout<<maximum*maximum<<endl;
        else cout<<((minimum+minimum)*(minimum+minimum))<<endl;

    }

    return 0;

}