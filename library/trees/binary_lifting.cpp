#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001
#define MAXLOG 31

int n, q, prox[MAXLOG][MAXN]; // prox[i][j] = onde chegaremos apos andarmos 2^i passos a partir de j

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> prox[0][i];

    for (int i = 0; i < (MAXLOG - 1); i++) {
        for (int j = 1; j <= n; j++) {
            prox[i + 1][j] = prox[i][prox[i][j]]; // e o mesmo que andar 2^i + 2^i = 2^(i+1) passos
        }
    }

    int x, k;
    while (q--) {
        cin >> x >> k;
        for (int i = 0; i < MAXLOG; i++) {
            if (k & (1 << i)) x = prox[i][x];
        }
        cout << x << "\n";
    }
}