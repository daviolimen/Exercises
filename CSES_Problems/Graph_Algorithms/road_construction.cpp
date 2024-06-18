#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;

int n, m, pai[MAXN], peso[MAXN], qtd[MAXN];

int find(int x) {
    if (pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}

void join(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (peso[x] > peso[y]) {
        pai[y] = x;
        qtd[x] += qtd[y];
    } else if (peso[y] > peso[x]) {
        pai[x] = y;
        qtd[y] += qtd[x];
    } else {
        pai[y] = x;
        qtd[x] += qtd[y];
        peso[x]++;
    }
}

int main() {
    for (int i = 0; i < MAXN; i++) {
        pai[i] = i;
        qtd[i] = 1;
    }
    cin >> n >> m;
    int comp = n, maxSize = 1;
    while (m--) {
        int a, b; cin >> a >> b;
        if (find(a) != find(b)) {
            comp--;
            join(a, b);
        }
        maxSize = max(maxSize, qtd[find(a)]);
        cout << comp << " " << maxSize << "\n";
    }
}