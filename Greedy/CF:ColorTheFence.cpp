#include <bits/stdc++.h>
using namespace std;

string greedy_eat_all_im_hungry_my_belly_yearns_for_numbers(const vector<long long> &vetor, int v){

    long long min_cost=vetor[0];
    int min_number;
    for(int i=0;i<vetor.size();i++){
        if(vetor[i]<=min_cost){
            min_cost=vetor[i];
            min_number=i+1;
        }
    }

    int digits=v/min_cost;
    int leftover=v%min_cost+min_cost; //aqui somei o min_cost pois na primeira vez ele ja vai tirar o digito e trocar comecando pelo 9, entao no fim das contas ele recebe o valor do q vai ser substituido de volta
    if(digits==0) return "-1";
    
    string s(digits, '0' + min_number);
    int position=0;

    for(int i=8;i>=0;i--){

        while(leftover>vetor[i]){
            s[position]='0'+i+1;
            position++;
            leftover=leftover+min_cost-vetor[i];
        }

    }

    return s;

}

int main(){
    
    int v;
    cin>>v;
    vector<long long> vetor(9);
    for(long long &x:vetor) cin>>x;

    cout<<greedy_eat_all_im_hungry_my_belly_yearns_for_numbers(vetor,v)<<endl;

}