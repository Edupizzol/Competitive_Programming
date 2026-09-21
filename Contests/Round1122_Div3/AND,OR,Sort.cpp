#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        string nums;
        cin>>nums;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            if(nums[i]=='1') v[i]=1;
            else v[i]=0;
        }
        long long count=0;

        if(v[0]==1){
            for(int i=1;i<n;i++) if(v[i]==0) count++;
            cout<<count<<endl;
            continue;
        }

        int start=-1;
        long long count1 = 0;

        for(int i=0;i<n;i++){
            if(v[i]==1){
                start=i;
                break;
            }
        }

        if(start == -1){
            cout << 0 << endl;
            continue;
        }

        long long count0 = 0;
        for(int i = start; i < n; i++){
            if(v[i] == 0) count0++;
        }

        count1=0;
        long long min_ops = count0; 

        for(int i=start;i<n;i++){
            if(v[i]==1) count1++;
            else count0--;
            if(count1+count0<min_ops){
                min_ops=count1+count0;
            }
        }

        cout<<min_ops<<endl;
    }
}

