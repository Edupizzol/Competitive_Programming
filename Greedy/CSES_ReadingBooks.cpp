#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> v(n);
    for(long long &x:v) cin>>x;
    sort(v.begin(), v.end());

    int low=0, high=n-1;
    long long countKotivalo=0, countJustiina=v[high], time=0;
    while(low<=high){
        if(low==high){
            time+=v[low]*2;
            break;
        }
        if(countKotivalo+v[low]>countJustiina){
            time+=countJustiina*2;
            high--; countJustiina=v[high]; countKotivalo=0;
        }
        else{
            countKotivalo+=v[low];
            low++;
        }
    }

    cout<<time<<endl;
    return 0;
}