#include <bits/stdc++.h>
using namespace std;

bool isCorrect(string s){
    stack<char> pilha;

    for(char c:s){
        if(c=='(' || c=='[' || c=='{') pilha.push(c);
        else{
            if(pilha.empty()) return false;
            char topo=pilha.top();
            if(topo=='(' && c==')' || topo=='[' && c==']' || topo=='{' && c=='}') pilha.pop();
            else return false; 
        }
    }

    return pilha.empty();
}

int main(){

    string s;
    cin>>s;
    if(isCorrect(s)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}