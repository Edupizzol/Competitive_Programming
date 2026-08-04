#include <bits/stdc++.h>
using namespace std;

int main(){

    string word;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>word;
        if(word.size()>10) cout<<word[0]<<word.size()-2<<word[word.size()-1]<<endl;
        else cout<<word<<endl;
    }

}