#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int n,k,m;
        cin>>n>>k>>m;
        vector<pair<bool,int>> v(k, {false,0});
        long long cont=0;
        for(int j=0;j<m;j++){
            char c;
            cin>>c;
            v[c-97].first=true; v[c-97].second++;
            bool raiseCount=true;
            for(int q=0;q<k;q++){
                if(!v[q].first) raiseCount=false;
            }
            if(raiseCount){
                cont++;
                for(int q=0;q<k;q++) v[q].first=false;
            }
        }

        cout << ((cont>=n) ? "YES" : "NO") << endl;
    }

    return 0;
}