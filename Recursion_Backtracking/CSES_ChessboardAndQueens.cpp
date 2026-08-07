#include <bits/stdc++.h>
using namespace std;

vector<string> tabuleiro(8);
int columnOfTheLine[8];
long long cont=0;

bool posicaoValida(int line, int column){
    if(tabuleiro[line][column]=='*') return false;

    for(int i=0;i<line;i++){
        if(columnOfTheLine[i]==column) return false;
        if(abs(line-i)==abs(column-columnOfTheLine[i])) return false;
    }
    return true;
}

void resolve(int line){
    if(line==8){cont++; return;}

    for(int j=0;j<8;j++){
        if(posicaoValida(line,j)){
            columnOfTheLine[line]=j;
            resolve(line+1);
        }
    }
}

int main(){
    for(int i=0;i<8;i++) cin>>tabuleiro[i];
    resolve(0);
    cout<<cont<<endl;
}