#include <bits/stdc++.h>
using namespace std;

struct camiseta {
    string nome, cor, tamanho;
};

camiseta arr[61];

bool cmp(camiseta a, camiseta b) {
    if (a.cor == b.cor) {
        if (a.tamanho == b.tamanho) {
            return a.nome < b.nome;
        } else {
            return a.tamanho > b.tamanho;
        }
    } else {
        return a.cor < b.cor;
    }
}

int main() {
    int N;
    cin >> N;
    bool lesgo = false;
    while (N != 0) {
        cin.ignore();
        for (int i = 0; i < N; i++) {
            getline(cin, arr[i].nome);
            cin >> arr[i].cor >> arr[i].tamanho; cin.ignore();
        }
        sort(arr, arr+N, cmp);
        if (lesgo) cout << "\n";
        else lesgo = true;
        for (int i = 0; i < N; i++) {
            cout << arr[i].cor << " " << arr[i].tamanho << " " << arr[i].nome << "\n";
        }
        scanf("%d", &N);
    }
}