#include <bits/stdc++.h>
using namespace std;

const int INF = (int) 1e9;

int l, c, p, preto[8][8], dp[8][(1 << 8)];

int main() {
    cin >> l >> c >> p;

    for (int i = 0; i < p; i++) {
        int x, y; cin >> x >> y; x--, y--;
        preto[x][y] = 1;
    }

    for (int i = 0; i < l; i++) {
        for (int mask = 0; mask < (1 << c); mask++) {
            dp[i][mask] = 0;
            bool maskValida = true;

            for (int j = 0; j < c; j++) {
                if ((mask & (1 << j)) && (preto[i][j])) {
                    maskValida = false;
                    continue;
                }

                if ((j > 0) && (mask & (1 << j)) && (mask & (1 << (j - 1)))) {
                    maskValida = false;
                    continue;
                }

                bool jValido = false;

                if ((i - 1 >= 0) && (preto[i - 1][j])) jValido = true;
                if ((i + 1 < l) && (preto[i + 1][j])) jValido = true;
                if ((j - 1 >= 0) && (preto[i][j - 1])) jValido = true;
                if ((j + 1 < c) && (preto[i][j + 1])) jValido = true;

                if ((!jValido) && (mask & (1 << j))) maskValida = false;
            }

            if (!maskValida) continue;

            int qtdBranco = __builtin_popcount(mask);

            if (i == 0) {
                dp[i][mask] = qtdBranco;
                continue;
            }

            for (int mask1 = 0; mask1 < (1 << c); mask1++) {
                bool validoMask1 = true;
                for (int j = 0; j < c; j++) {
                    if ((mask1 & (1 << j)) && (mask & (1 << j))) {
                        validoMask1 = false;
                    }
                }

                if (validoMask1) dp[i][mask] = max(dp[i][mask], dp[i - 1][mask1] + qtdBranco);
            }
        }
    }

    int ans = 0;

    for (int mask = 0; mask < (1 << c); mask++) {
        ans = max(ans, dp[l - 1][mask]);
    }

    cout << ans << "\n";
}