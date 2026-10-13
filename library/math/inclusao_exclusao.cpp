// exemplo da questao Quase Primo

#include <bits/stdc++.h>
using namespace std;

const int MAXK = 40;

int n, k, soma, primo[MAXK];

void f(int i, int mult, int qnt) { //indice atual, valor atual e quantidade de fatores
    if (mult > n) return; // se passou de n, retorna

    if (i == k) { // chegou no final da array
        if ((mult == 1) || (qnt == 0)) return;
        if (qnt & 1) soma += (n / mult);
        else soma -= (n / mult);
        return;
    }

    f(i + 1, mult, qnt); // sem acrescentar o primo i
    f(i + 1, mult * primo[i], qnt + 1); // acrescentando o primo i
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) cin >> primo[i];

    f(0, 1, 0);
    cout << (n - soma) << "\n";
}