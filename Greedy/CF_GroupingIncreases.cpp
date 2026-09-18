#include <bits/stdc++.h>
using namespace std;

long long calculatePenalty(vector<long long> &p){
    long long count=0;
    for(int i=1;i<p.size();i++) if(p[i]>p[i-1]) count++;
    return count;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<long long> v(n);
        for(long long &x:v) cin>>x;

        vector<long long> p1, p2;
        const long long INF = 2e9;
        long long a = INF, b = INF;

        for(int j=0;j<n;j++){  // <- começa em 0
            if(v[j]>a && v[j]>b) {
                if(a<b) { p1.push_back(v[j]); a=v[j]; }
                else    { p2.push_back(v[j]); b=v[j]; }
            }
            else if(v[j]<=a && v[j]<=b) {
                if(a<b) { p1.push_back(v[j]); a=v[j]; }
                else    { p2.push_back(v[j]); b=v[j]; }
            }
            else if(v[j]<=a && v[j]>b) { p1.push_back(v[j]); a=v[j]; }
            else { p2.push_back(v[j]); b=v[j]; }
        }

        cout << calculatePenalty(p1)+calculatePenalty(p2) << endl;
    }
    return 0;
}