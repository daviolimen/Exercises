// versao com todas otimizacoes, explicacao detalhada no noic

#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100

int pai[MAXN], peso[MAXN], qtd[MAXN]; // pai comeca com pai[i] = i, peso pode comecar zerado, pois o importante sao as comparacoes e qtd comeca so com 1s

int find(int x) {
    if (pai[x] == x) return x; //se isso acontecer ele ja e o pai

    return pai[x] = find(pai[x]); // isso ajuda a evitar a recursao toda vez
}

// otimizacao com pesos, para maior simetria
// junto com o calculo do numero de elementos na arvore
void join(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (peso[x] > peso[y]) {
        pai[y] = x;
        qtd[x] += qtd[y];
    } else if (peso[x] < peso[y]) {
        pai[x] = y;
        qtd[y] += qtd[x];
    } else {
        pai[y] = x;
        peso[x]++;
        qtd[x] += qtd[y];
    }
}