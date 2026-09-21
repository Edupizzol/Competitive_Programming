#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long long a,b,n;
        cin>>a>>b>>n;
        if(a>b) cout<<a+n-b<<endl;
        else if(a==b) cout<<n<<endl;
        else{
            long long diff = b-a;
            if(diff>abs(a+n-b)) cout<<diff<<endl;
            else cout<<abs(a+n-b)<<endl;
        }
    }
}