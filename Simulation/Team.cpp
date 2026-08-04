#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,num,a,b,c,count=0;
    cin>>n;

    vector<int> v(3);
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        if  (a==1 && b==1) count++;
        else if(a==1 && c==1) count++;
        else if(b==1 && c==1) count++;
    }

    cout<<count<<endl;

}
