#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int counter=0;
        int n;
        cin>>n;

        vector<int> ans;
        unordered_set<int> numbers;

        for(int i=0;i<n;i++){
            int pos=i+1;
            for(int j=1;j<=n;j++){
                if(pos & 1){
                    if(j & 1) continue;
                    else if(!(j & 1) && !numbers.contains(j)){ans.push_back(j);numbers.insert(j);break;}
                } 
                else{
                    if((j & 1) && !numbers.contains(j)){ans.push_back(j);numbers.insert(j);break;} 
                    else continue;
                }
            }
        }   


        for(int &x:ans) cout<<x<<" ";
        cout<<endl;
    }

    return 0;
}