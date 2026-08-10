// ============================================================
// * TEMPLATE DE ESTRUTURAS DE DADOS DA STL (C++)
// * Referência rápida: operações + quando usar cada uma
// ============================================================

#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------
// * STACK (pilha) — LIFO: último a entrar, primeiro a sair
// ------------------------------------------------------------
// ? QUANDO USAR: balanceamento de parênteses/tags, desfazer última
// ? ação, DFS iterativo, qualquer problema onde "o mais recente
// ? não fechado/processado" precisa ser acessado primeiro.
void exemploStack(){
    stack<int> st;

    st.push(5);        // insere no topo
    st.push(8);

    int topo = st.top();  // olha o topo SEM remover
    st.pop();               // remove o topo (NÃO retorna valor!)

    bool vazio = st.empty();  // true se não tem nada
    int qtd = st.size();        // quantidade de elementos

    // ! PEGADINHA: nunca chame .top() ou .pop() sem checar .empty()
    // ! antes — pilha vazia é acesso inválido (undefined behavior).
}

// ------------------------------------------------------------
// * QUEUE (fila) — FIFO: primeiro a entrar, primeiro a sair
// ------------------------------------------------------------
// ? QUANDO USAR: BFS, simulação de fila real (atendimento, Josephus),
// ? qualquer problema onde a ORDEM DE CHEGADA precisa ser preservada
// ? e você só mexe nas duas "portas" (entra no fim, sai da frente).
void exemploQueue(){
    queue<int> q;

    q.push(5);         // insere no FIM
    q.push(8);

    int frente = q.front();  // olha a frente sem remover
    int fim = q.back();        // olha o fim sem remover
    q.pop();                     // remove da FRENTE (não retorna valor!)

    bool vazio = q.empty();
    int qtd = q.size();

    // ! NÃO tem push_front nem pop_back — só as portas "certas".
    // ! Se precisar mexer nas duas pontas livremente, use deque.
}

// ------------------------------------------------------------
// * DEQUE — fila de duas pontas, tudo O(1) nos dois lados
// ------------------------------------------------------------
// ? QUANDO USAR: sliding window (máximo/mínimo de janela deslizante
// ? com deque monotônico), quando precisa inserir/remover tanto na
// ? frente quanto no fim com frequência.
void exemploDeque(){
    deque<int> dq;

    dq.push_back(5);      // insere no fim
    dq.push_front(3);       // insere no início

    int frente = dq.front();
    int fim = dq.back();

    dq.pop_back();             // remove do fim
    dq.pop_front();               // remove do início

    // Também suporta acesso por índice, igual vector:
    // dq[0], dq[dq.size()-1]

    // * TÉCNICA DO DEQUE MONOTÔNICO (sliding window max):
    // * - mantém os valores em ordem decrescente (pro máximo)
    // * - ao inserir um novo elemento, remove do FIM tudo que for
    // *   MENOR OU IGUAL a ele (nunca mais serão úteis)
    // * - remove da FRENTE quando o índice de lá já saiu da janela
    // * - a resposta é sempre dq.front()
}

// ------------------------------------------------------------
// * PRIORITY_QUEUE (heap) — sempre entrega o MAIOR (ou MENOR) primeiro
// ------------------------------------------------------------
// ? QUANDO USAR: "sempre pegue o maior/menor disponível, repetidamente,
// ? numa coleção que muda ao longo do tempo" — ex: Dijkstra, custo
// ? mínimo pra combinar elementos (Huffman-like), top-K elementos.
void exemploPriorityQueue(){
    priority_queue<int> maxHeap;                                     // MAIOR primeiro (padrão)
    priority_queue<int, vector<int>, greater<int>> minHeap;             // MENOR primeiro

    maxHeap.push(5);
    maxHeap.push(10);
    maxHeap.push(3);

    int topo = maxHeap.top();  // olha o maior (ou menor, se for minHeap)
    maxHeap.pop();                // remove o topo (não retorna valor!)

    bool vazio = maxHeap.empty();
    int qtd = maxHeap.size();

    // Pode inicializar já com todos os elementos de um vector, O(n):
    vector<int> v = {5, 2, 8, 1};
    priority_queue<int, vector<int>, greater<int>> minHeap2(v.begin(), v.end());
}

// ------------------------------------------------------------
// * SET / MULTISET — mantém SEMPRE ordenado, busca/remoção O(log n)
// ------------------------------------------------------------
// ? QUANDO USAR: precisa manter dados ordenados E buscar/remover em
// ? qualquer posição repetidamente (não só nas pontas). set = sem
// ? duplicata; multiset = permite valores repetidos.
void exemploSet(){
    multiset<int> ms;

    ms.insert(5);         // insere (mantendo ordem)
    ms.insert(3);
    ms.insert(5);            // multiset aceita duplicata; set ignoraria

    ms.erase(ms.find(5));       // remove APENAS UMA ocorrência (via iterator)
    // ms.erase(5);              // ! CUIDADO: isso remove TODAS as ocorrências de 5!

    auto it = ms.lower_bound(4);  // primeiro elemento >= 4
    auto it2 = ms.upper_bound(4);   // primeiro elemento > 4

    bool existe = ms.count(3) > 0;

    // set<int> é igual, só não aceita duplicata.
    // unordered_set<int> é mais rápido (O(1) médio) mas SEM ordem
    // — use quando só precisa saber "existe ou não", sem se importar
    // com ordem nem com lower_bound/upper_bound.
}

// ------------------------------------------------------------
// * RESUMO — qual estrutura escolher
// ------------------------------------------------------------
// * Só extremo (maior/menor) repetidamente               -> priority_queue
// * Acesso rápido por chave, sem ordem                    -> unordered_map/set
// * Ordem preservada + busca/remoção em qualquer posição   -> set/multiset
// * Só as duas pontas (entra fim, sai frente)              -> queue
// * Só o topo (entra/sai do mesmo lado)                    -> stack
// * As duas pontas livres, O(1) nos dois lados              -> deque

int main(){
    return 0;
}