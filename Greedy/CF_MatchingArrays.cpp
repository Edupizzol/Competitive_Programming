#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int n,x;
        cin>>n>>x;

        vector<long long> a(n);
        multiset<long long> ms;
        bool isPossible=true;
        vector<long long> ans;
        for(long long &x:a) cin>>x; 
        for(int j=0;j<n;j++){long long num; cin>>num; ms.insert(num);}

        for(int j=0;j<n;j++){
            if(x>0){
                auto postIt = ms.lower_bound(a[j]);
                if(postIt==ms.begin()){
                    auto num = ms.lower_bound(a[j]);
                    if(num!=ms.end()){ans.push_back(*num);ms.erase(num);}
                    else{isPossible=false; break;}
                }
                else{
                    auto it = std::prev(postIt);
                    ans.push_back(*it);
                    ms.erase(it);
                    x--;
                }
            }
            else{
                auto num = ms.lower_bound(a[j]);
                if(num!=ms.end()){ans.push_back(*num);ms.erase(num);}
                else{isPossible=false; break;}
            }
        }
        if(x>0) isPossible=false;

        cout<<i+1<<endl;
        (isPossible) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
        if(isPossible) for(long long &x:ans) cout<<x<<" "; 
        cout<<endl; cout<<endl;
    }


    return 0;
}