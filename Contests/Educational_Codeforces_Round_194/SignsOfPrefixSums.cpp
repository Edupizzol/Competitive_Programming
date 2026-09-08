#include <bits/stdc++.h>
using namespace std;

int biggest_abs(vector<int> &v){
    

    int num=0;
    for(int i=0;i<v.size();i++){
        if(v[i]<0) v[i]*=-1;
        if(v[i]>num) num=v[i];
    }
    return num;

}

int main(){

    int t;
    cin>>t;

    for(int j=0;j<t;j++){

        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> ans;
        if(s[0]=='0'){cout<<-1<<endl; continue;} 
        else if(s[0]=='+') ans.push_back(1);
        else ans.push_back(-1);
        long long sum=ans[0];

        for(int i=1;i<n;i++){
            if(s[i]=='+'){

                if(sum<=1 && sum>=0) ans.push_back(1);
                else if(sum>=2) ans.push_back(-1);
                else{
                    ans.push_back(abs(sum)+1);
                }

            }
            else if(s[i]=='-'){

                if(sum>=-1 && sum<=0) ans.push_back(-1);
                else if(sum<=-2) ans.push_back(1);
                else{
                    ans.push_back((sum+1)*-1);
                }

            }
            else if(s[i]=='0'){

                if(sum==0){
                    cout<<-1<<endl;
                    continue;
                }
                else if(sum>0){
                    ans.push_back(sum*-1);
                }
                else{
                    ans.push_back(sum);
                }

            }
            sum+=ans[i];
        }

        cout<<biggest_abs(ans)<<endl;

    }

    return 0;
}