# Competitive Programming

Repositório de treino para competitive programming, organizado por tópico. Faz parte de uma jornada com o objetivo de alcançar um rating decente no [Codeforces](https://codeforces.com/) até o final de 2026.

## Estrutura

Cada pasta representa um tópico do plano de estudo, seguindo aproximadamente a ordem em que eles costumam aparecer no Codeforces por rating:

```
.
├── simulation/              # Implementação e simulação básica
├── Sort_And_Searching/      # Ordenação e busca binária
├── TwoPointers/             # Two pointers e prefix sums
├── Greedy/                  # Algoritmos gulosos
├── Recursion_Backtracking/  # Recursão e backtracking
├── DataStructures/          # Pilha, fila, deque, heap
└── templates/               # Templates reutilizáveis (BFS, grafos, etc.)
```

Cada arquivo `.cpp` corresponde a um problema resolvido, geralmente do [CSES Problem Set](https://cses.fi/problemset/) ou do [Codeforces](https://codeforces.com/problemset). Os nomes dos arquivos seguem o padrão `Fonte_NomeDoProblema.cpp` (por exemplo, `CSES_ArrayDivision.cpp`, `CF_ColorTheFence.cpp`).

## Progresso

- [x] Implementação / simulação
- [x] Busca binária
- [x] Two pointers e prefix sums
- [x] Greedy
- [x] Recursão e backtracking
- [ ] Estruturas de dados (pilha, fila, deque, heap)
- [ ] Grafos (BFS/DFS aprofundado, caminhos mínimos, DSU, árvores)
- [ ] Programação dinâmica
- [ ] Matemática e número teoria
- [ ] Tópicos avançados (segment tree, grafos avançados, strings, geometria)

## Como compilar e rodar

Cada solução é um arquivo `.cpp` autocontido:

```bash
g++ -O2 -o solucao caminho/para/o/arquivo.cpp
./solucao < input.txt
```

## Metodologia

- Cada problema é resolvido do zero, sem olhar solução pronta antes de tentar sozinho.
- Soluções passam por **stress testing** contra força bruta sempre que possível, antes de considerar o problema fechado.
- Participação semanal em contests (ao vivo ou virtual) para calibrar progresso além da teoria.

## Ferramentas

- Compilador: g++ (C++17/20)
- Ambiente principal: Arch Linux