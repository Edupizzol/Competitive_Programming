#include <bits/stdc++.h>
using namespace std;

vector<char> letras;
bool usado[8] = {};
string atual = "";
vector<string> resultados;

void resolve(){
    if (atual.size() == letras.size()){
        resultados.push_back(atual);
        return;
    }
    for (int i = 0; i < (int)letras.size(); i++){
        if (usado[i]) continue;
        if (i > 0 && letras[i] == letras[i-1] && !usado[i-1]) continue;

        usado[i] = true;
        atual += letras[i];
        resolve();
        atual.pop_back();
        usado[i] = false;
    }
}

int main(){
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    for (char c : s) letras.push_back(c);

    resolve();

    cout << resultados.size() << "\n";
    for (const string &r : resultados) cout << r << "\n";
}