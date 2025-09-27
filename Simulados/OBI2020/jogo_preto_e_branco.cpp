#include <bits/stdc++.h>
using namespace std;

int N, M, P, ans, conf[8];
bool pretas[8][8], ok[8][8];

void search(int linha) {
    if (linha == N + 1) {
        int soma = 0;
        for (int i = 1; i <= N; i++) soma += __builtin_popcount(conf[i]);
        ans = max(ans, soma);
        return;
    }

    for (int mask = 0; mask < (1 << M); mask++) {
        bool safe = 1;
        for (int i = 0; i < M; i++) {
            if (!(mask & (1 << i))) continue;
            if (!ok[linha][i + 1]) {
                safe = 0;
                break;
            }
            if (conf[linha - 1] & (1 << i)) {
                safe = 0;
                break;
            }
            if ((i > 0) && (mask & (1 << (i - 1)))) {
                safe = 0;
                break;
            }
        }
        if (!safe) continue;
        conf[linha] = mask;
        search(linha + 1);
    }
}

int main() {
    cin >> N >> M >> P;
    for (int i = 0; i < P; i++) {
        int x, y; cin >> x >> y;
        pretas[x][y] = 1;
        ok[x][y + 1] = 1;
        ok[x][y - 1] = 1;
        ok[x + 1][y] = 1;
        ok[x - 1][y] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (pretas[i][j]) ok[i][j] = 0;
        }
    }

    search(1);
    cout << ans << "\n";
}