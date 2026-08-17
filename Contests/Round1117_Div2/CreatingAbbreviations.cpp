#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;

        unordered_set<char> words;

        for(int j=0;j<a;j++){
            string s;
            cin>>s;
            words.insert(s[0]-32);
        }

        bool isPossible=true;
        for(int j=0;j<b;j++){
            string abbreviation;
            cin>>abbreviation;
            for(char c:abbreviation){
                if(words.count(c)<=0) isPossible=false;
            }
        }

        if(isPossible) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}