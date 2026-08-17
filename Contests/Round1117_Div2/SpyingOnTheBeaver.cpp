#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int n;
        cin>>n;

        vector<vector<int>> children(n+1);
        unordered_map<int,int> fathermap;
        for(int j=2;j<=n;j++){
            int father;
            cin>>father;
            children[father].push_back(j);
            fathermap[j] = father;
        }
    
        int m;
        cin>>m;
        unordered_map<int,bool> marks;
        for(int j=1;j<=m;j++){
            int num;
            cin>>num;
            marks[num]=true;
        }

        if(m==1){
            cout<<0<<endl;
            continue;
        }

        vector<int> answers;
        int cont=0;
        for(int j=1;j<=n;j++){
        
            bool skip=false;
            for(int k=0;k<children[j].size();k++){
                if(marks[children[j][k]]) skip=true;
            }

            if(skip) continue;
            int tempFather = fathermap[j];
            if(marks[j]){
                if(marks[tempFather]){
                    cont++;
                    answers.push_back(j);
                    marks[tempFather]=false;
                }
                else{
                    cont++;
                    answers.push_back(j);
                }
                marks[j]=false;
            }
        }

        cout<<cont<<" ";
        for(int j=0;j<answers.size();j++) cout<<answers[j]<<" ";
        cout<<endl;
    }

}